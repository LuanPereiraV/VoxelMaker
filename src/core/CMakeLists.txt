# CMakeLists.txt para o diretório core

set(CORE_SOURCES
    Voxel.cpp
    VoxelGrid.cpp
    VoxelObject.cpp
)

# Criar biblioteca estática para core
add_library(VoxelMakerCore STATIC ${CORE_SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerCore PROPERTIES
    OUTPUT_NAME "voxelmaker_core"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerCore PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/core
) 