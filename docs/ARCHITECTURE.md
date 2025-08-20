# Arquitetura do VoxelMaker

## Visão Geral

O VoxelMaker é um software de modelagem 3D baseado em voxels (cubos) projetado para ser intuitivo e fácil de usar. A arquitetura foi desenvolvida seguindo princípios de design modular e extensível.

## Estrutura de Módulos

### 1. Core (Núcleo)
**Localização**: `src/core/` e `include/core/`

Responsável pela lógica fundamental do sistema de voxels:

- **Voxel**: Representa um cubo individual no espaço 3D
- **VoxelGrid**: Gerencia o grid 3D de voxels
- **VoxelObject**: Representa objetos compostos por múltiplos voxels

### 2. Graphics (Gráficos)
**Localização**: `src/graphics/` e `include/graphics/`

Gerencia toda a renderização e visualização:

- **Renderer**: Sistema principal de renderização
- **Camera**: Controle de câmera 3D
- **Shader**: Gerenciamento de shaders OpenGL
- **Mesh**: Geração e manipulação de geometria

### 3. UI (Interface do Usuário)
**Localização**: `src/ui/` e `include/ui/`

Interface gráfica e interação com o usuário:

- **Window**: Gerenciamento da janela principal
- **UI**: Sistema de interface gráfica
- **Input**: Processamento de entrada do usuário

### 4. Tools (Ferramentas)
**Localização**: `src/tools/` e `include/tools/`

Ferramentas de edição e manipulação:

- **BrushTool**: Ferramenta de pincel para adicionar/remover voxels
- **SelectionTool**: Seleção de voxels
- **TransformTool**: Transformações (mover, rotacionar, escalar)

### 5. Utils (Utilitários)
**Localização**: `src/utils/` e `include/utils/`

Funções auxiliares e utilitários:

- **Logger**: Sistema de logging
- **FileUtils**: Manipulação de arquivos
- **MathUtils**: Funções matemáticas auxiliares

## Fluxo de Dados

```
Input → UI → Tools → Core → Graphics → Window
```

1. **Input**: Eventos de mouse/teclado
2. **UI**: Processamento da interface
3. **Tools**: Aplicação de ferramentas de edição
4. **Core**: Modificação do modelo de voxels
5. **Graphics**: Renderização da cena
6. **Window**: Exibição na tela

## Padrões de Design

### 1. Singleton
- **Logger**: Instância única para logging
- **Renderer**: Instância única para renderização

### 2. Observer
- **Event System**: Notificação de mudanças no modelo
- **UI Updates**: Atualização automática da interface

### 3. Factory
- **Tool Factory**: Criação de ferramentas
- **Shader Factory**: Criação de shaders

### 4. Command
- **Undo/Redo**: Sistema de desfazer/refazer
- **Tool Commands**: Comandos de ferramentas

## Dependências Externas

### Bibliotecas Necessárias
- **OpenGL**: Renderização gráfica
- **GLFW**: Gerenciamento de janelas
- **GLM**: Matemática linear
- **GLAD**: Loader de funções OpenGL

### Bibliotecas Opcionais
- **Dear ImGui**: Interface gráfica
- **stb_image**: Carregamento de imagens
- **nlohmann/json**: Serialização JSON

## Configuração de Build

### CMake
O projeto usa CMake para configuração de build:

```cmake
# Configuração principal
cmake_minimum_required(VERSION 3.16)
project(VoxelMaker VERSION 1.0.0)

# Opções de build
option(BUILD_TESTS "Build tests" OFF)
option(BUILD_DOCS "Build documentation" OFF)
```

### Estrutura de Build
```
build/
├── bin/          # Executáveis
├── lib/          # Bibliotecas
└── CMakeFiles/   # Arquivos do CMake
```

## Extensibilidade

### Plugins
O sistema foi projetado para suportar plugins:

- **Tool Plugins**: Novas ferramentas de edição
- **Renderer Plugins**: Novos métodos de renderização
- **Format Plugins**: Novos formatos de arquivo

### Configuração
Sistema de configuração flexível:

- **Settings**: Configurações da aplicação
- **Keybindings**: Atalhos de teclado
- **UI Layout**: Layout da interface

## Performance

### Otimizações Planejadas
- **Spatial Hashing**: Aceleração de consultas espaciais
- **Level of Detail**: Detalhamento adaptativo
- **Frustum Culling**: Remoção de objetos fora da tela
- **Instanced Rendering**: Renderização em lote

### Profiling
- **Performance Counters**: Métricas de performance
- **Memory Tracking**: Monitoramento de memória
- **GPU Profiling**: Análise de performance da GPU

## Segurança

### Validação de Entrada
- **Bounds Checking**: Verificação de limites
- **Input Sanitization**: Sanitização de entrada
- **Error Handling**: Tratamento de erros robusto

### Memória
- **RAII**: Gerenciamento automático de recursos
- **Smart Pointers**: Ponteiros inteligentes
- **Memory Pools**: Pools de memória para objetos frequentes 