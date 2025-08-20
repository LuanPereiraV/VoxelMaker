# CMakeLists.txt para o diretório graphics

set(GRAPHICS_SOURCES
    Renderer.cpp
    Camera.cpp
    Shader.cpp
    Mesh.cpp
)

# Criar biblioteca estática para graphics
add_library(VoxelMakerGraphics STATIC ${GRAPHICS_SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerGraphics PROPERTIES
    OUTPUT_NAME "voxelmaker_graphics"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerGraphics PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/graphics
    ${CMAKE_SOURCE_DIR}/include/core
)

# Linkar com biblioteca core
target_link_libraries(VoxelMakerGraphics VoxelMakerCore) 