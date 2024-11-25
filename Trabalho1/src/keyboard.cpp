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
        case 27: // ESC
            exit(0); break;

        case 'q': case 'Q': // Diagonal movement (upper left)
            if (px + 0.25f < right && py - 0.25f > bot) {
                px += 0.25f; py -= 0.25f;
            }
            break;
        case 'a': case 'A': // Diagonal movement (lower left)
            if (px + 0.25f < right && py + 0.25f < top) {
                px += 0.25f; py += 0.25f;
            }
            break;
        case 'e': case 'E': // Diagonal movement (upper right)
            if (px - 0.25f > left && py - 0.25f > bot) {
                px -= 0.25f; py -= 0.25f;
            }
            break;
        case 'd': case 'D': // Diagonal movement (lower right)
            if (px - 0.25f > left && py + 0.25f < top) {
                px -= 0.25f; py += 0.25f;
            }
            break;
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
        case GLUT_KEY_PAGE_UP: // Rotate left
            angulo += 0.5; break;
        case GLUT_KEY_PAGE_DOWN: // Rotate right
            angulo -= 0.5; break;

        case GLUT_KEY_UP: // Move up
            if (currentMode == TRANSLATE) {
                if (ty + 0.2f < top) ty += 0.2f;
            } else if (currentMode == ROTATE) {
                angulo += 0.5;
            } else if (currentMode == SCALE) {
                top += 0.1; bot -= 0.1; left -= 0.1; right += 0.1;
            }
            break;
        case GLUT_KEY_DOWN: // Move down
            if (currentMode == TRANSLATE) {
                if (ty - 0.2f > bot) ty -= 0.2f;
            } else if (currentMode == ROTATE) {
                angulo -= 0.5;
            } else if (currentMode == SCALE) {
                top -= 0.1; bot += 0.1; left += 0.1; right -= 0.1;
            }
            break;
        case GLUT_KEY_RIGHT: // Move right
            if (currentMode == TRANSLATE) {
                if (tx + 0.2f < right) tx += 0.2f;
            }
            break;
        case GLUT_KEY_LEFT: // Move left
            if (currentMode == TRANSLATE) {
                if (tx - 0.2f > left) tx -= 0.2f;
            }
            break;

        case GLUT_KEY_HOME: // Zoom out
            left += 0.1; right -= 0.1;
            top -= 0.1; bot += 0.1;
            break;
        
        case GLUT_KEY_END: // Zoom in
            left -= 0.1; right += 0.1;
            top += 0.1; bot -= 0.1;
            break;

        case GLUT_KEY_F9: // Pan right
            px += 0.1;
            break;
        case GLUT_KEY_F10: // Pan left
            px -= 0.1;
            break;
        case GLUT_KEY_F11: // Pan up
            py += 0.1;
            break;
        case GLUT_KEY_F12: // Pan down
            py -= 0.1;
            break;

        case GLUT_KEY_INSERT: // Reset to center
            tx = ty = px = py = angulo = 0;
            left = bot = -1.0; right = top = 1.0;
            break;
    }
    
    glutPostRedisplay();
}
