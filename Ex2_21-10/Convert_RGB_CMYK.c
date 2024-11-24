/**
 * @file CG_2_1.c
 * @author Tales Oliveira (github.com/TalesLimaOliveira)
 * @date 2024-10-21
 *
 * @brief Converts RGB values to CMYK
 */

#include <stdio.h>

// Define the values for R G B
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
