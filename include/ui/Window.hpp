#pragma once

#include <string>
#include <functional>
#include <memory>

namespace VoxelMaker {

/**
 * @brief Gerencia a janela principal da aplicação
 */
class Window {
public:
    /**
     * @brief Configurações da janela
     */
    struct WindowSettings {
        int width;
        int height;
        std::string title;
        bool fullscreen;
        bool resizable;
        bool vsync;
        
        WindowSettings() 
            : width(1280)
            , height(720)
            , title("VoxelMaker")
            , fullscreen(false)
            , resizable(true)
            , vsync(true) {}
    };

    /**
     * @brief Callbacks de eventos
     */
    struct EventCallbacks {
        std::function<void(int, int)> onResize;
        std::function<void(int, int)> onMouseMove;
        std::function<void(int, int, int)> onMouseButton;
        std::function<void(double, double)> onScroll;
        std::function<void(int, int, int, int)> onKey;
        std::function<void()> onClose;
    };

private:
    WindowSettings settings;
    EventCallbacks callbacks;
    void* windowHandle;  // GLFWwindow* ou similar
    bool initialized;

public:
    /**
     * @brief Construtor
     */
    Window();

    /**
     * @brief Construtor com configurações
     * @param settings Configurações da janela
     */
    Window(const WindowSettings& settings);

    /**
     * @brief Destrutor
     */
    ~Window();

    /**
     * @brief Inicializa a janela
     * @return true se inicializada com sucesso
     */
    bool initialize();

    /**
     * @brief Limpa recursos da janela
     */
    void cleanup();

    /**
     * @brief Processa eventos da janela
     */
    void pollEvents();

    /**
     * @brief Troca os buffers da janela
     */
    void swapBuffers();

    /**
     * @brief Verifica se a janela deve ser fechada
     * @return true se deve ser fechada
     */
    bool shouldClose() const;

    /**
     * @brief Define as configurações da janela
     * @param settings Novas configurações
     */
    void setSettings(const WindowSettings& settings);

    /**
     * @brief Obtém as configurações da janela
     * @return Configurações atuais
     */
    const WindowSettings& getSettings() const { return settings; }

    /**
     * @brief Define os callbacks de eventos
     * @param callbacks Novos callbacks
     */
    void setEventCallbacks(const EventCallbacks& callbacks);

    /**
     * @brief Obtém o handle da janela
     * @return Handle da janela
     */
    void* getWindowHandle() const { return windowHandle; }

    /**
     * @brief Obtém as dimensões da janela
     * @return Par (largura, altura)
     */
    std::pair<int, int> getSize() const;

    /**
     * @brief Define o tamanho da janela
     * @param width Largura
     * @param height Altura
     */
    void setSize(int width, int height);

    /**
     * @brief Obtém a posição do cursor
     * @return Par (x, y) da posição do cursor
     */
    std::pair<double, double> getCursorPos() const;

    /**
     * @brief Define a posição do cursor
     * @param x Posição X
     * @param y Posição Y
     */
    void setCursorPos(double x, double y);

    /**
     * @brief Verifica se uma tecla está pressionada
     * @param key Código da tecla
     * @return true se está pressionada
     */
    bool isKeyPressed(int key) const;

    /**
     * @brief Verifica se um botão do mouse está pressionado
     * @param button Código do botão
     * @return true se está pressionado
     */
    bool isMouseButtonPressed(int button) const;

    /**
     * @brief Define o título da janela
     * @param title Novo título
     */
    void setTitle(const std::string& title);

    /**
     * @brief Obtém o título da janela
     * @return Título atual
     */
    std::string getTitle() const { return settings.title; }

    /**
     * @brief Verifica se a janela está inicializada
     * @return true se inicializada
     */
    bool isInitialized() const { return initialized; }

private:
    /**
     * @brief Configura os callbacks do GLFW
     */
    void setupCallbacks();
};

} // namespace VoxelMaker 