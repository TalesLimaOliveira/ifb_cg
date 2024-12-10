#ifndef DRAWING_H
#define DRAWING_H

/**
 * @brief Draws a house.
 */
void drawHouse();

/**
 * @brief Draws a Circle.
 * @param cx The x-coordinate of the center of the circle.
 * @param cy The y-coordinate of the center of the circle.
 * @param radius The radius of the circle.
 * @param segments The number of segments used to draw the circle.
 */
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