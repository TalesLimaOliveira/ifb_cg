#include <stdlib.h>
#include <GL/glut.h>
#include "instance.h"
#include <vector>
 
using namespace std;
 
vector<Instancia> casas;
int instanciaSelecionada = 0;

double translacaoX = 0, translacaoY = 0, panX = 0, panY = 0;
double esquerda = -1.0, direita = 1.0, baixo = -1.0, cima = 1.0;

void desenhaCasinha(){
	glLineWidth(3);

	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.2f,0.1f);
		glVertex2f(-0.2f,-0.2f);
		glVertex2f(0.2f,-0.2f);
		glVertex2f(0.2f,0.1f);
	glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.2f,0.1f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f,0.22f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.2f,0.1f);
    glEnd();
}

void desenhaEixos() {
	glColor3f(1,1,1);
	glLineWidth(1);

	glBegin(GL_LINES);
		glVertex2f(esquerda,0.0); glVertex2f(direita, 0.0);
		glVertex2f(0.0,baixo); glVertex2f(0.0,cima);
	glEnd();
}

void Desenha(void)
{
	// Limpa a janela de visualização com a cor branca
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
		glLoadIdentity();
		desenhaEixos();
	glPopMatrix();

	glPushMatrix();
		glLoadIdentity();
    	glTranslatef(translacaoX,translacaoY,0);
    	desenhaCasinha();
	glPopMatrix();

	glFlush();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y)
{
	(void)x; (void)y;
    if (key == 27)
		exit(0);
}

void TeclasEspecias(int key, int x, int y)
{
	(void)x; (void)y;
	if(key == GLUT_KEY_END){
		esquerda-=0.1; direita+=0.1;
		cima+=0.1; baixo-=0.1;
	}
	if(key == GLUT_KEY_HOME){
		esquerda+=0.1; direita-=0.1;
		cima-=0.1; baixo+=0.1;
	}

	if(key == GLUT_KEY_LEFT)
        translacaoX -= 0.1;
    if(key == GLUT_KEY_RIGHT)
        translacaoX += 0.1;
    if(key == GLUT_KEY_UP)
        translacaoY += 0.1;
    if(key == GLUT_KEY_DOWN)
        translacaoY -= 0.1;
	if(key == GLUT_KEY_F9)
		panX+=0.1;
	if(key == GLUT_KEY_F10)
		panX-=0.1;
	if(key == GLUT_KEY_F11)
		panY+=0.1;
	if(key == GLUT_KEY_F12)
		panY-=0.1;

	glutPostRedisplay();
}



void Inicializa(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(esquerda+panX, direita+panX, baixo+panY, cima+panY);
	glMatrixMode(GL_MODELVIEW);
}


// Programa Principal
int main(int argc, char *argv[]){
	Instancia casa;
    casas.push_back(casa);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(15,15);
    glutCreateWindow("Tales Lima Oliveira");

    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(TeclasEspecias);

    Inicializa();
    glutMainLoop();
	return 0;
}