#pragma once

#include "panel.h"

namespace hadron {
    class Explorer : public Panel {
        GDCLASS(Explorer, Panel)

    protected:
        static void _bind_methods();
    public:
        godot::Image icon();
        godot::String title();
        void build();
    };
}