#include "graphics/Shader.hpp"
#include <iostream>

namespace VoxelMaker {

Shader::Shader()
    : programID(0)
    , uniformLocations()
    , compiled(false) {
}

Shader::~Shader() {
    // TODO: Limpar recursos quando GLAD estiver disponível
}

bool Shader::loadFromFiles(const std::string& vertexPath, const std::string& fragmentPath) {
    // TODO: Implementar quando GLAD estiver disponível
    std::cout << "Carregando shader de arquivos: " << vertexPath << ", " << fragmentPath << std::endl;
    compiled = true;
    return true;
}

bool Shader::compile(const std::string& vertexSource, const std::string& fragmentSource) {
    // TODO: Implementar quando GLAD estiver disponível
    std::cout << "Compilando shader (modo simplificado)" << std::endl;
    compiled = true;
    return true;
}

void Shader::use() {
    if (compiled) {
        // TODO: Implementar quando GLAD estiver disponível
        std::cout << "Usando shader" << std::endl;
    }
}

void Shader::unbind() {
    // TODO: Implementar quando GLAD estiver disponível
    std::cout << "Parando de usar shader" << std::endl;
}

void Shader::setFloat(const std::string& name, float value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setInt(const std::string& name, int value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setBool(const std::string& name, bool value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setVec2(const std::string& name, const glm::vec2& value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setVec4(const std::string& name, const glm::vec4& value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setMat3(const std::string& name, const glm::mat3& value) {
    // TODO: Implementar quando GLAD estiver disponível
}

void Shader::setMat4(const std::string& name, const glm::mat4& value) {
    // TODO: Implementar quando GLAD estiver disponível
}

int Shader::getUniformLocation(const std::string& name) {
    if (uniformLocations.find(name) != uniformLocations.end()) {
        return uniformLocations[name];
    }

    // TODO: Implementar quando GLAD estiver disponível
    int location = -1; // Placeholder
    uniformLocations[name] = location;
    return location;
}

unsigned int Shader::compileShader(const std::string& source, unsigned int type) {
    // TODO: Implementar quando GLAD estiver disponível
    return 0;
}

bool Shader::checkCompileErrors(unsigned int shader, const std::string& type) {
    // TODO: Implementar quando GLAD estiver disponível
    return true;
}

} // namespace VoxelMaker 