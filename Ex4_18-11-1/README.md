# 2D House Drawing Program

Este aplicativo é um exemplo de uso da biblioteca OpenGL para desenhar formas geométricas simples e interagir com elas usando o teclado. Ele foi desenvolvido como parte de um exercício de computação gráfica.

## Key Bindings

### Teclas de Movimento

- **Seta para Cima (`↑`)**: Move a casa para cima.
- **Seta para Baixo (`↓`)**: Move a casa para baixo.
- **Seta para Esquerda (`←`)**: Move a casa para a esquerda.
- **Seta para Direita (`→`)**: Move a casa para a direita.

### Teclas de Rotação

- **Page Up**: Rotaciona a casa para a esquerda.
- **Page Down**: Rotaciona a casa para a direita.

### Teclas de Zoom

- **Home**: Dá zoom out (afasta a visão).
- **End**: Dá zoom in (aproxima a visão).

### Teclas de Panorâmica

- **F9**: Panorâmica para a direita.
- **F10**: Panorâmica para a esquerda.
- **F11**: Panorâmica para cima.
- **F12**: Panorâmica para baixo.

### Teclas de Movimento Diagonal

- **Q**: Movimento diagonal para cima e para a esquerda.
- **A**: Movimento diagonal para baixo e para a esquerda.
- **E**: Movimento diagonal para cima e para a direita.
- **D**: Movimento diagonal para baixo e para a direita.

### Outras Funcionalidades

- **Insert**: Reseta a posição e a rotação da casa para o centro da tela.
- **ESC**: Fecha o aplicativo.

## Compilação e Execução

Para compilar e executar o aplicativo, utilize o `Makefile`.

```sh
make
make run
make clean