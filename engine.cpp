#include "engine.hpp"

#include <stdexcept>

namespace engine {

    window::window(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
        initWindow();
    }

    window::~window() {
        glfwDestroyWindow(window1);
        glfwTerminate();
    }

    void window::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window1 = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
    }
    void window::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
        if (glfwCreateWindowSurface(instance, window1, nullptr, surface) != VK_SUCCESS) {
            throw std::runtime_error("Failed to create window surface");
        }
    }
}