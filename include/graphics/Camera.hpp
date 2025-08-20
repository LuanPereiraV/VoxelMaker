#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace VoxelMaker {

/**
 * @brief Gerencia a câmera 3D
 */
class Camera {
public:
    /**
     * @brief Tipos de projeção
     */
    enum class ProjectionType {
        PERSPECTIVE,
        ORTHOGRAPHIC
    };

private:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;
    
    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;
    
    float orthoSize;
    ProjectionType projectionType;
    
    bool viewMatrixDirty;
    bool projMatrixDirty;
    
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

public:
    /**
     * @brief Construtor padrão
     */
    Camera();

    /**
     * @brief Construtor com posição e alvo
     * @param pos Posição da câmera
     * @param tgt Alvo da câmera
     */
    Camera(const glm::vec3& pos, const glm::vec3& tgt);

    /**
     * @brief Destrutor
     */
    ~Camera() = default;

    // Getters
    const glm::vec3& getPosition() const { return position; }
    const glm::vec3& getTarget() const { return target; }
    const glm::vec3& getUp() const { return up; }
    float getFOV() const { return fov; }
    float getAspectRatio() const { return aspectRatio; }
    float getNearPlane() const { return nearPlane; }
    float getFarPlane() const { return farPlane; }
    float getOrthoSize() const { return orthoSize; }
    ProjectionType getProjectionType() const { return projectionType; }

    // Setters
    void setPosition(const glm::vec3& pos) { position = pos; viewMatrixDirty = true; }
    void setTarget(const glm::vec3& tgt) { target = tgt; viewMatrixDirty = true; }
    void setUp(const glm::vec3& u) { up = u; viewMatrixDirty = true; }
    void setFOV(float f) { fov = f; projMatrixDirty = true; }
    void setAspectRatio(float ar) { aspectRatio = ar; projMatrixDirty = true; }
    void setNearPlane(float near) { nearPlane = near; projMatrixDirty = true; }
    void setFarPlane(float far) { farPlane = far; projMatrixDirty = true; }
    void setOrthoSize(float size) { orthoSize = size; projMatrixDirty = true; }
    void setProjectionType(ProjectionType type) { projectionType = type; projMatrixDirty = true; }

    /**
     * @brief Obtém a matriz de visualização
     * @return Matriz de visualização
     */
    const glm::mat4& getViewMatrix();

    /**
     * @brief Obtém a matriz de projeção
     * @return Matriz de projeção
     */
    const glm::mat4& getProjectionMatrix();

    /**
     * @brief Obtém a matriz de visualização-projeção
     * @return Matriz VP
     */
    glm::mat4 getViewProjectionMatrix();

    /**
     * @brief Move a câmera para uma nova posição
     * @param newPos Nova posição
     */
    void moveTo(const glm::vec3& newPos);

    /**
     * @brief Move a câmera por um offset
     * @param offset Offset de movimento
     */
    void moveBy(const glm::vec3& offset);

    /**
     * @brief Olha para um novo alvo
     * @param newTarget Novo alvo
     */
    void lookAt(const glm::vec3& newTarget);

    /**
     * @brief Rotaciona a câmera ao redor do alvo
     * @param yaw Rotação em Y (radianos)
     * @param pitch Rotação em X (radianos)
     */
    void rotateAroundTarget(float yaw, float pitch);

    /**
     * @brief Zoom in/out
     * @param factor Fator de zoom
     */
    void zoom(float factor);

    /**
     * @brief Reseta a câmera para posição padrão
     */
    void reset();

private:
    /**
     * @brief Atualiza a matriz de visualização
     */
    void updateViewMatrix();

    /**
     * @brief Atualiza a matriz de projeção
     */
    void updateProjectionMatrix();
};

} // namespace VoxelMaker 