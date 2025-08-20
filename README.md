# VoxelMaker

Um software de criação de objetos 3D utilizando cubos (voxels) de forma rápida e intuitiva.

## Descrição

VoxelMaker é uma ferramenta de modelagem 3D focada na criação de objetos através de cubos. O software foi projetado para ser de fácil aprendizado, permitindo que usuários de todos os níveis criem modelos 3D de forma rápida e eficiente.

## Características

- Interface gráfica intuitiva
- Criação de objetos 3D usando cubos
- Ferramentas de edição simples e eficazes
- Sistema de camadas
- Exportação para formatos comuns
- Interface responsiva e moderna

## Estrutura do Projeto

```
VoxelMaker/
├── src/                    # Código fonte
│   ├── core/              # Lógica principal do voxel
│   ├── graphics/          # Renderização e gráficos
│   ├── ui/                # Interface do usuário
│   ├── tools/             # Ferramentas de edição
│   └── utils/             # Utilitários
├── include/               # Headers públicos
├── assets/                # Recursos (texturas, modelos, etc.)
├── docs/                  # Documentação
├── tests/                 # Testes unitários
├── build/                 # Arquivos de build (gerado)
├── CMakeLists.txt         # Configuração CMake
└── README.md              # Este arquivo
```

## Requisitos

- C++17 ou superior
- CMake 3.16 ou superior
- Biblioteca gráfica (a ser definida)

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Uso

Após o build, execute:
```bash
./bin/voxelmaker
```

## Desenvolvimento

Este projeto está em desenvolvimento ativo. A estrutura básica está sendo estabelecida e as funcionalidades serão implementadas gradualmente.

## Licença

[Licença a ser definida] 