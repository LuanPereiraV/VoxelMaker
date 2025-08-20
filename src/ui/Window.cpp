#include "ui/Window.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

namespace VoxelMaker {

Window::Window() 
    : settings()
    , callbacks()
    , windowHandle(nullptr)
    , initialized(false) {
}

Window::Window(const WindowSettings& settings)
    : settings(settings)
    , callbacks()
    , windowHandle(nullptr)
    , initialized(false) {
}

Window::~Window() {
    cleanup();
}

bool Window::initialize() {
    if (initialized) {
        return true;
    }

    // Inicializar GLFW
    if (!glfwInit()) {
        std::cerr << "Erro ao inicializar GLFW" << std::endl;
        return false;
    }

    // Configurar GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, settings.resizable ? GLFW_TRUE : GLFW_FALSE);

    // Criar janela
    windowHandle = glfwCreateWindow(
        settings.width, 
        settings.height, 
        settings.title.c_str(), 
        settings.fullscreen ? glfwGetPrimaryMonitor() : nullptr, 
        nullptr
    );

    if (!windowHandle) {
        std::cerr << "Erro ao criar janela GLFW" << std::endl;
        glfwTerminate();
        return false;
    }

    // Definir contexto OpenGL
    glfwMakeContextCurrent(static_cast<GLFWwindow*>(windowHandle));

    // Configurar VSync
    if (settings.vsync) {
        glfwSwapInterval(1);
    } else {
        glfwSwapInterval(0);
    }

    // Configurar callbacks
    setupCallbacks();

    initialized = true;
    return true;
}

void Window::cleanup() {
    if (windowHandle) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(windowHandle));
        windowHandle = nullptr;
    }
    
    if (initialized) {
        glfwTerminate();
        initialized = false;
    }
}

void Window::pollEvents() {
    if (initialized) {
        glfwPollEvents();
    }
}

void Window::swapBuffers() {
    if (windowHandle) {
        glfwSwapBuffers(static_cast<GLFWwindow*>(windowHandle));
    }
}

bool Window::shouldClose() const {
    if (windowHandle) {
        return glfwWindowShouldClose(static_cast<GLFWwindow*>(windowHandle));
    }
    return true;
}

void Window::setSettings(const WindowSettings& newSettings) {
    settings = newSettings;
    
    if (windowHandle) {
        // Aplicar novas configurações
        glfwSetWindowSize(static_cast<GLFWwindow*>(windowHandle), settings.width, settings.height);
        glfwSetWindowTitle(static_cast<GLFWwindow*>(windowHandle), settings.title.c_str());
        
        if (settings.vsync) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
    }
}

void Window::setEventCallbacks(const EventCallbacks& newCallbacks) {
    callbacks = newCallbacks;
}

std::pair<int, int> Window::getSize() const {
    if (windowHandle) {
        int width, height;
        glfwGetWindowSize(static_cast<GLFWwindow*>(windowHandle), &width, &height);
        return {width, height};
    }
    return {settings.width, settings.height};
}

void Window::setSize(int width, int height) {
    if (windowHandle) {
        glfwSetWindowSize(static_cast<GLFWwindow*>(windowHandle), width, height);
    }
    settings.width = width;
    settings.height = height;
}

std::pair<double, double> Window::getCursorPos() const {
    if (windowHandle) {
        double x, y;
        glfwGetCursorPos(static_cast<GLFWwindow*>(windowHandle), &x, &y);
        return {x, y};
    }
    return {0.0, 0.0};
}

void Window::setCursorPos(double x, double y) {
    if (windowHandle) {
        glfwSetCursorPos(static_cast<GLFWwindow*>(windowHandle), x, y);
    }
}

bool Window::isKeyPressed(int key) const {
    if (windowHandle) {
        return glfwGetKey(static_cast<GLFWwindow*>(windowHandle), key) == GLFW_PRESS;
    }
    return false;
}

bool Window::isMouseButtonPressed(int button) const {
    if (windowHandle) {
        return glfwGetMouseButton(static_cast<GLFWwindow*>(windowHandle), button) == GLFW_PRESS;
    }
    return false;
}

void Window::setTitle(const std::string& title) {
    if (windowHandle) {
        glfwSetWindowTitle(static_cast<GLFWwindow*>(windowHandle), title.c_str());
    }
    settings.title = title;
}

void Window::setupCallbacks() {
    if (!windowHandle) return;

    GLFWwindow* window = static_cast<GLFWwindow*>(windowHandle);

    // Callback de redimensionamento
    glfwSetWindowSizeCallback(window, [](GLFWwindow* w, int width, int height) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onResize) {
            window->callbacks.onResize(width, height);
        }
    });

    // Callback de movimento do mouse
    glfwSetCursorPosCallback(window, [](GLFWwindow* w, double x, double y) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onMouseMove) {
            window->callbacks.onMouseMove(static_cast<int>(x), static_cast<int>(y));
        }
    });

    // Callback de botões do mouse
    glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int button, int action, int mods) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onMouseButton) {
            window->callbacks.onMouseButton(button, action, mods);
        }
    });

    // Callback de scroll
    glfwSetScrollCallback(window, [](GLFWwindow* w, double xoffset, double yoffset) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onScroll) {
            window->callbacks.onScroll(xoffset, yoffset);
        }
    });

    // Callback de teclado
    glfwSetKeyCallback(window, [](GLFWwindow* w, int key, int scancode, int action, int mods) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onKey) {
            window->callbacks.onKey(key, scancode, action, mods);
        }
    });

    // Callback de fechamento
    glfwSetWindowCloseCallback(window, [](GLFWwindow* w) {
        Window* window = static_cast<Window*>(glfwGetWindowUserPointer(w));
        if (window && window->callbacks.onClose) {
            window->callbacks.onClose();
        }
    });

    // Definir ponteiro para a janela
    glfwSetWindowUserPointer(window, this);
}

} // namespace VoxelMaker 