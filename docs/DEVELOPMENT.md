# Guia de Desenvolvimento - VoxelMaker

## Configuração do Ambiente

### Pré-requisitos

#### Ubuntu/Debian
```bash
# Instalar dependências básicas
sudo apt update
sudo apt install build-essential cmake git

# Instalar bibliotecas de desenvolvimento
sudo apt install libglfw3-dev libglm-dev libopengl-dev

# Instalar bibliotecas opcionais
sudo apt install libgtest-dev nlohmann-json3-dev
```

#### Arch Linux
```bash
# Instalar dependências básicas
sudo pacman -S base-devel cmake git

# Instalar bibliotecas de desenvolvimento
sudo pacman -S glfw-x11 glm

# Instalar bibliotecas opcionais
sudo pacman -S gtest nlohmann-json
```

#### macOS
```bash
# Instalar Homebrew (se não tiver)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar dependências
brew install cmake glfw glm

# Instalar bibliotecas opcionais
brew install googletest nlohmann-json
```

### Configuração do Projeto

1. **Clonar o repositório**
```bash
git clone <url-do-repositorio>
cd VoxelMaker
```

2. **Configurar dependências de terceiros**
```bash
# Criar diretório para dependências de terceiros
mkdir -p third_party

# Baixar GLAD (OpenGL Loader)
# TODO: Adicionar instruções para baixar GLAD

# Baixar Dear ImGui (opcional)
# TODO: Adicionar instruções para baixar ImGui
```

3. **Build do projeto**
```bash
# Build básico
./build.sh

# Build com debug
./build.sh -d

# Build com testes
./build.sh -t

# Build limpo
./build.sh -c
```

## Estrutura de Código

### Convenções de Nomenclatura

#### Classes
- **PascalCase**: `VoxelGrid`, `Renderer`, `Camera`
- **Prefixo de namespace**: `VoxelMaker::`

#### Métodos e Funções
- **camelCase**: `addVoxel()`, `renderScene()`, `getPosition()`
- **Verbos para ações**: `create()`, `destroy()`, `update()`
- **Getters/Setters**: `getProperty()`, `setProperty()`

#### Variáveis
- **camelCase**: `voxelCount`, `renderSettings`, `windowHandle`
- **Constantes**: `UPPER_SNAKE_CASE`: `MAX_VOXELS`, `DEFAULT_GRID_SIZE`

#### Arquivos
- **Headers**: `.hpp` (C++ headers)
- **Implementação**: `.cpp`
- **CMake**: `CMakeLists.txt`

### Padrões de Código

#### Headers
```cpp
#pragma once

#include <memory>
#include <vector>

namespace VoxelMaker {

class MyClass {
public:
    // Construtores primeiro
    MyClass();
    explicit MyClass(const std::string& name);
    
    // Destrutor
    ~MyClass();
    
    // Getters/Setters
    const std::string& getName() const;
    void setName(const std::string& name);
    
    // Métodos públicos
    bool initialize();
    void update();
    void cleanup();
    
private:
    // Membros privados
    std::string name;
    bool initialized;
    
    // Métodos privados
    void internalMethod();
};

} // namespace VoxelMaker
```

#### Implementação
```cpp
#include "MyClass.hpp"
#include <iostream>

namespace VoxelMaker {

MyClass::MyClass() 
    : name("default")
    , initialized(false) {
}

MyClass::MyClass(const std::string& name)
    : name(name)
    , initialized(false) {
}

MyClass::~MyClass() {
    cleanup();
}

const std::string& MyClass::getName() const {
    return name;
}

void MyClass::setName(const std::string& newName) {
    name = newName;
}

bool MyClass::initialize() {
    if (initialized) {
        return true;
    }
    
    // Lógica de inicialização
    initialized = true;
    return true;
}

void MyClass::update() {
    if (!initialized) {
        return;
    }
    
    // Lógica de atualização
}

void MyClass::cleanup() {
    if (!initialized) {
        return;
    }
    
    // Lógica de limpeza
    initialized = false;
}

void MyClass::internalMethod() {
    // Implementação de método privado
}

} // namespace VoxelMaker
```

