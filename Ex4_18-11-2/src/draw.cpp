#include <GL/glut.h>
#include <vector>
#include <string>
#include <draw.h>
#include "instance.h"

extern double left, right, top, bottom, panX, panY;
extern std::vector<Instance> houses;
extern int selectedInstance;

void drawAxes() {
    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex2f(left, 0.0f);
        glVertex2f(right, 0.0f);
        glVertex2f(0.0f, bottom);
        glVertex2f(0.0f, top);
    glEnd();
}


void drawHouse() {
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

void drawText(void *font, const char *string) {
    while(*string) glutBitmapCharacter(font, *string++);
}

void display() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left + panX, right + panX, bottom + panY, top + panY);
    glMatrixMode(GL_MODELVIEW);

    // Clear the window with gray bgc
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        drawAxes();
    glPopMatrix();

    // Apply geometric transformations and display the house instances
    for (int i = 0; i < static_cast<int>(houses.size()); i++) {
        glPushMatrix();
            glTranslatef(houses[i].getTranslationX(), houses[i].getTranslationY(), 0.0f);
            glScalef(houses[i].getScaleX(), houses[i].getScaleY(), 1.0f);
            glRotatef(houses[i].getAngle(), 0.0f, 0.0f, 1.0f);
            if (selectedInstance == i)
                glColor3f(1.0f, 1.0f, 1.0f);
            else
                glColor3f(0.0f, 0.0f, 1.0f);

            drawHouse();

            // Draw instance number inside the house
            glColor3f(0.0f, 0.0f, 0.0f);
            glRasterPos2f(-0.0125f, -0.05f);
            std::string instanceNumber = std::to_string(i+1);
            drawText(GLUT_BITMAP_TIMES_ROMAN_24, instanceNumber.c_str());
        glPopMatrix();
    }

    // // Draw text
    // glPushMatrix();
    //     glTranslatef(0.0f, 0.0f, 0.0f);
    //     glScalef(0.2f, 0.2f, 0.2f);
    //     glRasterPos2f(0.5, 0.5);
    //     drawText(GLUT_BITMAP_TIMES_ROMAN_24, "TEXT TEST");
    // glPopMatrix();

    glutSwapBuffers();
    glFlush();
}