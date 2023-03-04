#pragma once
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/core/defs.hpp>

namespace hadron {
    class Panel : public godot::Control {
    public:
        virtual godot::Image icon() = 0;
        virtual godot::String title() = 0;
        virtual void build() = 0;
    };
}