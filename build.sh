#!/bin/bash

# Script de build para VoxelMaker
# Uso: ./build.sh [opções]

set -e  # Parar em caso de erro

# Cores para output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Função para imprimir mensagens coloridas
print_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Função para mostrar ajuda
show_help() {
    echo "Script de build para VoxelMaker"
    echo ""
    echo "Uso: $0 [opções]"
    echo ""
    echo "Opções:"
    echo "  -h, --help          Mostrar esta ajuda"
    echo "  -c, --clean         Limpar build anterior"
    echo "  -d, --debug         Build em modo debug"
    echo "  -r, --release       Build em modo release"
    echo "  -t, --tests         Incluir testes"
    echo "  -j N                Usar N jobs para compilação (padrão: número de CPUs)"
    echo "  --install           Instalar após build"
    echo ""
    echo "Exemplos:"
    echo "  $0                  Build padrão (release)"
    echo "  $0 -d               Build debug"
    echo "  $0 -c -d            Limpar e build debug"
    echo "  $0 -t -j 4          Build com testes usando 4 jobs"
}

# Variáveis padrão
BUILD_TYPE="Release"
CLEAN_BUILD=false
BUILD_TESTS=false
INSTALL_AFTER_BUILD=false
JOBS=$(nproc)

# Processar argumentos
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_help
            exit 0
            ;;
        -c|--clean)
            CLEAN_BUILD=true
            shift
            ;;
        -d|--debug)
            BUILD_TYPE="Debug"
            shift
            ;;
        -r|--release)
            BUILD_TYPE="Release"
            shift
            ;;
        -t|--tests)
            BUILD_TESTS=true
            shift
            ;;
        -j)
            JOBS="$2"
            shift 2
            ;;
        --install)
            INSTALL_AFTER_BUILD=true
            shift
            ;;
        *)
            print_error "Opção desconhecida: $1"
            show_help
            exit 1
            ;;
    esac
done

# Verificar se estamos no diretório correto
if [[ ! -f "CMakeLists.txt" ]]; then
    print_error "Este script deve ser executado no diretório raiz do projeto"
    exit 1
fi

print_info "Iniciando build do VoxelMaker"
print_info "Tipo de build: $BUILD_TYPE"
print_info "Jobs: $JOBS"
print_info "Testes: $([ "$BUILD_TESTS" = true ] && echo "Sim" || echo "Não")"

# Criar diretório de build se não existir
if [[ ! -d "build" ]]; then
    print_info "Criando diretório build"
    mkdir -p build
fi

# Limpar build anterior se solicitado
if [[ "$CLEAN_BUILD" = true ]]; then
    print_info "Limpando build anterior"
    rm -rf build/*
fi

# Entrar no diretório de build
cd build

# Configurar CMake
print_info "Configurando CMake..."
CMAKE_ARGS="-DCMAKE_BUILD_TYPE=$BUILD_TYPE"

if [[ "$BUILD_TESTS" = true ]]; then
    CMAKE_ARGS="$CMAKE_ARGS -DBUILD_TESTS=ON"
fi

cmake .. $CMAKE_ARGS

# Compilar
print_info "Compilando..."
make -j$JOBS

# Verificar se a compilação foi bem-sucedida
if [[ $? -eq 0 ]]; then
    print_success "Compilação concluída com sucesso!"
    
    # Executar testes se habilitados
    if [[ "$BUILD_TESTS" = true ]]; then
        print_info "Executando testes..."
        make test
    fi
    
    # Instalar se solicitado
    if [[ "$INSTALL_AFTER_BUILD" = true ]]; then
        print_info "Instalando..."
        sudo make install
        print_success "Instalação concluída!"
    fi
    
    print_info "Executável disponível em: build/bin/voxelmaker"
    
else
    print_error "Erro durante a compilação"
    exit 1
fi

print_success "Build concluído com sucesso!" 