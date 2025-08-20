cmake_minimum_required(VERSION 3.16)
project(VoxelMaker VERSION 1.0.0 LANGUAGES CXX)

# Configurar padrão C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Opções de build
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_DOCS "Build documentation" OFF)

# Encontrar dependências
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Incluir diretórios
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Adicionar subdiretórios (isso criará VoxelMakerLib)
add_subdirectory(src)

# Configurar executável principal
add_executable(VoxelMaker 
    main.cpp
)

# Linkar bibliotecas
target_link_libraries(VoxelMaker 
    OpenGL::GL 
    glfw 
    VoxelMakerLib
)

# Configurar propriedades do executável
set_target_properties(VoxelMaker PROPERTIES
    OUTPUT_NAME "voxelmaker"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Instalação
install(TARGETS VoxelMaker
    RUNTIME DESTINATION bin
)

# Configurar testes se habilitado
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Configurar documentação se habilitado
if(BUILD_DOCS)
    add_subdirectory(docs)
endif() 