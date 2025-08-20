# Dependencies.cmake - Configuração de dependências externas

# Função para encontrar e configurar OpenGL
function(setup_opengl)
    find_package(OpenGL REQUIRED)
    if(NOT OpenGL_FOUND)
        message(FATAL_ERROR "OpenGL não encontrado")
    endif()
    
    # Configurar GLAD (OpenGL Loader)
    add_subdirectory(third_party/glad)
    
    message(STATUS "OpenGL configurado: ${OpenGL_VERSION}")
endfunction()

# Função para encontrar e configurar GLFW
function(setup_glfw)
    find_package(glfw3 REQUIRED)
    if(NOT glfw3_FOUND)
        message(FATAL_ERROR "GLFW3 não encontrado")
    endif()
    
    message(STATUS "GLFW3 configurado: ${glfw3_VERSION}")
endfunction()

# Função para encontrar e configurar GLM
function(setup_glm)
    find_package(glm REQUIRED)
    if(NOT glm_FOUND)
        message(FATAL_ERROR "GLM não encontrado")
    endif()
    
    message(STATUS "GLM configurado")
endfunction()

# Função para configurar Dear ImGui (opcional)
function(setup_imgui)
    option(USE_IMGUI "Usar Dear ImGui para interface" ON)
    
    if(USE_IMGUI)
        if(EXISTS "${CMAKE_SOURCE_DIR}/third_party/imgui")
            add_subdirectory(third_party/imgui)
            set(IMGUI_AVAILABLE TRUE)
            message(STATUS "Dear ImGui configurado")
        else()
            message(WARNING "Dear ImGui não encontrado em third_party/imgui")
            set(IMGUI_AVAILABLE FALSE)
        endif()
    else()
        set(IMGUI_AVAILABLE FALSE)
        message(STATUS "Dear ImGui desabilitado")
    endif()
endfunction()

# Função para configurar stb_image (opcional)
function(setup_stb_image)
    option(USE_STB_IMAGE "Usar stb_image para carregamento de imagens" ON)
    
    if(USE_STB_IMAGE)
        if(EXISTS "${CMAKE_SOURCE_DIR}/third_party/stb_image.h")
            set(STB_IMAGE_AVAILABLE TRUE)
            message(STATUS "stb_image configurado")
        else()
            message(WARNING "stb_image.h não encontrado em third_party/")
            set(STB_IMAGE_AVAILABLE FALSE)
        endif()
    else()
        set(STB_IMAGE_AVAILABLE FALSE)
        message(STATUS "stb_image desabilitado")
    endif()
endfunction()

# Função para configurar nlohmann/json (opcional)
function(setup_json)
    option(USE_JSON "Usar nlohmann/json para serialização" ON)
    
    if(USE_JSON)
        find_package(nlohmann_json QUIET)
        if(nlohmann_json_FOUND)
            set(JSON_AVAILABLE TRUE)
            message(STATUS "nlohmann/json configurado")
        else()
            message(WARNING "nlohmann/json não encontrado")
            set(JSON_AVAILABLE FALSE)
        endif()
    else()
        set(JSON_AVAILABLE FALSE)
        message(STATUS "nlohmann/json desabilitado")
    endif()
endfunction()

# Função para configurar testes (opcional)
function(setup_testing)
    option(BUILD_TESTS "Construir testes unitários" OFF)
    
    if(BUILD_TESTS)
        enable_testing()
        find_package(GTest QUIET)
        if(GTest_FOUND)
            set(TESTING_AVAILABLE TRUE)
            message(STATUS "Google Test configurado para testes")
        else()
            message(WARNING "Google Test não encontrado")
            set(TESTING_AVAILABLE FALSE)
        endif()
    else()
        set(TESTING_AVAILABLE FALSE)
        message(STATUS "Testes desabilitados")
    endif()
endfunction()

# Função principal para configurar todas as dependências
function(setup_dependencies)
    message(STATUS "Configurando dependências...")
    
    # Dependências obrigatórias
    setup_opengl()
    setup_glfw()
    setup_glm()
    
    # Dependências opcionais
    setup_imgui()
    setup_stb_image()
    setup_json()
    setup_testing()
    
    message(STATUS "Dependências configuradas")
endfunction()

# Configurar variáveis globais
set(VM_DEPENDENCIES_CONFIGURED FALSE)

# Chamar configuração de dependências
setup_dependencies()
set(VM_DEPENDENCIES_CONFIGURED TRUE) 