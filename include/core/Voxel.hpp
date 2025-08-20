#pragma once

#include <cstdint>
#include <string>
#include <glm/glm.hpp>

namespace VoxelMaker {

/**
 * @brief Representa um voxel (cubo) individual no espaço 3D
 */
class Voxel {
public:
    /**
     * @brief Estrutura para armazenar informações de cor RGBA
     */
    struct Color {
        uint8_t r, g, b, a;
        
        Color() : r(255), g(255), b(255), a(255) {}
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) 
            : r(r), g(g), b(b), a(a) {}
    };

    /**
     * @brief Estrutura para armazenar informações de material
     */
    struct Material {
        std::string name;
        float roughness;
        float metallic;
        float transparency;
        
        Material() : name("default"), roughness(0.5f), metallic(0.0f), transparency(0.0f) {}
    };

private:
    glm::ivec3 position;    ///< Posição do voxel no grid
    Color color;            ///< Cor do voxel
    Material material;      ///< Material do voxel
    bool active;            ///< Se o voxel está ativo/visível

public:
    /**
     * @brief Construtor padrão
     */
    Voxel();

    /**
     * @brief Construtor com posição
     * @param pos Posição do voxel
     */
    Voxel(const glm::ivec3& pos);

    /**
     * @brief Construtor completo
     * @param pos Posição do voxel
     * @param col Cor do voxel
     * @param mat Material do voxel
     */
    Voxel(const glm::ivec3& pos, const Color& col, const Material& mat = Material());

    // Getters
    const glm::ivec3& getPosition() const { return position; }
    const Color& getColor() const { return color; }
    const Material& getMaterial() const { return material; }
    bool isActive() const { return active; }

    // Setters
    void setPosition(const glm::ivec3& pos) { position = pos; }
    void setColor(const Color& col) { color = col; }
    void setMaterial(const Material& mat) { material = mat; }
    void setActive(bool act) { active = act; }

    /**
     * @brief Verifica se dois voxels são iguais
     * @param other Voxel para comparar
     * @return true se são iguais
     */
    bool operator==(const Voxel& other) const;

    /**
     * @brief Verifica se dois voxels são diferentes
     * @param other Voxel para comparar
     * @return true se são diferentes
     */
    bool operator!=(const Voxel& other) const;
};

} // namespace VoxelMaker 