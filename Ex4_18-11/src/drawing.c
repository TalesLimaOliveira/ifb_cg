#include <GL/glut.h>
#include "drawing.h"

double tx = 0, ty = 0, angulo = 0, px = 0, py = 0;
double left = -1.0, right = 1.0, bot = -1.0, top = 1.0;
// double zoom = 50.0;

void drawHouse() {
    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1); glVertex2f(-0.25f, 0.1f);
        glColor3f(1, 0, 0); glVertex2f(0.0, 0.25);
        glColor3f(0, 0, 1); glVertex2f(0.25f, 0.1f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.25, -0.2);
        glVertex2f(-0.25,  0.1);
        glVertex2f( 0.25,  0.1);
        glVertex2f( 0.25, -0.2);
    glEnd();
}

void drawCross() {
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glColor3f(0, 0, 0);
    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2f(0, 1); glVertex2f(0, -1);
        glVertex2f(-1, 0); glVertex2f(1, 0);
    glEnd();
}

void displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        gluPerspective(zoom, 1.0, 1.0, 100.0);
        gluOrtho2D(left+px, right+px, bot+py, top+py);
        glTranslatef(tx, ty, 0);
        glRotatef(angulo, 0, 0, 1);

        drawHouse();
    glPopMatrix();

    drawCross();

    glFlush();
}
