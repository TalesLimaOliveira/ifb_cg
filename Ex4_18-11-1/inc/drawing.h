#ifndef DRAWING_H
#define DRAWING_H

extern double tx, ty, angulo;
extern double left, right, bot, top;

/**
 * @brief Draws a house.
 */
void drawHouse();

/**
 * @brief Draws a cross.
 */
void drawCross();

/**
 * @brief The display callback function.
 */
void display();

#endif // DRAWING_H