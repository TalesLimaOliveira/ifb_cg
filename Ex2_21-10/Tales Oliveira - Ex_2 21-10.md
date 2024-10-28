# Exercícios para 21/10 - Computação Gráfica

Esta lista de exercicio é para a disciplina **Computação Gráfica** ministrada pelo Prof. [Raimundo Claudio Vasconcelos]()

Por [Tales L. Oliveira.](https://github.com/TalesLimaOliveira)


### 1) Codigo de conversão de RGB para CMYK

```c
/**
 * @file CG_2_1.c
 * @author Tales Oliveira (github.com/TalesLimaOliveira)
 * @date 2024-10-21
 *
 * @brief Converts RGB values to CMYK
 */

#include <stdio.h>

#define RED 100
#define GREEN 200
#define BLUE 100

double max(double A, double B) {
    return (A > B) ? A : B;
}

int main(void) {
    double R, G, B;
    double C, M, Y, K;

    R = RED / 255.0;
    G = GREEN / 255.0;
    B = BLUE / 255.0;

    K = 1.0 - max(max(R, G), B);

    if (K < 1.0) {
        C = (1.0 - R - K) / (1.0 - K);
        M = (1.0 - G - K) / (1.0 - K);
        Y = (1.0 - B - K) / (1.0 - K);
    }
    else {
        C = 0, M = 0, Y = 0;
    } 

    printf("C:%.2f  M:%.2f  Y:%.2f  K:%.2f\n", C, M, Y, K);
    return 0;
}
```

### 2) Qual formato armazena mais informações de cores: JPEG ou GIF?

	JPEG armazena mais informações de cores do que o GIF.

    O formato JPEG suporta cores em 24 bits, o que permite representar até 16,7 milhões de cores. Já o GIF suporta apenas uma paleta de 256 cores (8 bits).

    JPEG é mais adequado para fotografias e imagens com muitos detalhes e gradientes de cores suaves.

###  3) Quais as etapas de  do processo de codificação de um JPEG?

    Conversão de cor: A imagem RGB é convertida para o espaço de cores YCbCr, onde Y representa a luminosidade, e Cb e Cr representam as informações de cor (crominância).

    Subamostragem de crominância: Como o olho humano é mais sensível à variação de luminosidade do que à variação de cor, as componentes de cor (Cb e Cr) são sub amostradas para reduzir a quantidade de dados.

    Divisão em blocos: A imagem é dividida em blocos de 8x8 pixels para que possam ser processados individualmente.
    Transformada Discreta de Cosseno (DCT): Cada bloco de 8x8 pixels passa pela DCT, que converte as informações espaciais dos pixels em frequências, separando os detalhes de alta e baixa frequência.

    Quantização: A etapa de quantização reduz a precisão dos valores das frequências, principalmente nas frequências mais altas (onde as variações são menos perceptíveis ao olho humano). Isso é o que leva à compressão com perda de qualidade.

    Codificação: Após a quantização, os coeficientes de frequência são organizados em um formato de codificação eficiente usando algoritmos como Huffman ou RLE (Run-Length Encoding) para comprimir ainda mais os dados.

###  4) Em que situações é preferível a utilização de GIF a JPEG?

	Imagens com poucas cores: Como o GIF suporta até 256 cores, ele é mais adequado para imagens que não exigem alta profundidade de cor, como logotipos, gráficos simples ou desenhos.

    Animações: O formato GIF suporta animações, tornando-o ideal para imagens animadas simples na web.

    Imagens com transparência: O GIF pode armazenar informações de transparência (em 1 bit, ou seja, transparente ou opaco), o que é útil para ícones ou imagens que precisam se sobrepor a diferentes fundos.