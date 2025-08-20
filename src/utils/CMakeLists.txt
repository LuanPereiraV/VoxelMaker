# CMakeLists.txt para o diretório utils

set(UTILS_SOURCES
    Logger.cpp
    FileUtils.cpp
    MathUtils.cpp
)

# Criar biblioteca estática para utils
add_library(VoxelMakerUtils STATIC ${UTILS_SOURCES})

# Configurar propriedades da biblioteca
set_target_properties(VoxelMakerUtils PROPERTIES
    OUTPUT_NAME "voxelmaker_utils"
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# Incluir diretórios de headers
target_include_directories(VoxelMakerUtils PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/utils
) 