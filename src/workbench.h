#pragma once

#include <godot_cpp/classes/h_box_container.hpp>
#include <godot_cpp/classes/button.hpp>

namespace hadron {
    class Workbench : public godot::HBoxContainer {
        GDCLASS(Workbench, godot::HBoxContainer)
    
    protected:
        static void _bind_methods();
    
    public:
        Workbench();
        void _ready();
        void launch_panel(godot::InputEvent *ev);
        ~Workbench();
    };
}