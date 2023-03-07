use eframe::{egui, egui::Ui};
use egui_extras::RetainedImage;

pub mod explorer;
pub mod search;

pub trait Panel : Sync {
    fn title(&self) -> String;
    fn icon(&self) -> RetainedImage;
    fn build(&mut self, ctx: &egui::Context, ui: &mut Ui);
}