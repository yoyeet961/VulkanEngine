#include "first_class.hpp"

namespace engine {
    void app::run() {
        while (!window2.shouldClose()) {
            glfwPollEvents();
        }
    }
}