#ifndef DRAW_H
#define DRAW_H

/**
 * @brief Draws the coordinate axes.
 */
void drawAxes();

/**
 * @brief Draws a house.
 */
void drawHouse();

/**
 * @brief Displays the scene.
 */
void display();

/**
 * @brief Draws text on the screen.
 * @param font The font to use.
 * @param string The string to draw.
 */
void drawText(void *font, char *string);

#endif // DRAW_H