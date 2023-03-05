#include "workbench.h"
#include "panel.h"
#include "explorer.h"

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/input_event.hpp>

using namespace godot;
using namespace hadron;

void Workbench::_bind_methods() {
    ClassDB::bind_method(D_METHOD("launch_panel"), &Workbench::launch_panel);
}

Workbench::Workbench() {
    Panel::register_panel(new Explorer());
}

void Workbench::_ready() {
    auto panels = Panel::get_panels();
    auto toolbox = find_child("Toolbox");
    for(Panel *panel : panels) {
        auto btn = new Button();
        btn->set_button_icon(panel->icon());
        btn->set_size(Vector2(32, 32));
        btn->set_text(panel->title());
        btn->connect("gui_input", Callable(this, "launch_panel"));
        toolbox->add_child(btn);
    }
}

void Workbench::launch_panel(InputEvent *ev) {
    auto text = ev->as_text();
    auto panels = Panel::get_panels();

    for(Panel *panel : panels) {
        if(panel->title() == text) {
            panel->activate(find_child("SidePanel"));
            break;
        }
    }
}

Workbench::~Workbench() {
    
}