#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

int tx = 0, ty = 0, angulo = 0, ex = 1, ey = 1;

// OPENGL CONFIGS
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // BLACK
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// DRAW SHURIKEN
void drawShuriken() {
    glBegin(GL_LINE_LOOP);

    // Definindo coordenadas dos vértices
    GLfloat vertices[6][2] = {
        {0.0, 0.5},        // Ponta superior (vermelho)
        {-0.5, -0.3},      // Interior inferior esquerdo
        {0.0, -0.1},       // Ponta inferior esquerda (verde)
        {0.5, -0.3},       // Interior inferior direito
        {0.0, -0.5},       // Ponta inferior direita (azul)
        {-0.5, -0.3}       // Fechando o loop
    };

    // Definindo cores das pontas
    GLfloat cores[3][3] = {
        {1.0, 0.0, 0.0},  // Vermelho para a primeira ponta
        {0.0, 1.0, 0.0},  // Verde para a segunda ponta
        {0.0, 0.0, 1.0}   // Azul para a terceira ponta
    };

    // Desenha com gradiente
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            glColor3f(cores[i / 2][0], cores[i / 2][1], cores[i / 2][2]);  // Alterna entre as cores
        } else {
            glColor3f(0.5, 0.5, 0.5);  // Cinza claro para os pontos internos
        }
        glVertex2f(vertices[i][0], vertices[i][1]);
    }

    glEnd();
}

// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // RESHAPE CONFIG
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    glScalef(ex, ey, 1);
    glRotatef(angulo, 0, 0, 1);

    drawShuriken();
    glFlush();
}


// RESHAPE WINDOW
void reshape(GLsizei w, GLsizei h) {
    if (h == 0) h = 1; 
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(25, 25);
    glutCreateWindow("Shuriken com Efeito Gradiente");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();
    return 0;
}
