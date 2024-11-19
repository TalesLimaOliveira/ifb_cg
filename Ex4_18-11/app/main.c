#include <stdlib.h>
#include <GL/glut.h>
#include "drawing.h"
#include "input.h"

void initialize() {
    glMatrixMode(GL_PROJECTION);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.5f, 0.5f, 0);
}



int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tales Lima Oliveira");

    glutDisplayFunc(displayCallback);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialKeysCallback);
    glutReshapeFunc(reshapeCallback);

    initialize();
    glutMainLoop();
    return 0;
}