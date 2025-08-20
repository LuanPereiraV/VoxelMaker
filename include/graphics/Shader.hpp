#pragma once

#include <glm/glm.hpp>
#include <string>
#include <unordered_map>

namespace VoxelMaker {

/**
 * @brief Gerencia shaders OpenGL
 */
class Shader {
private:
    unsigned int programID;
    std::unordered_map<std::string, int> uniformLocations;
    bool compiled;

public:
    /**
     * @brief Construtor
     */
    Shader();

    /**
     * @brief Destrutor
     */
    ~Shader();

    /**
     * @brief Carrega e compila o shader
     * @param vertexPath Caminho para o vertex shader
     * @param fragmentPath Caminho para o fragment shader
     * @return true se compilado com sucesso
     */
    bool loadFromFiles(const std::string& vertexPath, const std::string& fragmentPath);

    /**
     * @brief Compila o shader a partir de strings
     * @param vertexSource Código fonte do vertex shader
     * @param fragmentSource Código fonte do fragment shader
     * @return true se compilado com sucesso
     */
    bool compile(const std::string& vertexSource, const std::string& fragmentSource);

    /**
     * @brief Usa o shader
     */
    void use();

    /**
     * @brief Para de usar o shader
     */
    void unbind();

    /**
     * @brief Define um uniform float
     * @param name Nome do uniform
     * @param value Valor
     */
    void setFloat(const std::string& name, float value);

    /**
     * @brief Define um uniform int
     * @param name Nome do uniform
     * @param value Valor
     */
    void setInt(const std::string& name, int value);

    /**
     * @brief Define um uniform bool
     * @param name Nome do uniform
     * @param value Valor
     */
    void setBool(const std::string& name, bool value);

    /**
     * @brief Define um uniform vec2
     * @param name Nome do uniform
     * @param value Valor
     */
    void setVec2(const std::string& name, const glm::vec2& value);

    /**
     * @brief Define um uniform vec3
     * @param name Nome do uniform
     * @param value Valor
     */
    void setVec3(const std::string& name, const glm::vec3& value);

    /**
     * @brief Define um uniform vec4
     * @param name Nome do uniform
     * @param value Valor
     */
    void setVec4(const std::string& name, const glm::vec4& value);

    /**
     * @brief Define um uniform mat3
     * @param name Nome do uniform
     * @param value Valor
     */
    void setMat3(const std::string& name, const glm::mat3& value);

    /**
     * @brief Define um uniform mat4
     * @param name Nome do uniform
     * @param value Valor
     */
    void setMat4(const std::string& name, const glm::mat4& value);

    /**
     * @brief Obtém o ID do programa
     * @return ID do programa
     */
    unsigned int getProgramID() const { return programID; }

    /**
     * @brief Verifica se o shader foi compilado
     * @return true se compilado
     */
    bool isCompiled() const { return compiled; }

private:
    /**
     * @brief Obtém a localização de um uniform
     * @param name Nome do uniform
     * @return Localização
     */
    int getUniformLocation(const std::string& name);

    /**
     * @brief Compila um shader individual
     * @param source Código fonte
     * @param type Tipo do shader
     * @return ID do shader
     */
    unsigned int compileShader(const std::string& source, unsigned int type);

    /**
     * @brief Verifica erros de compilação
     * @param shader ID do shader
     * @param type Tipo de verificação
     * @return true se não há erros
     */
    bool checkCompileErrors(unsigned int shader, const std::string& type);
};

} // namespace VoxelMaker 