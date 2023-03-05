#include "explorer.h"
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>

using namespace godot;
using namespace hadron;

void Explorer::_bind_methods() {

}

auto Explorer::build() -> Node* {
    Ref<PackedScene> scene = ResourceLoader::get_singleton()->load("res://panels/explorer.tscn");
    return scene->instantiate();
}

auto Explorer::title() -> String {
    return "Explorer";
}

auto Explorer::icon() -> Ref<Texture2D> {
    return ResourceLoader::get_singleton()->load("res://icons/explorer.svg");
}