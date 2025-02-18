# Semáforo com Raspberry Pi Pico e Pico SDK

Este projeto implementa um semáforo utilizando a Raspberry Pi Pico e a ferramenta Pico SDK. O código faz uso da função `add_repeating_timer_ms()` para alternar entre os estados do semáforo a cada 3 segundos.

## 📌 Funcionalidades
- O LED RGB inicia na cor **vermelha** e alterna para **amarela** e depois **verde**, ciclicamente.
- A mudança de estado é gerenciada pela função `repeating_timer_callback()`.
- O programa imprime uma mensagem via serial a cada 1 segundo.
- Utiliza os GPIOs 11, 12 e 13 para controlar o LED RGB.

## 🛠 Requisitos
- Raspberry Pi Pico
- Ferramenta Educacional **BitDogLab**
- LED RGB conectado aos GPIOs:
  - **Vermelho**: GPIO 11
  - **Amarelo**: GPIO 12
  - **Verde**: GPIO 13
- Pico SDK instalado e configurado

## 🚀 Como Compilar e Executar

### 1️⃣ Configurar o Ambiente
Se ainda não configurou o **Pico SDK**, siga os passos abaixo:

```bash
# Clone o repositório do Pico SDK
git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
export PICO_SDK_PATH=$(pwd)
```

### 2️⃣ Compilar o Programa

```bash
# Criar diretório de build
mkdir build && cd build

# Gerar os arquivos de compilação
cmake .. -G "Ninja"
ninja
```

### 3️⃣ Fazer Upload para o Raspberry Pi Pico
1. Conecte a Raspberry Pi Pico ao PC em **modo BOOTSEL** (pressionando o botão BOOTSEL ao conectar o cabo USB).
2. Arraste o arquivo `.uf2` gerado para o dispositivo **RPI-RP2**.

### 4️⃣ Monitorar a Saída Serial
Para visualizar as mensagens impressas pelo programa:

```bash
screen /dev/ttyUSB0 115200
```

## 📋 Exemplo de Saída no Terminal

```
[INFO] Semáforo iniciado em vermelho
[INFO] Estado: Amarelo
[INFO] Estado: Verde
[INFO] Estado: Vermelho
...
```


