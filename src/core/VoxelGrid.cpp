#include "core/VoxelGrid.hpp"
#include <algorithm>

namespace VoxelMaker {

VoxelGrid::VoxelGrid() 
    : dimensions()
    , voxels()
    , origin(0, 0, 0) {
}

VoxelGrid::VoxelGrid(const Dimensions& dim)
    : dimensions(dim)
    , voxels()
    , origin(0, 0, 0) {
}

VoxelGrid::VoxelGrid(const Dimensions& dim, const glm::ivec3& orig)
    : dimensions(dim)
    , voxels()
    , origin(orig) {
}

bool VoxelGrid::addVoxel(const Voxel& voxel) {
    if (!isWithinBounds(voxel.getPosition())) {
        return false;
    }
    
    auto voxelPtr = std::make_shared<Voxel>(voxel);
    voxels[voxel.getPosition()] = voxelPtr;
    return true;
}

bool VoxelGrid::removeVoxel(const glm::ivec3& position) {
    auto it = voxels.find(position);
    if (it != voxels.end()) {
        voxels.erase(it);
        return true;
    }
    return false;
}

std::shared_ptr<Voxel> VoxelGrid::getVoxel(const glm::ivec3& position) const {
    auto it = voxels.find(position);
    if (it != voxels.end()) {
        return it->second;
    }
    return nullptr;
}

bool VoxelGrid::hasVoxel(const glm::ivec3& position) const {
    return voxels.find(position) != voxels.end();
}

bool VoxelGrid::isWithinBounds(const glm::ivec3& position) const {
    return position.x >= 0 && position.x < dimensions.width &&
           position.y >= 0 && position.y < dimensions.height &&
           position.z >= 0 && position.z < dimensions.depth;
}

void VoxelGrid::clear() {
    voxels.clear();
}

std::vector<std::shared_ptr<Voxel>> VoxelGrid::getAllVoxels() const {
    std::vector<std::shared_ptr<Voxel>> result;
    result.reserve(voxels.size());
    
    for (const auto& pair : voxels) {
        if (pair.second->isActive()) {
            result.push_back(pair.second);
        }
    }
    
    return result;
}

std::vector<std::shared_ptr<Voxel>> VoxelGrid::getVoxelsInRegion(
    const glm::ivec3& minPos, 
    const glm::ivec3& maxPos
) const {
    std::vector<std::shared_ptr<Voxel>> result;
    
    for (const auto& pair : voxels) {
        const auto& pos = pair.first;
        if (pos.x >= minPos.x && pos.x <= maxPos.x &&
            pos.y >= minPos.y && pos.y <= maxPos.y &&
            pos.z >= minPos.z && pos.z <= maxPos.z &&
            pair.second->isActive()) {
            result.push_back(pair.second);
        }
    }
    
    return result;
}

void VoxelGrid::resize(const Dimensions& newDimensions, bool preserveExisting) {
    if (!preserveExisting) {
        clear();
    } else {
        // Remove voxels que estão fora dos novos limites
        auto it = voxels.begin();
        while (it != voxels.end()) {
            if (!isWithinBounds(it->first)) {
                it = voxels.erase(it);
            } else {
                ++it;
            }
        }
    }
    
    dimensions = newDimensions;
}

void VoxelGrid::applyTransform(const glm::mat4& transform) {
    // TODO: Implementar transformação de voxels
    // Esta é uma implementação simplificada
    // Em uma implementação completa, seria necessário:
    // 1. Converter posições para coordenadas homogêneas
    // 2. Aplicar a transformação
    // 3. Converter de volta para coordenadas inteiras
    // 4. Lidar com colisões e sobreposições
}

} // namespace VoxelMaker 