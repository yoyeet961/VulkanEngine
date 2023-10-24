#pragma once

#include "engine.hpp"
#include "engine_pipeline.hpp"
#include "engine_device.hpp"

namespace engine {
    class app {

        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

        private:
            window window2{WIDTH, HEIGHT, "Vulkan Engine"};
            EngineDevice engineDevice{window2};
            enginePipeline EnginePipeline{engineDevice, "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", enginePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
    };
}