#include "engine_pipeline.hpp"


//std
#include <fstream>
#include <iostream>


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
    enginePipeline::enginePipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
        createGraphicsPipeline(vertFilepath, fragFilepath);
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

void enginePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
    auto vertCode = readFile(vertFilepath);
    auto fragCode = readFile(fragFilepath);

    std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
    std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
}
}