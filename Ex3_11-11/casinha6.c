#include <GL/glut.h>
#include <stdlib.h>

int tx = 0, ty = 0, angulo = 0, ex = 1, ey = 1, user_input = 0;

// Função para configurar a cor de fundo
void Inicializa(void) {
    // Cor de fundo azul
    glClearColor(0.18f, 0.14f, 0.5f, 1.0f);
}

// Função chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
    if (h == 0) h = 1; // Evita divisão por zero

    // Define as dimensões da área de visualização
    glViewport(0, 0, w, h);

    // Configura a projeção p/ manter a proporção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}

// Função de desenho
void Desenha() {
    // Limpa a tela com a cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    // Transformações de translação, escala e rotação
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    glScalef(ex, ey, 1);
    glRotatef(angulo, 0, 0, 1);


    // ROOF
    glBegin(GL_TRIANGLES); 
        glColor3f(0.0f, 0.58f, 0.25f);  // GREEN
        glVertex2i(50, 100);            // TOP LEFT HOUSE
        glVertex2i(125, 110 + user_input);           // MIDDLE ROOF
        glVertex2i(200, 100);           // TOP RIGHT HOUSE
    glEnd();

    // HOUSE
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.79f, 0.0f);   // YELLOW
        glVertex2i(50, 5);              // BOT LEFT
        glVertex2i(50, 100);            // TOP LEFT
        glVertex2i(200, 100);           // TOP RIGHT
        glVertex2i(200, 5);             // BOT RIGHT
    glEnd();


    // DOOR
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);   // BLACK
        glVertex2i(80, 7);             // BOT LEFT
        glVertex2i(80, 60);            // TOP LEFT
        glVertex2i(120, 60);           // TOP RIGHT
        glVertex2i(120, 7);            // BOT RIGHT
    glEnd();

    // WINDOWS
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);   // WHITE
        glVertex2i(140, 25);           // BOT LEFT
        glVertex2i(140, 60);           // TOP LEFT
        glVertex2i(180, 60);           // TOP RIGHT
        glVertex2i(180, 25);           // BOT RIGHT 
    glEnd();

    // BARS
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);   // BLACK
        glVertex2i(160, 60);           // H TOP
        glVertex2i(160, 25);           // H BOT
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(140, 43);           // V LEFT
        glVertex2i(180, 43);           // V RIGHT
    glEnd();

    // Processa os comandos OpenGL
    glFlush();
}

// Função de teclas especiais
void TeclasEspeciais(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_PAGE_UP:    // Rota para a direita
            angulo += 1;
            break;
        case GLUT_KEY_PAGE_DOWN:  // Rota para a esquerda
            angulo -= 1;
            break;
        case GLUT_KEY_HOME:       // Aumenta a escala no eixo X
            ex += 1;
            break;
        case GLUT_KEY_END:        // Diminui a escala no eixo X
            ex -= 1;
            break;
        case GLUT_KEY_UP:         // Move para cima
            ty += 1;
            break;
        case GLUT_KEY_DOWN:       // Move para baixo
            ty -= 1;
            break;
        case GLUT_KEY_RIGHT:      // Move para a direita
            tx += 1;
            break;
        case GLUT_KEY_LEFT:       // Move para a esquerda
            tx -= 1;
            break;
    }
    // Redesenha a tela com as novas transformações
    glutPostRedisplay(); 
}

// Função principal
int main(int argc, char **argv) {

    if(argc != 2) return 1;

    user_input = atoi(argv[1]);

    // Inicializa o ambiente GLUT e configura a janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(25, 25);
    glutCreateWindow("Casinha");

    // Registra as funções de callback
    // Função de desenho
    glutDisplayFunc(Desenha);      
    // Função de redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);  
    // Função de teclas especiais
    glutSpecialFunc(TeclasEspeciais);       

    // Configura a cor de fundo e inicia o loop principal
    Inicializa();
    glutMainLoop();

    return 0;
}