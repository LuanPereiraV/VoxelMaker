# CMakeLists.txt para o diretório src

# Adicionar subdiretórios
add_subdirectory(core)
add_subdirectory(graphics)
add_subdirectory(ui)
add_subdirectory(tools)
add_subdirectory(utils)

# Criar biblioteca estática com todo o código fonte
set(SOURCES
    core/Voxel.cpp
    core/VoxelGrid.cpp
    core/VoxelObject.cpp
    graphics/Renderer.cpp
    graphics/Camera.cpp
    graphics/Shader.cpp
    ui/Window.cpp
    ui/UI.cpp
    tools/BrushTool.cpp
    tools/SelectionTool.cpp
    tools/TransformTool.cpp
    utils/Logger.cpp
    utils/FileUtils.cpp
    utils/MathUtils.cpp
)

# Criar biblioteca estática
add_library(VoxelMakerLib STATIC ${SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerLib PROPERTIES
    OUTPUT_NAME "voxelmaker"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerLib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)

# Linkar dependências
target_link_libraries(VoxelMakerLib
    glfw
    OpenGL::GL
) 