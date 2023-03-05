#include "panel.h"

#include <godot_cpp/classes/label.hpp>

using namespace hadron;
using namespace godot;

std::vector<Panel*> Panel::panels = {};

void Panel::activate(Node *target) {
    // remove existing children
    auto children = target->get_children();
    children.clear();

    // add title
    auto title_label = new Label();
    title_label->set_text(title());

    target->add_child(title_label);

    // add the rest of the stuff
    target->add_child(build());
}

void Panel::register_panel(Panel *p) {
    panels.push_back(p);
}