#ifndef DRAWING_H
#define DRAWING_H

/**
 * @brief Draws a house.
 */
void drawHouse();
void drawHouse2();

void drawCircle(float cx, float cy, float radius, int segments);

/**
 * @brief Draws a cross.
 */
void drawCross();

/**
 * @brief The display callback function.
 */
void display();

/**
 * @brief Draws the help bar at the bottom of the screen.
 */
void drawHelpBar();

#endif // DRAWING_H