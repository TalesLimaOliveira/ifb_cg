#ifndef KEYBOARD_H
#define KEYBOARD_H

extern double tx, ty, angulo, left, right, top, bot;
enum Mode {NONE, TRANSLATE, ROTATE, SCALE};

extern Mode currentMode;

/**
 * @brief Handles keyboard input for standard keys.
 * @param key The key that was pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboard(unsigned char key, int x, int y);

/**
 * @brief Handles keyboard input for special keys.
 * @param key The special key that was pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboardSpecial(int key, int x, int y);

#endif // KEYBOARD_H