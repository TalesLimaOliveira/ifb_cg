#include <stdlib.h>
#include <GL/glut.h>
#include <vector>
#include "drawing2.h"
#include "instance.h"
#include "input.h"

using namespace std;

vector<Instancia> casas;
int instanciaSelecionada = 0;


void Inicializa(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(esquerda + panX, direita + panX, baixo + panY, cima + panY);
    glMatrixMode(GL_MODELVIEW);
}

void setupCallbacks() {
    glutDisplayFunc(desenha);
    glutKeyboardFunc(keyboardCallback);
    glutSpecialFunc(specialKeysCallback);
    glutReshapeFunc(reshapeCallback);
}

int main(int argc, char *argv[]) {
    Instancia casa;
    casas.push_back(casa);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(15, 15);
    glutCreateWindow("Tales Lima Oliveira");

    setupCallbacks();
    Inicializa();
    glutMainLoop();
    return 0;
}