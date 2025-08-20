# CMakeLists.txt para o diretório tools

set(TOOLS_SOURCES
    BrushTool.cpp
    SelectionTool.cpp
    TransformTool.cpp
)

# Criar biblioteca estática para tools
add_library(VoxelMakerTools STATIC ${TOOLS_SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerTools PROPERTIES
    OUTPUT_NAME "voxelmaker_tools"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerTools PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/tools
    ${CMAKE_SOURCE_DIR}/include/core
    ${CMAKE_SOURCE_DIR}/include/graphics
)

# Linkar com bibliotecas dependentes
target_link_libraries(VoxelMakerTools VoxelMakerCore VoxelMakerGraphics) 