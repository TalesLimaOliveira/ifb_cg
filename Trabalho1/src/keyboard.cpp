#include <stdlib.h>
#include <GL/glut.h>
#include <drawing.h>
#include <keyboard.h>

Mode currentMode = NONE;

/**
 * @brief Handles keyboard input for standard keys.
 * @param key The key that was pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboard(unsigned char key, int x, int y) {
    (void)x; (void)y;

    switch (key) {
        // Exit the program
        case 27: //ESC
            exit(0); break;

        // Reset to center
        case 'i': case 'I':
            tx = ty = angulo = 0;
            left = bot = -1.0;
            right = top = 1.0;
            break;

        // Change mode
        case 't': case 'T':
            currentMode = TRANSLATE;
            break;
        case 'r': case 'R':
            currentMode = ROTATE;
            break;
        case 's': case 'S':
            currentMode = SCALE;
            break;
    }

    glutPostRedisplay();
}

/**
 * @brief Handles keyboard input for special keys.
 * @param key The special key that was pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboardSpecial(int key, int x, int y) {
    (void)x; (void)y;
    
    switch (key) {


        case GLUT_KEY_UP: 
            if (currentMode == TRANSLATE) { // Move up
                if (ty + 0.2f < top) ty += 0.2f;
            } else if (currentMode == ROTATE) { // Rotate clockwise
                angulo += 0.5;
            } else if (currentMode == SCALE) { // Scale up
                top += 0.1; bot -= 0.1; left -= 0.1; right += 0.1;
            }
            break;

        case GLUT_KEY_DOWN:
            if (currentMode == TRANSLATE) { // Move down
                if (ty - 0.2f > bot) ty -= 0.2f;
            } else if (currentMode == ROTATE) { // Rotate counter-clockwise
                angulo -= 0.5;
            } else if (currentMode == SCALE) { // Scale down
                top -= 0.1; bot += 0.1; left += 0.1; right -= 0.1;
            }
            break;

        case GLUT_KEY_RIGHT:
            if (currentMode == TRANSLATE){ // Move right
                if (tx + 0.2f < right) tx += 0.2f;
            }
            break;
        case GLUT_KEY_LEFT:
            if (currentMode == TRANSLATE){ // Move left
                if (tx - 0.2f > left) tx -= 0.2f;
            }
            break;
    }
    
    glutPostRedisplay();
}
