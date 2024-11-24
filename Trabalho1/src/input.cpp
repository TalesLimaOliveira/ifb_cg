#include <stdlib.h>
#include <GL/glut.h>
#include "drawing.h"

// Define os limites para o movimento
const double moveLimitX = 1.0f;
const double moveLimitY = 1.0f;

void keyboardCallback(unsigned char key, int x, int y) {
    (void)x; (void)y;
    switch (key) {
        case 27: // ESC
            exit(0); break;

        case 'q': // Movimento diagonal (superior esquerda)
            if (px + 0.25 < moveLimitX && py - 0.25 > -moveLimitY) {
                px += 0.25; py -= 0.25;
            }
            break;
        case 'a': // Movimento diagonal (inferior esquerda)
            if (px + 0.25 < moveLimitX && py + 0.25 < moveLimitY) {
                px += 0.25; py += 0.25;
            }
            break;
        case 'e': // Movimento diagonal (superior direita)
            if (px - 0.25 > -moveLimitX && py - 0.25 > -moveLimitY) {
                px -= 0.25; py -= 0.25;
            }
            break;
        case 'd': // Movimento diagonal (inferior direita)
            if (px - 0.25 > -moveLimitX && py + 0.25 < moveLimitY) {
                px -= 0.25; py += 0.25;
            }
            break;
    }

    glutPostRedisplay();
}

void specialKeysCallback(int key, int x, int y) {
    (void)x; (void)y;
    switch (key) {
        case GLUT_KEY_PAGE_UP: // Rotação para a esquerda
            angulo += 0.5; break;
        case GLUT_KEY_PAGE_DOWN: // Rotação para a direita
            angulo -= 0.5; break;


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


        case GLUT_KEY_HOME: // Zoom out
            left += 0.1; right -= 0.1;
            top -= 0.1; bot += 0.1;
            break;
        
        case GLUT_KEY_END: // Zoom in
            left-=0.1; right+=0.1;
            top+=0.1; bot-=0.1;
            break;


        case GLUT_KEY_F9: // Pan para a direita
            px += 0.1;
            break;
        case GLUT_KEY_F10: // Pan para a esquerda
            px -= 0.1;
            break;
        case GLUT_KEY_F11: // Pan para cima
            py += 0.1;
            break;
        case GLUT_KEY_F12: // Pan para baixo
            py -= 0.1;
            break;

        case GLUT_KEY_INSERT: // Reset para o centro
            tx = ty = px = py = angulo = 0;
            left = bot = -1.0; right = top = 1.0;
            break;
    }
    
    glutPostRedisplay();
}

void reshapeCallback(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glLoadIdentity();

    // Verifica a relação de aspecto da tela para ajustar a projeção ortográfica
    if (w <= h)
        gluOrtho2D(left, right, bot, bot + (right - left) * h / w);
    else
        gluOrtho2D(left, left + (right - left) * w / h, bot, top);
}
