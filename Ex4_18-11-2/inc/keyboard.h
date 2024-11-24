#ifndef KEYBOARD_H
#define KEYBOARD_H

/**
 * @brief Handles standard keyboard input.
 * @param key The key pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboard(unsigned char key, int x, int y);

/**
 * @brief Handles special keyboard input (arrow keys, function keys, etc.).
 * @param key The special key pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboardSpecial(int key, int x, int y);

#endif // KEYBOARD_H