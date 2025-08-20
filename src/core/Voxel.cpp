#include "core/Voxel.hpp"

namespace VoxelMaker {

Voxel::Voxel() 
    : position(0, 0, 0)
    , color()
    , material()
    , active(true) {
}

Voxel::Voxel(const glm::ivec3& pos)
    : position(pos)
    , color()
    , material()
    , active(true) {
}

Voxel::Voxel(const glm::ivec3& pos, const Color& col, const Material& mat)
    : position(pos)
    , color(col)
    , material(mat)
    , active(true) {
}

bool Voxel::operator==(const Voxel& other) const {
    return position == other.position && 
           color.r == other.color.r && 
           color.g == other.color.g && 
           color.b == other.color.b && 
           color.a == other.color.a &&
           material.name == other.material.name &&
           material.roughness == other.material.roughness &&
           material.metallic == other.material.metallic &&
           material.transparency == other.material.transparency &&
           active == other.active;
}

bool Voxel::operator!=(const Voxel& other) const {
    return !(*this == other);
}

} // namespace VoxelMaker 