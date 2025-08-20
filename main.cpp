#include <iostream>
#include <memory>
#include <stdexcept>

// OpenGL e GLFW
#include <GLFW/glfw3.h>

// Incluir headers principais
#include "core/Voxel.hpp"
#include "core/VoxelGrid.hpp"
#include "graphics/Renderer.hpp"
#include "graphics/Camera.hpp"
#include "graphics/Shader.hpp"
#include "ui/Window.hpp"

using namespace VoxelMaker;

/**
 * @brief Classe principal da aplicação
 */
class VoxelMakerApp {
private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::shared_ptr<Camera> camera;
    std::unique_ptr<VoxelGrid> voxelGrid;
    
    bool running;

public:
    /**
     * @brief Construtor
     */
    VoxelMakerApp() : running(false) {}

    /**
     * @brief Destrutor
     */
    ~VoxelMakerApp() = default;

    /**
     * @brief Inicializa a aplicação
     * @return true se inicializada com sucesso
     */
    bool initialize() {
        try {
            std::cout << "Inicializando VoxelMaker..." << std::endl;

            // Criar janela
            Window::WindowSettings windowSettings;
            windowSettings.width = 1280;
            windowSettings.height = 720;
            windowSettings.title = "VoxelMaker - Editor de Voxels 3D";
            
            window = std::make_unique<Window>(windowSettings);
            if (!window->initialize()) {
                std::cerr << "Erro ao inicializar janela" << std::endl;
                return false;
            }

            // Criar câmera
            camera = std::make_shared<Camera>();
            camera->setPosition(glm::vec3(10.0f, 10.0f, 10.0f));
            camera->setTarget(glm::vec3(0.0f, 0.0f, 0.0f));
            camera->setFOV(45.0f);
            camera->setAspectRatio(1280.0f / 720.0f);

            // Criar grid de voxels
            VoxelGrid::Dimensions gridDim(32, 32, 32);
            voxelGrid = std::make_unique<VoxelGrid>(gridDim);

            // Criar renderer
            renderer = std::make_unique<Renderer>();
            if (!renderer->initialize()) {
                std::cerr << "Erro ao inicializar renderer" << std::endl;
                return false;
            }
            renderer->setCamera(camera);

            // Configurar callbacks da janela
            setupWindowCallbacks();

            std::cout << "VoxelMaker inicializado com sucesso!" << std::endl;
            return true;

        } catch (const std::exception& e) {
            std::cerr << "Erro durante inicialização: " << e.what() << std::endl;
            return false;
        }
    }

    /**
     * @brief Executa o loop principal da aplicação
     */
    void run() {
        if (!window || !renderer || !camera || !voxelGrid) {
            std::cerr << "Aplicação não inicializada corretamente" << std::endl;
            return;
        }

        running = true;
        std::cout << "Iniciando loop principal..." << std::endl;

        while (running && !window->shouldClose()) {
            // Processar eventos
            window->pollEvents();

            // Atualizar lógica da aplicação
            update();

            // Renderizar
            render();

            // Trocar buffers
            window->swapBuffers();
        }

        std::cout << "Loop principal finalizado" << std::endl;
    }

    /**
     * @brief Limpa recursos da aplicação
     */
    void cleanup() {
        std::cout << "Limpando recursos..." << std::endl;
        
        if (renderer) {
            renderer->cleanup();
        }
        
        if (window) {
            window->cleanup();
        }
        
        std::cout << "Recursos limpos" << std::endl;
    }

private:
    /**
     * @brief Configura os callbacks da janela
     */
    void setupWindowCallbacks() {
        if (!window) return;

        Window::EventCallbacks callbacks;
        
        callbacks.onResize = [this](int width, int height) {
            if (camera) {
                camera->setAspectRatio(static_cast<float>(width) / static_cast<float>(height));
            }
        };

        callbacks.onKey = [this](int key, int scancode, int action, int mods) {
            handleKeyInput(key, scancode, action, mods);
        };

        callbacks.onMouseMove = [this](int x, int y) {
            handleMouseMove(x, y);
        };

        callbacks.onMouseButton = [this](int button, int action, int mods) {
            handleMouseButton(button, action, mods);
        };

        callbacks.onScroll = [this](double xoffset, double yoffset) {
            handleScroll(xoffset, yoffset);
        };

        callbacks.onClose = [this]() {
            running = false;
        };

        window->setEventCallbacks(callbacks);
    }

    /**
     * @brief Atualiza a lógica da aplicação
     */
    void update() {
        // TODO: Implementar lógica de atualização
        // - Atualizar ferramentas
        // - Processar input
        // - Atualizar física (se necessário)
    }

    /**
     * @brief Renderiza a cena
     */
    void render() {
        if (!renderer || !voxelGrid) return;

        // TODO: Implementar limpeza de buffer quando GLAD estiver disponível
        // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        // Renderizar grid de voxels
        renderer->renderVoxelGrid(*voxelGrid);

        // Renderizar grid de referência
        renderer->renderGrid();

        // Renderizar eixos
        renderer->renderAxes();
    }

    /**
     * @brief Processa input de teclado
     */
    void handleKeyInput(int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            switch (key) {
                case GLFW_KEY_ESCAPE:
                    running = false;
                    break;
                case GLFW_KEY_R:
                    // Resetar câmera
                    if (camera) camera->reset();
                    break;
                case GLFW_KEY_SPACE:
                    // TODO: Alternar ferramenta
                    break;
                default:
                    break;
            }
        }
    }

    /**
     * @brief Processa movimento do mouse
     */
    void handleMouseMove(int x, int y) {
        // TODO: Implementar controle de câmera
    }

    /**
     * @brief Processa cliques do mouse
     */
    void handleMouseButton(int button, int action, int mods) {
        // TODO: Implementar interação com voxels
    }

    /**
     * @brief Processa scroll do mouse
     */
    void handleScroll(double xoffset, double yoffset) {
        if (camera) {
            camera->zoom(static_cast<float>(yoffset) * 0.1f);
        }
    }
};

/**
 * @brief Função principal
 */
int main() {
    std::cout << "=== VoxelMaker - Editor de Voxels 3D ===" << std::endl;
    std::cout << "Versão: 1.0.0" << std::endl;
    std::cout << "Desenvolvido em C++" << std::endl;
    std::cout << "========================================" << std::endl;

    VoxelMakerApp app;

    try {
        if (!app.initialize()) {
            std::cerr << "Falha ao inicializar aplicação" << std::endl;
            return -1;
        }

        app.run();

    } catch (const std::exception& e) {
        std::cerr << "Erro durante execução: " << e.what() << std::endl;
        return -1;
    }

    app.cleanup();

    std::cout << "VoxelMaker finalizado com sucesso!" << std::endl;
    return 0;
}
