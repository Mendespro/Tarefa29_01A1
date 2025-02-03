cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Configuração do ambiente do Raspberry Pi Pico VS Code Extension
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Definição do modelo da placa
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importação do SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Configuração do projeto
project(Tarefa29d01 C CXX ASM)

# Inicialização do SDK
pico_sdk_init()

# Criação do executável
add_executable(Tarefa29d01 Tarefa29d01.c)

# Geração do cabeçalho PIO
pico_generate_pio_header(Tarefa29d01 ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

# Definição do nome e versão do programa
pico_set_program_name(Tarefa29d01 "Tarefa29d01")
pico_set_program_version(Tarefa29d01 "0.1")

# Configuração da saída padrão
pico_enable_stdio_uart(Tarefa29d01 0)
pico_enable_stdio_usb(Tarefa29d01 1)

# Adicionar bibliotecas necessárias
target_link_libraries(Tarefa29d01
    pico_stdlib
    hardware_pwm
    hardware_pio
    hardware_clocks
)

# Adicionar diretórios de include
target_include_directories(Tarefa29d01 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Gerar arquivos de saída extras
pico_add_extra_outputs(Tarefa29d01)
