#pragma once

#include "../core/VoxelGrid.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include <memory>
#include <vector>

namespace VoxelMaker {

/**
 * @brief Gerencia a renderização dos voxels
 */
class Renderer {
public:
    /**
     * @brief Configurações de renderização
     */
    struct RenderSettings {
        bool wireframeMode;
        bool showGrid;
        bool showAxes;
        bool enableLighting;
        float voxelSize;
        
        RenderSettings() 
            : wireframeMode(false)
            , showGrid(true)
            , showAxes(true)
            , enableLighting(true)
            , voxelSize(1.0f) {}
    };

private:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<Shader> voxelShader;
    std::shared_ptr<Shader> gridShader;
    std::shared_ptr<Shader> axesShader;
    
    RenderSettings settings;
    
    // OpenGL buffers
    unsigned int voxelVAO, voxelVBO, voxelEBO;
    unsigned int gridVAO, gridVBO;
    unsigned int axesVAO, axesVBO;
    
    bool initialized;

public:
    /**
     * @brief Construtor
     */
    Renderer();

    /**
     * @brief Destrutor
     */
    ~Renderer();

    /**
     * @brief Inicializa o renderer
     * @return true se inicializado com sucesso
     */
    bool initialize();

    /**
     * @brief Limpa recursos do renderer
     */
    void cleanup();

    /**
     * @brief Define a câmera
     * @param cam Câmera a ser usada
     */
    void setCamera(std::shared_ptr<Camera> cam) { camera = cam; }

    /**
     * @brief Renderiza um grid de voxels
     * @param grid Grid a ser renderizado
     */
    void renderVoxelGrid(const VoxelGrid& grid);

    /**
     * @brief Renderiza um voxel individual
     * @param voxel Voxel a ser renderizado
     */
    void renderVoxel(const Voxel& voxel);

    /**
     * @brief Renderiza o grid de referência
     */
    void renderGrid();

    /**
     * @brief Renderiza os eixos de coordenadas
     */
    void renderAxes();

    /**
     * @brief Define as configurações de renderização
     * @param settings Novas configurações
     */
    void setRenderSettings(const RenderSettings& settings) { this->settings = settings; }

    /**
     * @brief Obtém as configurações de renderização
     * @return Configurações atuais
     */
    const RenderSettings& getRenderSettings() const { return settings; }

    /**
     * @brief Verifica se o renderer está inicializado
     * @return true se inicializado
     */
    bool isInitialized() const { return initialized; }

private:
    /**
     * @brief Inicializa os shaders
     * @return true se inicializados com sucesso
     */
    bool initializeShaders();

    /**
     * @brief Inicializa os buffers de geometria
     * @return true se inicializados com sucesso
     */
    bool initializeBuffers();

    /**
     * @brief Cria a geometria do cubo
     */
    void createCubeGeometry();

    /**
     * @brief Cria a geometria do grid
     */
    void createGridGeometry();

    /**
     * @brief Cria a geometria dos eixos
     */
    void createAxesGeometry();

    /**
     * @brief Atualiza as matrizes de transformação
     */
    void updateMatrices();
};

} // namespace VoxelMaker 