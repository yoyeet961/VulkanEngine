#pragma once

#include "engine.hpp"

namespace engine {
    class app {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

        private:
            window window2{WIDTH, HEIGHT, "Vulkan Engine"};
    };
}