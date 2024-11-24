#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include <keyboard.h>
#include <instance.h>

extern double left, right, top, bottom;
extern std::vector<Instance> houses;
extern int selectedInstance;

void keyboard(unsigned char key, int x, int y) {
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
        case '1':
            selectedInstance--;
            if (selectedInstance < 0)
                selectedInstance = houses.size() - 1;
            break;
        case '3':
            selectedInstance++;
            if (selectedInstance >= static_cast<int>(houses.size()))
                selectedInstance = 0;
            break;
    }

    glutPostRedisplay();
}


void keyboardSpecial(int key, int x, int y) {
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