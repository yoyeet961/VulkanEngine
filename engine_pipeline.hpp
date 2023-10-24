#pragma once

#include "engine_device.hpp"

// std
#include <string>
#include <vector>

namespace engine {

    struct PipelineConfigInfo {};
    class enginePipeline {
        public:
        enginePipeline(EngineDevice &device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
        ~enginePipeline() {}
        
        enginePipeline(const enginePipeline&) = delete;
        void operator=(const enginePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

        private:
        static std::vector<char> readFile(const std::string& filepath);

        void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
        EngineDevice& engineDevice;
    };
}