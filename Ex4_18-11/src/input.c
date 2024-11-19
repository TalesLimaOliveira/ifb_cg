#include <stdlib.h>
#include <GL/glut.h>
#include "drawing.h"

// Define os limites para o movimento
const double moveLimitX = 1.0;
const double moveLimitY = 1.0;

// Limites do zoom
const double zoomLimitMin = 0.5;  // Limite mínimo de zoom
const double zoomLimitMax = 2.0;   // Limite máximo de zoom

void keyboardCallback(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // ESC
            exit(0);
            break;

        case 'q': // Movimento diagonal (superior esquerda)
            if (px + 0.25 < moveLimitX && py - 0.25 > -moveLimitY) {
                px += 0.25;
                py -= 0.25;
            }
            break;
        case 'a': // Movimento diagonal (inferior esquerda)
            if (px + 0.25 < moveLimitX && py + 0.25 < moveLimitY) {
                px += 0.25;
                py += 0.25;
            }
            break;
        case 'e': // Movimento diagonal (superior direita)
            if (px - 0.25 > -moveLimitX && py - 0.25 > -moveLimitY) {
                px -= 0.25;
                py -= 0.25;
            }
            break;
        case 'd': // Movimento diagonal (inferior direita)
            if (px - 0.25 > -moveLimitX && py + 0.25 < moveLimitY) {
                px -= 0.25;
                py += 0.25;
            }
            break;
    }
    glutPostRedisplay();
}

void specialKeysCallback(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_PAGE_UP: // Rotação para a esquerda
            angulo += 0.5;
            break;
        case GLUT_KEY_PAGE_DOWN: // Rotação para a direita
            angulo -= 0.5;
            break;

        case GLUT_KEY_UP: // Movimento para cima
            if (ty + 0.2 < moveLimitY) {
                ty += 0.2;
            }
            break;
        case GLUT_KEY_DOWN: // Movimento para baixo
            if (ty - 0.2 > -moveLimitY) {
                ty -= 0.2;
            }
            break;
        case GLUT_KEY_RIGHT: // Movimento para a direita
            if (tx + 0.2 < moveLimitX) {
                tx += 0.2;
            }
            break;
        case GLUT_KEY_LEFT: // Movimento para a esquerda
            if (tx - 0.2 > -moveLimitX) {
                tx -= 0.2;
            }
            break;

        case GLUT_KEY_HOME: // Zoom in
            if ((right - left) > zoomLimitMin * 2) { // Verifica se o zoom não ultrapassa o limite mínimo
                left -= 0.25;
                right += 0.25;
                bot -= 0.25;
                top += 0.25;
            }
            break;
        case GLUT_KEY_END: // Zoom out
            if ((right - left) < zoomLimitMax * 2) { // Verifica se o zoom não ultrapassa o limite máximo
                left += 0.25;
                right -= 0.25;
                bot += 0.25;
                top -= 0.25;
            }
            break;

        case GLUT_KEY_INSERT: // Reset para o centro
            tx = 0;
            ty = 0;
            px = 0;
            py = 0;
            angulo = 0;
            left = -1.0;
            right = 1.0;
            bot = -1.0;
            top = 1.0;
            break;
    }
    glutPostRedisplay();
}

void reshapeCallback(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glLoadIdentity();

    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}
