#pragma once

#include <godot_cpp/classes/h_box_container.hpp>

namespace hadron {
    class Workbench : public godot::HBoxContainer {
        GDCLASS(Workbench, godot::HBoxContainer)
    
    protected:
        static void _bind_methods();
    
    public:
        Workbench();
        ~Workbench();
    };
}