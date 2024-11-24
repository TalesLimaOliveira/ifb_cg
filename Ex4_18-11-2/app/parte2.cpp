#include <GL/glut.h>
#include <vector>
#include "draw.h"
#include "keyboard.h"
#include "instancia.h"

float translationX = 0, translationY = 0, panX = 0, panY = 0;
float left  = -1.0f, right = 1.0f, top = 1.0f, bottom  = -1.0f;

std::vector<Instancia> houses;
int selectedInstance = 0;

/**
 * @brief Initializes the OpenGL settings and creates the initial house instance.
 */
void initialize() {
    // Define the 2D viewing window
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(left + panX, right + panX, bottom + panY, top + panY);
    glMatrixMode(GL_MODELVIEW);

    Instancia house;
    houses.push_back(house);
}

/**
 * @brief Main function to set up the OpenGL environment and start the main loop.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return Exit status.
 */
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(15,15);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D House Drawing");

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutSpecialFunc(handleSpecialKeys);

    initialize();
    glutMainLoop();
    return 0;
}