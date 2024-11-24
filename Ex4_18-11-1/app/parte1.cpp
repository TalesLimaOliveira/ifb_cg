#include <stdlib.h>
#include <GL/glut.h>
#include "drawing.h"
#include "input.h"

void initialize(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left+px, right+px, bot+py, top+py);
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
    glutInitWindowPosition(15,15);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tales Lima Oliveira - Parte 1");

    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialKeysCallback);
    glutReshapeFunc(reshapeCallback);

    initialize();
    glutMainLoop();
    return 0;
}