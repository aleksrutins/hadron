use egui_extras::RetainedImage;

use super::Panel;

pub struct Search;

impl Panel for Search {
    fn title(&self) -> String {
        "Search".into()
    }

    fn icon(&self) -> RetainedImage {
        RetainedImage::from_image_bytes("search.png", include_bytes!("search.png")).unwrap()
    }

    fn build(&mut self, _ctx: &eframe::egui::Context, ui: &mut eframe::egui::Ui) {
        ui.label("Search");
    }
}