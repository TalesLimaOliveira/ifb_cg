#include <stdlib.h>
#include <GL/glut.h>
#include "drawing.h"

void keyboardCallback(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // ESC
            exit(0);
            break;
        case 'q':
            px -= 0.25; py += 0.25;
            break;
        case 'a':
            px += 0.25; py -= 0.25;
            break;
        case 'e':
            px += 0.25; py += 0.25;
            break;
        case 'd':
            px -= 0.25; py -= 0.25;
            break;
    }
    glutPostRedisplay();
}

void specialKeysCallback(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_PAGE_UP:
            angulo += 0.2;
            break;
        case GLUT_KEY_PAGE_DOWN:
            angulo -= 0.5;
            break;
        case GLUT_KEY_UP:
            ty += 0.2;
            break;
        case GLUT_KEY_DOWN:
            ty -= 0.2;
            break;
        case GLUT_KEY_RIGHT:
            tx += 0.2;
            break;
        case GLUT_KEY_LEFT:
            tx -= 0.2;
            break;
        case GLUT_KEY_HOME:
            left -= 0.25; right += 0.25;
            bot -= 0.25; top += 0.25;
            break;
        case GLUT_KEY_END:
            left += 0.25; right -= 0.25;
            bot += 0.25; top -= 0.25;
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
