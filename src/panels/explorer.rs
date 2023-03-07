use egui_extras::RetainedImage;

use super::Panel;

pub struct Explorer;

impl Panel for Explorer {
    fn title(&self) -> String {
        "Explorer".into()
    }

    fn icon(&self) -> RetainedImage {
        RetainedImage::from_image_bytes("explorer.png", include_bytes!("explorer.png")).unwrap()
    }

    fn build(&mut self, _ctx: &eframe::egui::Context, ui: &mut eframe::egui::Ui) {
        ui.label("Explorer");
    }
}