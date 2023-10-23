#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace engine {

    class window {

        public:

            window(int w, int h, std::string name);
            ~window();

            bool shouldClose() { return glfwWindowShouldClose(window1); };

            GLFWwindow *window1;

        private:

            void initWindow();
            const int width;
            const int height;

            std::string windowName;

    };
}