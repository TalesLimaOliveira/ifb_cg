#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>
#include "drawing.h"
#include "colors.h"
#include "keyboard.h"

extern double translationX, translationY, scaleX, scaleY;
extern double angulo, left, right, bot, top;
extern Mode currentMode;
extern bool isMirrored, isAxesVisible;


/**
 * @brief Draws the house.
 */
void drawHouse(){
    // Draw the front base
    glColor3f(HOUSE_BASE_FRONT.r, HOUSE_BASE_FRONT.g, HOUSE_BASE_FRONT.b);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f); // BOT LEFT
        glVertex2f(-0.5f,  0.5f); // TOP LEFT
        glVertex2f( 0.5f,  0.5f); // TOP RIGHT
        glVertex2f( 0.5f, -0.5f); // BOT RIGHT
    glEnd();

    // Draw the front roof
    glColor3f(HOUSE_ROOF_FRONT.r, HOUSE_ROOF_FRONT.g, HOUSE_ROOF_FRONT.b);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f,  0.5f); // BOT LEFT
        glVertex2f( 0.0f,  1.0f); // TOP CENTER
        glVertex2f( 0.5f,  0.5f); // BOT RIGHT
    glEnd();

    // Draw the circular window on the front roof
    glColor3f(HOUSE_WINDOW_FRONT.r, HOUSE_WINDOW_FRONT.g, HOUSE_WINDOW_FRONT.b);
    drawCircle(0.0f, 0.75f, 0.1f, 50);

    // Draw the side base
    glColor3f(HOUSE_BASE_SIDE.r, HOUSE_BASE_SIDE.g, HOUSE_BASE_SIDE.b);
    glBegin(GL_QUADS);
        glVertex2f( 0.5f, -0.5f); // BOT LEFT
        glVertex2f( 0.5f,  0.5f); // TOP LEFT
        glVertex2f( 1.5f,  0.6f); // TOP RIGHT
        glVertex2f( 1.5f, -0.4f); // BOT RIGHT
    glEnd();

    // Draw the square window on the side base
    glColor3f(HOUSE_WINDOW_SIDE.r, HOUSE_WINDOW_SIDE.g, HOUSE_WINDOW_SIDE.b);
    glBegin(GL_QUADS);
        glVertex2f( 0.9f, -0.1f); // BOT LEFT
        glVertex2f( 0.9f,  0.2f); // TOP LEFT
        glVertex2f( 1.2f,  0.2f); // TOP RIGHT
        glVertex2f( 1.2f, -0.1f); // BOT RIGHT
    glEnd();

    // Draw the side roof
    glColor3f(HOUSE_ROOF_SIDE.r, HOUSE_ROOF_SIDE.g, HOUSE_ROOF_SIDE.b);
    glBegin(GL_QUADS);
        glVertex2f( 0.5f,  0.5f); // BOT LEFT
        glVertex2f( 0.0f,  1.0f); // TOP LEFT
        glVertex2f( 1.25f, 1.1f); // TOP RIGHT
        glVertex2f( 1.5f,  0.6f); // BOT RIGHT
    glEnd();
}

/**
 * @brief Draws a Circle.
 * @param cx The x-coordinate of the center of the circle.
 * @param cy The y-coordinate of the center of the circle.
 * @param radius The radius of the circle.
 * @param segments The number of segments used to draw the circle.
 */
void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
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
