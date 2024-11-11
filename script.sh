#!/bin/bash

# Nome do programa (sem extensão)
PROGRAM_NAME="ouros71"

# Caminho do código-fonte na Raspberry Pi
SOURCE_FILE="/home/rasp/ifb_cg/Ex3_11-11/${PROGRAM_NAME}.c"

# Caminho de destino no Windows
WINDOWS_USER="tales"               # Substitua pelo seu nome de usuário no Windows
WINDOWS_IP="10.0.0.100"            # IP do Windows na rede
WINDOWS_PATH="D:/Files/codes/ifb_cg/Ex3_11-11"  # Caminho de destino no Windows

# Compilar o código na Raspberry Pi
echo "Compilando o código..."
gcc -o "$PROGRAM_NAME" "$SOURCE_FILE" -lGL -lGLU -lglut -lm
if [ $? -ne 0 ]; then
  echo "Erro ao compilar o código."
  exit 1
fi
echo "Compilação concluída com sucesso."

# Enviar o binário compilado para o Windows via SCP
echo "Transferindo binário para o Windows..."
scp "$PROGRAM_NAME" "$WINDOWS_USER@$WINDOWS_IP:$WINDOWS_PATH"
echo  "40028922"
if [ $? -ne 0 ]; then
  echo "Erro ao transferir o binário para o Windows."
  exit 1
fi
echo "Binário transferido com sucesso."

# Aviso de conclusão
echo "Processo concluído. O binário está pronto para ser executado no Windows."
