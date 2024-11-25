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
void keyboard(unsigned char key, int x, int y){
    (void)x; (void)y;

    switch (key){
    case 27: //ESC - Exit the program
        exit(0); break;

    // Reset to center
    case 'i': case 'I':
        translationX = translationY = angulo = 0.0;
        left = bot = -1.0; right = top = 1.0;
        scaleX = scaleY = 1.0;
        currentMode = NONE;
        break;
    
    case 'm': case 'M':
        scaleX = -scaleX;
        currentMode = NONE;
        break;

    // Change mode
    case 't': case 'T':
        currentMode = TRANSLATE; break;

    case 'r': case 'R':
        currentMode = ROTATE; break;

    case 's': case 'S':
        currentMode = SCALE; break;
    }

    glutPostRedisplay();
}

/**
 * @brief Handles keyboard input for special keys.
 * @param key The special key that was pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void keyboardSpecial(int key, int x, int y){
    (void)x; (void)y;
    
    switch (key){
    case GLUT_KEY_UP: 
        if (currentMode == TRANSLATE) // Move up
            if (translationY + 0.2f < top)
                translationY += 0.2f;
        else if (currentMode == ROTATE)// Rotate clockwise
            angulo += 0.5;
        else if (currentMode == SCALE) // Scale up
            scaleX += 0.1; scaleY += 0.1;
        break;

    case GLUT_KEY_DOWN:
        if (currentMode == TRANSLATE) // Move down
            if (translationY - 0.2f > bot)
                translationY -= 0.2f;
        else if (currentMode == ROTATE) // Rotate counter-clockwise
            angulo -= 0.5;
        else if (currentMode == SCALE) // Scale down
            scaleX -= 0.1; scaleY -= 0.1;
        break;

    case GLUT_KEY_RIGHT:
        if (currentMode == TRANSLATE){ // Move right
            if (translationX + 0.2f < right)
                translationX += 0.2f;
        }
        break;
    case GLUT_KEY_LEFT:
        if (currentMode == TRANSLATE) // Move left
            if (translationX - 0.2f > left)
                translationX -= 0.2f;
        break;
    }
    
    glutPostRedisplay();
}
