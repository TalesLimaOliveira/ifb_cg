#include <GL/glut.h>
#include "drawing.h"
#include "colors.h"
#include "keyboard.h"

extern double translationX, translationY, scaleX, scaleY;
extern double angulo, left, right, bot, top;
extern Mode currentMode;

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
    const char* helpText1[] = {"[ESC] Exit", "[I] Reset", "[M] Mirror"};
    const char* helpText2[] = {"[T] Translate", "[R] Rotate", "[S] Scale"};
    Color helpColors[] = {WHITE, WHITE, WHITE};
    Color modeColors[] = {WHITE, WHITE, WHITE};

    // Change color of the selected mode
    switch (currentMode) {
        case TRANSLATE:
            modeColors[0] = GREEN; break;
        case ROTATE:
            modeColors[1] = GREEN; break;
        case SCALE:
            modeColors[2] = GREEN; break;
        case NONE: 
            modeColors[0] = WHITE;
            modeColors[1] = WHITE;
            modeColors[2] = WHITE; break;
        default: break;
    }

    // Change color of the mirror text if mirrored
    if (isMirrored) {
        helpColors[2] = GREEN;
    }

    // Draw help texts
    float offset = 0.0f;
    for (int i = 0; i < 3; i++) {
        glColor3f(helpColors[i].r, helpColors[i].g, helpColors[i].b);
        glRasterPos2f(left + 0.05f + offset, bot + 0.1f);
        for (const char* c = helpText1[i]; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
        offset += 0.2f;
    }

    // Draw mode texts with respective colors
    offset = 0.0f;
    for (int i = 0; i < 3; i++) {
        glColor3f(modeColors[i].r, modeColors[i].g, modeColors[i].b);
        glRasterPos2f(left + 0.05f + offset, bot + 0.05f);
        for (const char* c = helpText2[i]; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
        offset += 0.2f;
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
