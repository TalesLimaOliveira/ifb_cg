#include <stdlib.h>
#include <GL/glut.h>
#include "instance.h"
#include "input.h"
#include "drawing.h"
#include "drawing2.h"
#include <vector>

using namespace std;

vector<Instancia> casas;
int instanciaSelecionada = 0;

void Desenha(void) {
    // Limpa a janela de visualização com a cor branca
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glLoadIdentity();
        desenhaEixos();
    glPopMatrix();

    glPushMatrix();
        glLoadIdentity();
        glTranslatef(translacaoX, translacaoY, 0);
        desenhaCasinha();
    glPopMatrix();

    glFlush();
}

void Inicializa(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(esquerda + panX, direita + panX, baixo + panY, cima + panY);
    glMatrixMode(GL_MODELVIEW);
}

void setupCallbacks() {
    glutDisplayFunc(displayCallback);
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