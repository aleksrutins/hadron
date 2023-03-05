#pragma once

#include "panel.h"

namespace hadron {
    class Explorer : public Panel {
        GDCLASS(Explorer, Panel)

    protected:
        static void _bind_methods();
    public:
        auto icon() -> Ref<Texture2D>;
        auto title() -> String;
        auto build() -> Node*;
    };
}