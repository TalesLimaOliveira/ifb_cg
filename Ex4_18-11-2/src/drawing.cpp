#include <GL/glut.h>
#include "drawing.h"

double cima = 1.0f, baixo = -1.0f, direita = 1.0f, esquerda = -1.0f;
double tx = 0, ty = 0, angulo = 0, px = 0, py = 0;

void desenha(void) {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glLoadIdentity();
        desenhaEixos();
    glPopMatrix();

    glPushMatrix();
        glLoadIdentity();
        glTranslatef(tx, ty, 0);
        glRotatef(angulo, 0, 0, 1);
        desenhaCasinha();
    glPopMatrix();

    glFlush();
}


void desenhaCasinha() {
    glLineWidth(3);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, 0.1f);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.2f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.2f, 0.1f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 0.22f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.2f, 0.1f);
    glEnd();
}

void desenhaEixos() {
    glColor3f(1, 1, 1);
    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2f(esquerda, 0.0); glVertex2f(direita, 0.0);
        glVertex2f(0.0, baixo); glVertex2f(0.0, cima);
    glEnd();
}