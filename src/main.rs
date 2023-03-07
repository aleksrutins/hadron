#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")] // hide console window on Windows in release

mod panels;

use eframe::{egui::{self, Id, Sense}, Theme, epaint::Vec2};
use panels::{Panel, explorer::Explorer, search::Search};

fn main() -> Result<(), eframe::Error> {
    // Log to stdout (if you run with `RUST_LOG=debug`).
    tracing_subscriber::fmt::init();

    let options = eframe::NativeOptions {
        initial_window_size: Some(egui::vec2(320.0, 240.0)),
        default_theme: Theme::Light,
        ..Default::default()
    };
    eframe::run_native(
        "My egui App",
        options,
        Box::new(|_cc| Box::new(MyApp::default())),
    )
}

struct MyApp {
    name: String,
    age: u32,
    panels: Vec<Box<dyn Panel>>,
    current_panel: usize
}

impl Default for MyApp {
    fn default() -> Self {
        Self {
            name: "Arthur".to_owned(),
            age: 42,
            panels: vec![
                Box::new(Explorer {}),
                Box::new(Search {})
            ],
            current_panel: 0
        }
    }
}

impl eframe::App for MyApp {
    fn update(&mut self, ctx: &egui::Context, _frame: &mut eframe::Frame) {
        egui::SidePanel::left(Id::new("toolbox_sidebar")).default_width(24.0).show(ctx, |ui| {
            ui.vertical(|ui| {
                for (idx, panel) in self.panels.iter().enumerate() {
                    if panel.icon().show_size(ui, Vec2::splat(24.0))
                        .interact(Sense::click())
                        .clicked() {
                        self.current_panel = idx;
                    }
                }
            });
        });
        egui::SidePanel::left(Id::new("toolbox_selected_item_view")).show(ctx, |ui| {
            ui.vertical(|ui| {
                let Some(panel) = self.panels.get_mut(self.current_panel) else {
                    ui.label("No panel selected");
                    return;
                };
                ui.heading(panel.title());
                panel.build(ctx, ui);
            });
        });
        egui::CentralPanel::default().show(ctx, |ui| {
            ui.heading("My egui Application");
            ui.horizontal(|ui| {
                let name_label = ui.label("Your name: ");
                ui.text_edit_singleline(&mut self.name)
                    .labelled_by(name_label.id);
            });
            ui.add(egui::Slider::new(&mut self.age, 0..=120).text("age"));
            if ui.button("Click each year").clicked() {
                self.age += 1;
            }
            ui.label(format!("Hello '{}', age {}", self.name, self.age));
        });
    }
}