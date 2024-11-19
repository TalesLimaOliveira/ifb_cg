#include <GL/glut.h>
#include "drawing.h"

double tx = 0, ty = 0, angulo = 0, px = 0, py = 0;
double left = -1.0, right = 1.0, bot = -1.0, top = 1.0;
// double zoom = 50.0;

void drawHouse() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2, -0.2);
        glVertex2f(-0.2,  0.1);
        glVertex2f( 0.2,  0.1);
        glVertex2f( 0.2, -0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0, 0, 1); glVertex2f(-0.2, 0.1);
        glColor3f(1, 0, 0); glVertex2f(0.0, 0.25);
        glColor3f(0, 0, 1); glVertex2f(0.2, 0.1);
    glEnd();
}

void drawCross() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(1);

    glBegin(GL_LINES);
        glVertex2f(0, top); glVertex2f(0, bot);
        glVertex2f(left, 0); glVertex2f(right, 0);
    glEnd();
}

void displayCallback() {
    glClearColor(0.5, 0.5, 0.5, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        glLoadIdentity();
        drawCross();
    glPopMatrix();

    glPushMatrix();
        glLoadIdentity();
        glTranslatef(tx, ty, 0);
        glRotatef(angulo, 0, 0, 1);
        drawHouse();
    glPopMatrix();

    glFlush();
}
