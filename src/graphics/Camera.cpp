#include "graphics/Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace VoxelMaker {

Camera::Camera()
    : position(0.0f, 0.0f, 5.0f)
    , target(0.0f, 0.0f, 0.0f)
    , up(0.0f, 1.0f, 0.0f)
    , fov(45.0f)
    , aspectRatio(16.0f / 9.0f)
    , nearPlane(0.1f)
    , farPlane(1000.0f)
    , orthoSize(10.0f)
    , projectionType(ProjectionType::PERSPECTIVE)
    , viewMatrixDirty(true)
    , projMatrixDirty(true) {
}

Camera::Camera(const glm::vec3& pos, const glm::vec3& tgt)
    : position(pos)
    , target(tgt)
    , up(0.0f, 1.0f, 0.0f)
    , fov(45.0f)
    , aspectRatio(16.0f / 9.0f)
    , nearPlane(0.1f)
    , farPlane(1000.0f)
    , orthoSize(10.0f)
    , projectionType(ProjectionType::PERSPECTIVE)
    , viewMatrixDirty(true)
    , projMatrixDirty(true) {
}

const glm::mat4& Camera::getViewMatrix() {
    if (viewMatrixDirty) {
        updateViewMatrix();
    }
    return viewMatrix;
}

const glm::mat4& Camera::getProjectionMatrix() {
    if (projMatrixDirty) {
        updateProjectionMatrix();
    }
    return projectionMatrix;
}

glm::mat4 Camera::getViewProjectionMatrix() {
    return getProjectionMatrix() * getViewMatrix();
}

void Camera::moveTo(const glm::vec3& newPos) {
    position = newPos;
    viewMatrixDirty = true;
}

void Camera::moveBy(const glm::vec3& offset) {
    position += offset;
    viewMatrixDirty = true;
}

void Camera::lookAt(const glm::vec3& newTarget) {
    target = newTarget;
    viewMatrixDirty = true;
}

void Camera::rotateAroundTarget(float yaw, float pitch) {
    // Calcular direção da câmera
    glm::vec3 direction = glm::normalize(target - position);
    
    // Aplicar rotações
    glm::mat4 yawRotation = glm::rotate(yaw, up);
    glm::mat4 pitchRotation = glm::rotate(pitch, glm::cross(direction, up));
    
    // Atualizar posição
    glm::vec4 newPosition = yawRotation * pitchRotation * glm::vec4(position - target, 1.0f);
    position = glm::vec3(newPosition) + target;
    
    viewMatrixDirty = true;
}

void Camera::zoom(float factor) {
    if (projectionType == ProjectionType::PERSPECTIVE) {
        fov = glm::clamp(fov - factor, 1.0f, 120.0f);
        projMatrixDirty = true;
    } else {
        orthoSize = glm::clamp(orthoSize - factor, 0.1f, 100.0f);
        projMatrixDirty = true;
    }
}

void Camera::reset() {
    position = glm::vec3(0.0f, 0.0f, 5.0f);
    target = glm::vec3(0.0f, 0.0f, 0.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    fov = 45.0f;
    aspectRatio = 16.0f / 9.0f;
    nearPlane = 0.1f;
    farPlane = 1000.0f;
    orthoSize = 10.0f;
    projectionType = ProjectionType::PERSPECTIVE;
    
    viewMatrixDirty = true;
    projMatrixDirty = true;
}

void Camera::updateViewMatrix() {
    viewMatrix = glm::lookAt(position, target, up);
    viewMatrixDirty = false;
}

void Camera::updateProjectionMatrix() {
    if (projectionType == ProjectionType::PERSPECTIVE) {
        projectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
    } else {
        float halfSize = orthoSize * 0.5f;
        float halfWidth = halfSize * aspectRatio;
        projectionMatrix = glm::ortho(-halfWidth, halfWidth, -halfSize, halfSize, nearPlane, farPlane);
    }
    projMatrixDirty = false;
}

} // namespace VoxelMaker 