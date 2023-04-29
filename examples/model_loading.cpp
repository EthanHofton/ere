#include <ere/core/entry_point.hpp>
#include "lighting/model_lighting.hpp"

namespace ere {

extern ref<application> ere_create_application(int argc, char** argv) {
    ref<application> app = application::get_application();

    app->push_layer(createRef<model_lighting>());

    app->set_background_color({0.f, 0.f, 0.f, 1.0f});
    app->set_fps(120.0);
    app->set_window_title("Ere Engine - model lighting");
    app->vsync(false);
    app->set_relative_mouse_mode(true);

    return app;
}

}