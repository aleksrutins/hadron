#pragma once
#include <vector>
#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/core/defs.hpp>

namespace hadron {
    using namespace godot;
    class Panel : public godot::Control {
        static std::vector<Panel*> panels;
    public:
        virtual auto icon() -> Ref<Texture2D> = 0;
        virtual auto title() -> String = 0;
        virtual auto build() -> Node* = 0;

        void activate(Node *target);

        static void register_panel(Panel *);

        static std::vector<Panel*> get_panels() {
            return panels;
        }
    };
}