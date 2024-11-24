#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <keyboard.h>
#include <instance.h>

extern float translationX, translationY;
extern float left, right, top, bottom, panX, panY;
extern std::vector<Instance> houses;
extern int selectedInstance;

/**
 * @brief Handles standard keyboard input.
 * @param key The key pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void handleKeyboard(unsigned char key, int x, int y) {
    if (key == 27) // ESC key
        exit(0);
}

/**
 * @brief Handles special keyboard input (arrow keys, function keys, etc.).
 * @param key The special key pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            houses[selectedInstance].decrementTranslationX();
            break;
        case GLUT_KEY_RIGHT:
            houses[selectedInstance].incrementTranslationX();
            break;
        case GLUT_KEY_UP:
            houses[selectedInstance].incrementTranslationY();
            break;
        case GLUT_KEY_DOWN:
            houses[selectedInstance].decrementTranslationY();
            break;
        case GLUT_KEY_PAGE_DOWN:
            selectedInstance--;
            if (selectedInstance < 0)
                selectedInstance = houses.size() - 1;
            break;
        case GLUT_KEY_PAGE_UP:
            selectedInstance++;
            if (selectedInstance >= houses.size())
                selectedInstance = 0;
            break;
        case GLUT_KEY_F1:
            {
                Instance newHouse;
                houses.push_back(newHouse);
                selectedInstance = houses.size() - 1;
            }
            break;
        case GLUT_KEY_F2:
            houses[selectedInstance].incrementAngle();
            break;
        case GLUT_KEY_F3:
            houses[selectedInstance].decrementAngle();
            break;
        case GLUT_KEY_F5:
            houses[selectedInstance].incrementScaleX();
            houses[selectedInstance].incrementScaleY();
            break;
        case GLUT_KEY_F6:
            houses[selectedInstance].decrementScaleX();
            houses[selectedInstance].decrementScaleY();
            break;
    }

    glutPostRedisplay();
}