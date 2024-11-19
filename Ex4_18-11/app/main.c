#include <stdlib.h>
#include <GL/glut.h>

double tx = 0, ty = 0, angulo = 0, px = 0, py = 0;
double left = -1.0, right = 1.0, bot = -1.0, top = 1.0;

void Casinha(void){
	//Desenha telhado
	glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 1); 				// Blue
		glVertex2f(-0.25f, 0.1f); 			// BotLeft
		glColor3f(1, 0, 0); 				// Red
		glVertex2f(0.0, 0.25);				// Top
		glColor3f(0, 0, 1); 				// Blue
		glVertex2f(0.25f, 0.1f);			// BotRight
	glEnd();

	// Line Settings
	glColor3f(1.0f, 1.0f, 1.0f); 			// White
	glLineWidth(3);

	//Desenha quadrado
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0); 		// White
		glVertex2f(-0.25, -0.2);		// BotLeft
		glVertex2f(-0.25,  0.1);		// TopLeft
		glVertex2f( 0.25,  0.1);		// TopRight
		glVertex2f( 0.25, -0.2);		// BotRight
	glEnd();
}

void Cruz(void){
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

	// Line Settings
	glColor3f(0, 0, 0); 			// White
	glLineWidth(2);

	//Desenha Crosshair (Cruz)
	glBegin(GL_LINES);
		glVertex2f( 0, 1);
		glVertex2f( 0,-1);
		glVertex2f(-1, 0);
		glVertex2f( 1, 0);
	glEnd();
}


//Funcao callback de redesenho da janela de visualizacao
void Desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
		gluOrtho2D(left+px, right+px, bot+py, top+py);
		glTranslatef(tx, ty, 0);
		glRotatef(angulo, 0, 0, 1);

		Casinha();
	glPopMatrix();
	
	Cruz();

	//Executa os comandos OpenGL
	glFlush();
}


void Inicializa(void)
{	
	glMatrixMode(GL_PROJECTION);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.7f, 0.38f, 0.7f, 0); // Pink
}


// Funcao chamada quando o tamanho da janela  alterado
void Reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);
	glLoadIdentity();

	if (w <= h)
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h/w);
	else
		gluOrtho2D(0.0f, 250.0f * w/h, 0.0f, 250.0f);
}




// Funcao callback chamada para gerenciar eventos de teclas
void Teclado (unsigned char key, int x, int y)
{
	switch (key){
	case 27: //ESC
		exit(0); break;

	case 'q':
		px -= 0.25, py += 0.25; break;
	case 'a':
		px += 0.25, py -= 0.25; break;
	case 'e':
		px += 0.25, py += 0.25; break;
	case 'd':
		px -= 0.25, py -= 0.25; break;
	}
	
	glutPostRedisplay();
}

// Funcao de teclas especiais
void TeclasEspeciais(int key, int x, int y){
	switch (key){
	//Rotate
	case GLUT_KEY_PAGE_UP:
		angulo += 0.2; break;
	case GLUT_KEY_PAGE_DOWN:
		angulo -= 0.5;
		break;

	// Move
	case GLUT_KEY_UP: 
		ty += 0.2; break;
	case GLUT_KEY_DOWN:
		ty -= 0.2; break;
	case GLUT_KEY_RIGHT:
		tx += 0.2; break;
	case GLUT_KEY_LEFT:
		tx -= 0.2; break;

	// Zoom
	case GLUT_KEY_HOME:
		left -= 0.25, right += 0.25;
		bot  -= 0.25, top   += 0.25;
		break;
	case GLUT_KEY_END:
		left += 0.25, right -= 0.25;
		bot  += 0.25, top   -= 0.25;
		break;
	}

	glutPostRedisplay();
}


// Programa Principal
int main(void)
{
	int argc = 0;
	char *argv[] = {(char *)"gl", 0};

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500,500);
	glutCreateWindow("Tales Lima Oliveira");

	glutDisplayFunc(Desenha);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(TeclasEspeciais);
	glutReshapeFunc(Reshape);

	Inicializa();
	glutMainLoop();

	return 0;
}