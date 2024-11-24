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
    (void)x; (void)y; // Supress unused variable warnings

    switch (key) {
        case 27: // ESC key
            exit(0);
        case 'r':
        case 'R':
            houses[selectedInstance] = Instance();
            break;
        case 'w':
        case 'W':
            houses[selectedInstance].incrementTranslationY();
            break;
        case 'a':
        case 'A':
            houses[selectedInstance].decrementTranslationX();
            break;
        case 's':
        case 'S':
            houses[selectedInstance].decrementTranslationY();
            break;
        case 'd':
        case 'D':
            houses[selectedInstance].incrementTranslationX();
            break;
        case 'q':
        case 'Q':
            houses[selectedInstance].incrementAngle();
            break;
        case 'e':
        case 'E':
            houses[selectedInstance].decrementAngle();
            break;
        case 'c':
        case 'C':
            {
                Instance newHouse;
                houses.push_back(newHouse);
                selectedInstance = houses.size() - 1;
            }
            break;
        case 'f':
        case 'F':
            houses[selectedInstance].incrementScaleX();
            houses[selectedInstance].incrementScaleY();
            break;
        case 'g':
        case 'G':
            houses[selectedInstance].decrementScaleX();
            houses[selectedInstance].decrementScaleY();
            break;
    }

    glutPostRedisplay();
}

/**
 * @brief Handles special keyboard input (arrow keys, function keys, etc.).
 * @param key The special key pressed.
 * @param x The x-coordinate of the mouse when the key was pressed.
 * @param y The y-coordinate of the mouse when the key was pressed.
 */
void handleSpecialKeys(int key, int x, int y) {
    (void)x; (void)y; // Supress unused variable warnings

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
            if (selectedInstance >= static_cast<int>(houses.size()))
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
        case GLUT_KEY_INSERT:
            houses[selectedInstance] = Instance();
            break;
    }

    glutPostRedisplay();
}