## Debugging

### Configuração do Debugger

#### VSCode
Criar `.vscode/launch.json`:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug VoxelMaker",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/bin/voxelmaker",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

#### GDB
```bash
# Compilar com debug
./build.sh -d

# Executar com gdb
gdb build/bin/voxelmaker

# Comandos úteis do GDB
(gdb) break main
(gdb) run
(gdb) next
(gdb) step
(gdb) print variable_name
(gdb) bt
```

### Logging

O projeto usa um sistema de logging configurável:

```cpp
#include "utils/Logger.hpp"

// Logging básico
Logger::info("Mensagem informativa");
Logger::warning("Aviso");
Logger::error("Erro");
Logger::debug("Debug info");

// Logging com formatação
Logger::info("Voxel adicionado na posição ({}, {}, {})", x, y, z);
```

## Testes

### Executar Testes
```bash
# Compilar com testes
./build.sh -t

# Executar todos os testes
cd build && make test

# Executar testes específicos
./bin/test_voxel_core
```

### Escrever Testes
```cpp
#include <gtest/gtest.h>
#include "core/Voxel.hpp"

TEST(VoxelTest, Constructor) {
    VoxelMaker::Voxel voxel(glm::ivec3(1, 2, 3));
    
    EXPECT_EQ(voxel.getPosition(), glm::ivec3(1, 2, 3));
    EXPECT_TRUE(voxel.isActive());
}

TEST(VoxelTest, ColorSetting) {
    VoxelMaker::Voxel voxel;
    VoxelMaker::Voxel::Color color(255, 0, 0, 255);
    
    voxel.setColor(color);
    EXPECT_EQ(voxel.getColor().r, 255);
    EXPECT_EQ(voxel.getColor().g, 0);
    EXPECT_EQ(voxel.getColor().b, 0);
}
```

## Performance

### Profiling

#### Valgrind
```bash
# Análise de memória
valgrind --tool=memcheck --leak-check=full ./build/bin/voxelmaker

# Análise de performance
valgrind --tool=callgrind ./build/bin/voxelmaker
```

#### Perf
```bash
# Análise de performance
perf record ./build/bin/voxelmaker
perf report
```

### Otimizações

1. **Compilação otimizada**
```bash
./build.sh -r  # Release mode
```

2. **Flags de otimização**
```cmake
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
```

3. **Análise estática**
```bash
# Clang-tidy
clang-tidy src/**/*.cpp

# Cppcheck
cppcheck --enable=all src/
```

## Contribuição

### Workflow

1. **Criar branch**
```bash
git checkout -b feature/nova-funcionalidade
```

2. **Desenvolver**
- Seguir convenções de código
- Adicionar testes
- Documentar mudanças

3. **Commit**
```bash
git add .
git commit -m "feat: adicionar nova funcionalidade

- Descrição detalhada das mudanças
- Impacto na performance
- Testes adicionados"
```

4. **Push e Pull Request**
```bash
git push origin feature/nova-funcionalidade
# Criar PR no GitHub/GitLab
```

### Padrões de Commit

- `feat:` Nova funcionalidade
- `fix:` Correção de bug
- `docs:` Documentação
- `style:` Formatação de código
- `refactor:` Refatoração
- `test:` Testes
- `chore:` Tarefas de manutenção

## Recursos Úteis

### Documentação
- [OpenGL Documentation](https://www.opengl.org/documentation/)
- [GLFW Documentation](https://www.glfw.org/documentation.html)
- [GLM Documentation](https://glm.g-truc.net/0.9.9/index.html)

### Ferramentas
- [CMake Documentation](https://cmake.org/documentation/)
- [GTest Documentation](https://google.github.io/googletest/)
- [Dear ImGui](https://github.com/ocornut/imgui)

### Comunidade
- [OpenGL Forums](https://community.khronos.org/)
- [Stack Overflow - OpenGL](https://stackoverflow.com/questions/tagged/opengl) 