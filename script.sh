#!/bin/bash

# Caminho do código-fonte no Raspberry Pi
SOURCE_FILE="/caminho/para/seu_codigo.cpp"

# Caminho de destino no Windows
WINDOWS_USER="usuario_windows"  # Substitua pelo seu nome de usuário no Windows
WINDOWS_IP="192.168.0.100"       # IP do Windows na rede
WINDOWS_PATH="C:/caminho/destino/"  # Caminho de destino no Windows

# Compilar o código na Raspberry Pi
echo "Compilando o código..."
g++ -o seu_programa "$SOURCE_FILE" -lGL -lGLU -lglut
if [ $? -ne 0 ]; then
  echo "Erro ao compilar o código."
  exit 1
fi
echo "Compilação concluída com sucesso."

# Enviar o código-fonte para o Windows via SCP
echo "Transferindo código-fonte para o Windows..."
scp "$SOURCE_FILE" "$WINDOWS_USER@$WINDOWS_IP:$WINDOWS_PATH"
if [ $? -ne 0 ]; then
  echo "Erro ao transferir o arquivo para o Windows."
  exit 1
fi
echo "Arquivo transferido com sucesso."

# Aviso de conclusão
echo "Processo concluído. Pronto para compilar e executar no Windows."
