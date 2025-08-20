# TODO - VoxelMaker

## 🎯 Visão Geral
Este arquivo lista todas as implementações pendentes no projeto VoxelMaker, organizadas por prioridade e módulo.

---

## 🔥 **PRIORIDADE ALTA** - Funcionalidade Básica

### 1. Configuração do GLAD
- [ ] **Baixar GLAD** da [GLAD Web Service](https://glad.dav1d.de/)
  - [ ] Configurar para OpenGL 3.3+ Core Profile
  - [ ] Extrair para `third_party/glad/`
- [ ] **Atualizar CMakeLists.txt** para incluir GLAD
- [ ] **Integrar GLAD** nos arquivos que usam OpenGL

### 2. Renderização OpenGL Real

#### Renderer.cpp
- [ ] `initialize()` - Inicializar GLAD e OpenGL
- [ ] `cleanup()` - Limpar recursos OpenGL
- [ ] `renderVoxelGrid()` - Renderizar grid de voxels
- [ ] `renderVoxel()` - Renderizar voxel individual
- [ ] `renderGrid()` - Renderizar grid de referência
- [ ] `renderAxes()` - Renderizar eixos coordenados
- [ ] `initializeShaders()` - Carregar shaders
- [ ] `initializeBuffers()` - Criar VBOs/VAOs
- [ ] `createCubeGeometry()` - Geometria do cubo
- [ ] `createGridGeometry()` - Geometria do grid
- [ ] `createAxesGeometry()` - Geometria dos eixos
- [ ] `updateMatrices()` - Atualizar matrizes MVP

#### Shader.cpp
- [ ] `loadFromFiles()` - Carregar shaders de arquivos
- [ ] `compile()` - Compilar shaders
- [ ] `use()` - Ativar shader
- [ ] `unbind()` - Desativar shader
- [ ] `setUniform()` - Definir uniforms
- [ ] `getUniformLocation()` - Obter localização de uniform
- [ ] `compileShader()` - Compilar shader individual
- [ ] `checkCompileErrors()` - Verificar erros de compilação

#### Shaders (Arquivos)
- [ ] Criar `shaders/voxel.vert` - Vertex shader para voxels
- [ ] Criar `shaders/voxel.frag` - Fragment shader para voxels
- [ ] Criar `shaders/grid.vert` - Vertex shader para grid
- [ ] Criar `shaders/grid.frag` - Fragment shader para grid
- [ ] Criar `shaders/axes.vert` - Vertex shader para eixos
- [ ] Criar `shaders/axes.frag` - Fragment shader para eixos

---

## ⚡ **PRIORIDADE MÉDIA** - Interação e Ferramentas

### 3. Sistema de Input e Controles

#### main.cpp
- [ ] `update()` - Lógica de atualização principal
- [ ] `handleKeyInput()` - Alternar ferramentas (tecla ESPAÇO)
- [ ] `handleMouseMove()` - Controle de câmera
- [ ] `handleMouseButton()` - Interação com voxels

#### Input.cpp
- [ ] Sistema de processamento de entrada
- [ ] Mapeamento de teclas
- [ ] Estados de mouse
- [ ] Callbacks de input
- [ ] Sistema de eventos

### 4. Ferramentas de Edição

#### BrushTool.cpp
- [ ] Adicionar voxels
- [ ] Remover voxels
- [ ] Diferentes tamanhos de pincel
- [ ] Modos de pintura
- [ ] Configuração de cor/material

#### SelectionTool.cpp
- [ ] Seleção de voxels individuais
- [ ] Seleção em área
- [ ] Seleção múltipla
- [ ] Operações em lote
- [ ] Visualização de seleção

#### TransformTool.cpp
- [ ] Mover voxels selecionados
- [ ] Rotacionar seleções
- [ ] Escalar seleções
- [ ] Duplicar seleções
- [ ] Transformações em eixos específicos

### 5. Interface Gráfica

#### UI.cpp
- [ ] Interface com Dear ImGui
- [ ] Painéis de ferramentas
- [ ] Propriedades de voxels
- [ ] Menu principal
- [ ] Barra de status
- [ ] Configurações de renderização

---

## 📁 **PRIORIDADE BAIXA** - Funcionalidades Avançadas

### 6. Sistema de Arquivos

#### FileUtils.cpp
- [ ] Salvar projetos (.vox)
- [ ] Carregar projetos
- [ ] Exportar para formatos 3D (OBJ, PLY)
- [ ] Gerenciamento de arquivos
- [ ] Sistema de autosave

#### VoxelObject.cpp
- [ ] Agrupamento de voxels
- [ ] Operações em objetos
- [ ] Hierarquia de objetos
- [ ] Instâncias de objetos

### 7. Utilitários

#### Logger.cpp
- [ ] Sistema de logging
- [ ] Diferentes níveis (DEBUG, INFO, WARNING, ERROR)
- [ ] Output para arquivo/console
- [ ] Timestamps
- [ ] Configuração de log

#### MathUtils.cpp
- [ ] Funções matemáticas auxiliares
- [ ] Intersecção de raios
- [ ] Transformações geométricas
- [ ] Otimizações matemáticas

#### Mesh.cpp
- [ ] Gerenciamento de geometria
- [ ] Otimização de malhas
- [ ] LOD (Level of Detail)
- [ ] Cache de geometria

### 8. Funcionalidades do Core

#### VoxelGrid.cpp
- [ ] `applyTransform()` - Transformação de voxels
- [ ] Otimizações de performance
- [ ] Spatial hashing
- [ ] Compressão de dados

---

## 🧪 **TESTES E QUALIDADE**

### Testes Unitários
- [ ] Testes para Voxel
- [ ] Testes para VoxelGrid
- [ ] Testes para Camera
- [ ] Testes para Renderer
- [ ] Testes para Shader
- [ ] Testes para Window

### Testes de Integração
- [ ] Testes de renderização
- [ ] Testes de input
- [ ] Testes de ferramentas
- [ ] Testes de arquivos

### Validação e Tratamento de Erros
- [ ] Validação de entrada
- [ ] Tratamento de erros OpenGL
- [ ] Tratamento de erros de arquivo
- [ ] Sistema de recuperação de erros

---

## ⚡ **OTIMIZAÇÕES**

### Performance
- [ ] Frustum culling
- [ ] Instanced rendering
- [ ] LOD (Level of Detail)
- [ ] Multithreading
- [ ] Cache de geometria
- [ ] Otimização de memória

### Renderização
- [ ] Sombreado avançado
- [ ] Efeitos de iluminação
- [ ] Anti-aliasing
- [ ] Bloom/glow effects
- [ ] Partículas

---

## 📚 **DOCUMENTAÇÃO**

### Documentação Técnica
- [ ] Documentação da API
- [ ] Guia de desenvolvimento
- [ ] Documentação de shaders
- [ ] Documentação de ferramentas

### Documentação do Usuário
- [ ] Manual do usuário
- [ ] Tutorial básico
- [ ] Guia de ferramentas
- [ ] FAQ

---

## 🎨 **RECURSOS VISUAIS**

### Texturas e Materiais
- [ ] Sistema de materiais
- [ ] Texturas para voxels
- [ ] Normal maps
- [ ] PBR materials

### Interface Visual
- [ ] Ícones para ferramentas
- [ ] Temas de interface
- [ ] Animações de transição
- [ ] Feedback visual

---

## 🔧 **CONFIGURAÇÃO E BUILD**

### CMake
- [ ] Configuração para diferentes plataformas
- [ ] Opções de build condicionais
- [ ] Configuração de dependências opcionais
- [ ] Scripts de instalação

### Dependências
- [ ] Dear ImGui para interface
- [ ] stb_image para texturas
- [ ] nlohmann/json para arquivos
- [ ] spdlog para logging

---

## 📊 **ESTATÍSTICAS DE PROGRESSO**

### Módulos
- [ ] **Core**: 90% completo
- [ ] **Graphics**: 20% completo
- [ ] **UI**: 100% completo (Window)
- [ ] **Tools**: 0% completo
- [ ] **Utils**: 0% completo

### Funcionalidades Principais
- [ ] **Renderização**: 20% completo
- [ ] **Input**: 30% completo
- [ ] **Ferramentas**: 0% completo
- [ ] **Arquivos**: 0% completo
- [ ] **Interface**: 0% completo

---

## 🎯 **PRÓXIMOS PASSOS IMEDIATOS**

1. **Configurar GLAD** - Permitir renderização OpenGL real
2. **Implementar renderização básica** - Ver voxels na tela
3. **Adicionar controles de câmera** - Navegar pelo espaço 3D
4. **Implementar BrushTool básico** - Adicionar/remover voxels
5. **Criar interface simples** - Painel de ferramentas

---

## 📝 **NOTAS**

- O projeto está **bem estruturado** e **pronto para desenvolvimento**
- A base sólida permite implementar funcionalidades gradualmente
- Priorizar funcionalidades que permitam **testar e ver resultados visuais**
- Manter a **organização e qualidade do código** durante o desenvolvimento

---

*Última atualização: $(date)*
*Status: Estrutura básica completa, aguardando implementação de funcionalidades* 