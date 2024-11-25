#include <GL/glut.h>
#include <vector>
#include <draw.h>
#include <keyboard.h>
#include <instance.h>

double panX = 0.0f, panY = 0.0f;
double translationX = 0.0f, translationY = 0.0f;
double left = -1.0f, right = 1.0f, top = 1.0f, bottom = -1.0f;

std::vector<Instance> houses;
int selectedInstance = 0;

/**
 * @brief Initializes the OpenGL settings and creates the initial house instance.
 */
void initialize() {
    // Define the 2D viewing window
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(left + panX, right + panX, bottom + panY, top + panY);
    glMatrixMode(GL_MODELVIEW);

    Instance house;
    houses.push_back(house);
}

/**
 * @brief Handles window resizing.
 * @param w The new width of the window.
 * @param h The new height of the window.
 */
void reshape(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Check the aspect ratio of the screen to adjust the orthographic projection
    if (w <= h)
        gluOrtho2D(left, right, bottom, bottom + (right - left) * h / w);
    else
        gluOrtho2D(left, left + (right - left) * w / h, bottom, top);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
	glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Tales Lima Oliveira - Parte 2");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);
    glutReshapeFunc(reshape);

    initialize();
    glutMainLoop();
    return 0;
}