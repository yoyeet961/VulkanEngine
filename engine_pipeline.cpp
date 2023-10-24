#include "engine_pipeline.hpp"

//std
#include <fstream>
#include <iostream>
#include <stdexcept>


/**
 * Reads the contents of a file and returns them as a vector of characters.
 *
 * @param filepath the path to the file to be read
 *
 * @return a vector of characters containing the contents of the file
 *
 * @throws std::runtime_error if the file cannot be opened
 */
namespace engine {
    enginePipeline::enginePipeline(EngineDevice &device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) : engineDevice{device} {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }
    std::vector<char> enginePipeline::readFile(const std::string& filepath) {
        std::ifstream file(filepath, std::ios::ate | std::ios::binary);

        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file " + filepath);
        }
        
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

void enginePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {
    auto vertCode = readFile(vertFilepath);
    auto fragCode = readFile(fragFilepath);

    std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
    std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
}

void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
    //enginePipeline pipeline{enginePipeline::engineDevice::device(), "shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv", enginePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};

    // void createShaderModule(const std::vector<char>&, VkShaderModule_T**, EngineDevice& engineDevice);
    if (vkCreateShaderModule(engineDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create shader module");
    }
}

PipelineConfigInfo enginePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
    PipelineConfigInfo configInfo{};

    return configInfo;
}

}