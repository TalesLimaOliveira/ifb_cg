#include <GL/glut.h>
#include <drawing.h>
#include <colors.h>

extern double translationX, translationY, scaleX, scaleY;
extern double angulo, left, right, bot, top;

/**
 * @brief Draws a house.
 */
void drawHouse(){
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(WHITE.r, WHITE.g, WHITE.b);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.2f,  0.1f);
        glVertex2f( 0.2f,  0.1f);
        glVertex2f( 0.2f, -0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(RED.r, RED.g, RED.b); glVertex2f(-0.2f, 0.1f);
        glColor3f(GREEN.r, GREEN.g, GREEN.b); glVertex2f(0.0f, 0.25f);
        glColor3f(BLUE.r, BLUE.g, BLUE.b); glVertex2f(0.2f, 0.1f);
    glEnd();
}

/**
 * @brief Draws a cross.
 */
void drawCross(){
    glColor3f(WHITE.r, WHITE.g, WHITE.b);
    glLineWidth(1.0f);

    glBegin(GL_LINES);
        glVertex2f(0.0f, top); glVertex2f(0.0f, bot);
        glVertex2f(left, 0.0f); glVertex2f(right, 0.0f);
    glEnd();
}

/**
 * @brief Draws the help bar at the bottom of the screen.
 */
void drawHelpBar() {
    glColor3f(WHITE.r, WHITE.g, WHITE.b);
    glRasterPos2f(left + 0.05f, bot + 0.05f);
    const char* helpText = "[ESC] Exit | [I] Reset | [M] Mirror | [T] Translate | [R] Rotate | [S] Scale";
    for (const char* c = helpText; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

/**
 * @brief The display callback function.
 */
void display(){
    glClearColor(BG.r, BG.g, BG.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        drawCross();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(translationX, translationY, 0.0f);
        glScalef(scaleX, scaleY, 1.0f);
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        drawHouse();
    glPopMatrix();

    drawHelpBar();

    glFlush();
}
