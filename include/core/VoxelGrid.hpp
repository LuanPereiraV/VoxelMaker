#pragma once

#include "Voxel.hpp"
#include <vector>
#include <unordered_map>
#include <memory>

namespace VoxelMaker {

// Função hash personalizada para glm::ivec3
struct Vec3Hash {
    std::size_t operator()(const glm::ivec3& v) const {
        std::size_t h1 = std::hash<int>{}(v.x);
        std::size_t h2 = std::hash<int>{}(v.y);
        std::size_t h3 = std::hash<int>{}(v.z);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

/**
 * @brief Gerencia um grid 3D de voxels
 */
class VoxelGrid {
public:
    /**
     * @brief Estrutura para armazenar dimensões do grid
     */
    struct Dimensions {
        int width, height, depth;
        
        Dimensions() : width(64), height(64), depth(64) {}
        Dimensions(int w, int h, int d) : width(w), height(h), depth(d) {}
        
        int getVolume() const { return width * height * depth; }
    };

private:
    Dimensions dimensions;
    std::unordered_map<glm::ivec3, std::shared_ptr<Voxel>, Vec3Hash> voxels;
    glm::ivec3 origin;  ///< Origem do grid no espaço mundial

public:
    /**
     * @brief Construtor padrão
     */
    VoxelGrid();

    /**
     * @brief Construtor com dimensões
     * @param dim Dimensões do grid
     */
    VoxelGrid(const Dimensions& dim);

    /**
     * @brief Construtor completo
     * @param dim Dimensões do grid
     * @param orig Origem do grid
     */
    VoxelGrid(const Dimensions& dim, const glm::ivec3& orig);

    /**
     * @brief Destrutor
     */
    ~VoxelGrid() = default;

    // Getters
    const Dimensions& getDimensions() const { return dimensions; }
    const glm::ivec3& getOrigin() const { return origin; }
    size_t getVoxelCount() const { return voxels.size(); }

    // Setters
    void setDimensions(const Dimensions& dim) { dimensions = dim; }
    void setOrigin(const glm::ivec3& orig) { origin = orig; }

    /**
     * @brief Adiciona um voxel ao grid
     * @param voxel Voxel a ser adicionado
     * @return true se foi adicionado com sucesso
     */
    bool addVoxel(const Voxel& voxel);

    /**
     * @brief Remove um voxel do grid
     * @param position Posição do voxel a ser removido
     * @return true se foi removido com sucesso
     */
    bool removeVoxel(const glm::ivec3& position);

    /**
     * @brief Obtém um voxel do grid
     * @param position Posição do voxel
     * @return Ponteiro para o voxel ou nullptr se não existir
     */
    std::shared_ptr<Voxel> getVoxel(const glm::ivec3& position) const;

    /**
     * @brief Verifica se existe um voxel na posição
     * @param position Posição a verificar
     * @return true se existe um voxel
     */
    bool hasVoxel(const glm::ivec3& position) const;

    /**
     * @brief Verifica se uma posição está dentro dos limites do grid
     * @param position Posição a verificar
     * @return true se está dentro dos limites
     */
    bool isWithinBounds(const glm::ivec3& position) const;

    /**
     * @brief Limpa todos os voxels do grid
     */
    void clear();

    /**
     * @brief Obtém todos os voxels ativos
     * @return Vector com todos os voxels
     */
    std::vector<std::shared_ptr<Voxel>> getAllVoxels() const;

    /**
     * @brief Obtém voxels em uma região específica
     * @param minPos Posição mínima da região
     * @param maxPos Posição máxima da região
     * @return Vector com os voxels na região
     */
    std::vector<std::shared_ptr<Voxel>> getVoxelsInRegion(
        const glm::ivec3& minPos, 
        const glm::ivec3& maxPos
    ) const;

    /**
     * @brief Redimensiona o grid
     * @param newDimensions Novas dimensões
     * @param preserveExisting Se deve preservar voxels existentes
     */
    void resize(const Dimensions& newDimensions, bool preserveExisting = true);

    /**
     * @brief Aplica uma transformação a todos os voxels
     * @param transform Matriz de transformação
     */
    void applyTransform(const glm::mat4& transform);
};

} // namespace VoxelMaker 