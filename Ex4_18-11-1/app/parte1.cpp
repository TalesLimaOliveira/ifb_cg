#include <stdlib.h>
#include <GL/glut.h>
#include <drawing.h>
#include <keyboard.h>

double tx = 0.0f, ty = 0.0f, angulo = 0.0f;
double left = -1.0f, right = 1.0f, bot = -1.0f, top = 1.0f;

/**
 * @brief Initializes the OpenGL environment.
 */
void initialize(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bot, top);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
 * @brief Handles window reshaping.
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
        gluOrtho2D(left, right, bot, bot + (right - left) * h / w);
    else
        gluOrtho2D(left, left + (right - left) * w / h, bot, top);

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
    glutInitWindowPosition(15, 15);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tales Lima Oliveira - Parte 1");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);
    glutReshapeFunc(reshape);

    initialize();
    glutMainLoop();
    return 0;
}