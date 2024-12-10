#include <GL/glut.h>
#include <stdlib.h>
#include "drawing.h"
#include "colors.h"
#include "keyboard.h"

extern double translationX, translationY, scaleX, scaleY;
extern double angulo, left, right, bot, top;
extern Mode currentMode;
extern bool isMirrored, isAxesVisible;

/**
 * @brief Draws a house.
 */
void drawHouse(){
    // BASE
    glBegin(GL_QUADS);
        glColor3f(HOUSE.r, HOUSE.g, HOUSE.b);
        glVertex2f(-0.4f, -0.4f); // BOT LEFT
        glVertex2f(-0.4f,  0.2f); // TOP LEFT
        glVertex2f( 0.4f,  0.2f); // TOP RIGHT
        glVertex2f( 0.4f, -0.4f); // BOT RIGHT
    glEnd();

    // ROOF
    glBegin(GL_TRIANGLES);
        glColor3f(RED.r, RED.g, RED.b); glVertex2f(-0.4f, 0.2f);        // BOT LEFT
        glColor3f(GREEN.r, GREEN.g, GREEN.b); glVertex2f(0.0f, 0.5f);   // TOP CENTER
        glColor3f(BLUE.r, BLUE.g, BLUE.b); glVertex2f(0.4f, 0.2f);      // BOT RIGHT
    glEnd();

    // DOOR
    glBegin(GL_QUADS);
        glColor3f(INSIDE.r, INSIDE.g, INSIDE.b);
        glVertex2f(-0.3f, -0.36f); // BOT LEFT
        glVertex2f(-0.3f, 0.0f);  // TOP LEFT
        glVertex2f(-0.1f, 0.0f);  // TOP RIGHT
        glVertex2f(-0.1f, -0.36f); // BOT RIGHT
    glEnd();

    // WINDOW
    glBegin(GL_QUADS);
        glColor3f(INSIDE.r, INSIDE.g, INSIDE.b);
        glVertex2f(0.1f, -0.15f); // BOT LEFT
        glVertex2f(0.1f,  0.0f);  // TOP LEFT
        glVertex2f(0.3f,  0.0f);  // TOP RIGHT
        glVertex2f(0.3f, -0.15f); // BOT RIGHT 
    glEnd();

    // BARS
    glBegin(GL_LINES);
        glColor3f(WHITE.r, WHITE.g, WHITE.b);
        glVertex2f(0.2f, 0.0f); // H TOP
        glVertex2f(0.2f, -0.15f); // H BOT
        glVertex2f(0.1f, -0.075f); // V LEFT
        glVertex2f(0.3f, -0.075f); // V RIGHT
    glEnd();
}

/**
 * @brief Draws a cross for the axis.
 */
void drawAxis(){
    glColor3f(WHITE.r, WHITE.g, WHITE.b);
    glLineWidth(0.5f);

    glBegin(GL_LINES);
        glVertex2f(0.0f, -1.0f); glVertex2f(0.0f, 1.0f); // Vertical line
        glVertex2f(-1.0f, 0.0f); glVertex2f(1.0f, 0.0f); // Horizontal line
    glEnd();
}


/**
 * @brief Draws the help bar at the bottom of the screen.
 */
void drawHelpBar() {
    const char* modeText[] = {"[R] Rotate", "[T] Translate", "[S] Scale"};
    const char* helpText[] = {"[ESC] Exit", "[I] Reset", "[M] Mirror", "[A] Axis"};
    Color modeColors[] = {WHITE, WHITE, WHITE};
    Color helpColors[] = {RED, WHITE, WHITE, WHITE};

    // Change color of the selected mode
    switch (currentMode) {
        case ROTATE:
            modeColors[0] = GREEN; break;
        case TRANSLATE:
            modeColors[1] = GREEN; break;
        case SCALE:
            modeColors[2] = GREEN; break;
        case NONE: 
            modeColors[0] = WHITE;
            modeColors[1] = WHITE;
            modeColors[2] = WHITE; 
            helpColors[2] = WHITE; break;
        default: break;
    }

    // Change color of the mirror text if mirrored
    if (isMirrored){helpColors[2] = BLUE;}
    // Change color of the axes if visible
    if (isAxesVisible){helpColors[3] = BLUE;}
    
    // Draw help texts (BOT)
    float offset = 0.0f;
    for (int i = 0; i < 4; i++) {
        glColor3f(helpColors[i].r, helpColors[i].g, helpColors[i].b);
        glRasterPos2f(left + 0.05f + offset, bot + 0.05f);
        for (const char* c = helpText[i]; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
        offset += 0.5f;
    }

    // Draw mode texts (TOP)
    offset = 0.0f;
    for (int i = 0; i < 3; i++) {
        glColor3f(modeColors[i].r, modeColors[i].g, modeColors[i].b);
        glRasterPos2f(left + 0.05f + offset, bot + 0.15f);
        for (const char* c = modeText[i]; *c != '\0'; c++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
        offset += 0.5f;
    }
}

/**
 * @brief The display callback function.
 */
void display(){
    glClearColor(BACKGROUND.r, BACKGROUND.g, BACKGROUND.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if (isAxesVisible) {
        glPushMatrix();
            drawAxis();
        glPopMatrix();
    }

    glPushMatrix();
        glTranslatef(translationX, translationY, 0.0f);
        glScalef(scaleX, scaleY, 1.0f);
        glRotatef(angulo, 0.0f, 0.0f, 1.0f);
        drawHouse();
    glPopMatrix();
    
    glPushMatrix();
        drawHelpBar();
    glPopMatrix();

    glFlush();
}
