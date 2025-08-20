# CMakeLists.txt para o diretório ui

set(UI_SOURCES
    Window.cpp
    UI.cpp
    Input.cpp
)

# Criar biblioteca estática para ui
add_library(VoxelMakerUI STATIC ${UI_SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerUI PROPERTIES
    OUTPUT_NAME "voxelmaker_ui"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerUI PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ui
    ${CMAKE_SOURCE_DIR}/include/core
)

# Linkar com bibliotecas dependentes
target_link_libraries(VoxelMakerUI VoxelMakerCore) 