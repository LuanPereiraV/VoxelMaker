# Instruções de Instalação - VoxelMaker

## Pré-requisitos

### Ubuntu/Debian
```bash
# Atualizar repositórios
sudo apt update

# Instalar dependências básicas
sudo apt install build-essential cmake git

# Instalar bibliotecas de desenvolvimento OpenGL
sudo apt install libglfw3-dev libglm-dev libopengl-dev

# Instalar bibliotecas opcionais
sudo apt install libgtest-dev nlohmann-json3-dev
```

### Arch Linux
```bash
# Instalar dependências básicas
sudo pacman -S base-devel cmake git

# Instalar bibliotecas de desenvolvimento
sudo pacman -S glfw-x11 glm

# Instalar bibliotecas opcionais
sudo pacman -S gtest nlohmann-json
```

### Fedora/RHEL
```bash
# Instalar dependências básicas
sudo dnf install gcc-c++ cmake git

# Instalar bibliotecas de desenvolvimento
sudo dnf install glfw-devel glm-devel mesa-libGL-devel

# Instalar bibliotecas opcionais
sudo dnf install gtest-devel nlohmann-json-devel
```

### macOS
```bash
# Instalar Homebrew (se não tiver)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Instalar dependências
brew install cmake glfw glm

# Instalar bibliotecas opcionais
brew install googletest nlohmann-json
```

## Configuração do GLAD

O projeto usa GLAD para carregar as funções OpenGL. Você precisa baixar e configurar o GLAD:

### Opção 1: Baixar GLAD manualmente
1. Acesse [GLAD Web Service](https://glad.dav1d.de/)
2. Configure:
   - Language: C/C++
   - Specification: OpenGL
   - API: OpenGL 3.3 ou superior
   - Profile: Core
3. Baixe o arquivo ZIP
4. Extraia e copie os arquivos para `third_party/glad/`

### Opção 2: Usar script de download
```bash
# Criar diretório para dependências
mkdir -p third_party

# Baixar GLAD (exemplo - ajuste conforme necessário)
cd third_party
wget https://github.com/Dav1dde/glad/releases/download/v0.1.36/glad.zip
unzip glad.zip
cd ..
```

## Estrutura de Dependências

Após a instalação, sua estrutura deve ficar assim:
```
VoxelMaker/
├── third_party/
│   └── glad/
│       ├── include/
│       │   └── glad/
│       │       └── glad.h
│       └── src/
│           └── glad.c
├── src/
├── include/
└── ...
```

## Verificação da Instalação

### Verificar OpenGL
```bash
# Verificar se o OpenGL está disponível
glxinfo | grep "OpenGL version"
```

### Verificar GLFW
```bash
# Verificar se o GLFW está instalado
pkg-config --modversion glfw3
```

### Verificar GLM
```bash
# Verificar se o GLM está instalado
pkg-config --modversion glm
```

## Problemas Comuns

### Erro: "OpenGL não encontrado"
```bash
# Ubuntu/Debian
sudo apt install libopengl-dev

# Arch Linux
sudo pacman -S opengl-driver

# Fedora
sudo dnf install mesa-libGL-devel
```

### Erro: "GLFW não encontrado"
```bash
# Ubuntu/Debian
sudo apt install libglfw3-dev

# Arch Linux
sudo pacman -S glfw-x11

# Fedora
sudo dnf install glfw-devel
```

### Erro: "GLM não encontrado"
```bash
# Ubuntu/Debian
sudo apt install libglm-dev

# Arch Linux
sudo pacman -S glm

# Fedora
sudo dnf install glm-devel
```

### Erro de compilação do GLAD
- Verifique se o GLAD foi baixado corretamente
- Certifique-se de que os arquivos estão em `third_party/glad/`
- Verifique se o CMakeLists.txt está configurado corretamente

## Build do Projeto

Após instalar todas as dependências:

```bash
# Build básico
./build.sh

# Build com debug
./build.sh -d

# Build com testes
./build.sh -t
```

## Próximos Passos

1. **Instalar dependências** seguindo as instruções acima
2. **Configurar GLAD** na pasta `third_party/`
3. **Executar build** com `./build.sh`
4. **Testar aplicação** executando `./build/bin/voxelmaker`

## Suporte

Se encontrar problemas:
1. Verifique se todas as dependências estão instaladas
2. Consulte a documentação das bibliotecas
3. Verifique os logs de erro durante o build
4. Abra uma issue no repositório do projeto 