#include <GL/glut.h>
#include <drawing.h>

extern double translationX, translationY, scaleX, scaleY;
extern double angulo, left, right, bot, top;

/**
 * @brief Draws a house.
 */
void drawHouse() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.2f,  0.1f);
        glVertex2f( 0.2f,  0.1f);
        glVertex2f( 0.2f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.2f, 0.1f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 0.25f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.2f, 0.1f);
    glEnd();
}

/**
 * @brief Draws a cross.
 */
void drawCross() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(1.0f);

    glBegin(GL_LINES);
        glVertex2f(0.0f, top); glVertex2f(0.0f, bot);
        glVertex2f(left, 0.0f); glVertex2f(right, 0.0f);
    glEnd();
}

/**
 * @brief The display callback function.
 */
void display() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix(); // Corrected order of glPushMatrix and glPopMatrix
        drawCross();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(translationX, translationY, 0.0f);
        glScalef(scaleX, scaleY, 1.0f);
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        drawHouse();
    glPopMatrix();

    glFlush();
}
