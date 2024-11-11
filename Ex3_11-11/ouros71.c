#include <GL/glut.h>
#include <stdlib.h>

int tx = 0, ty = 0, angulo = 0, ex = 1, ey = 1;

// INIT OPENGL WINDOW
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);       // BLACK
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);   // Config ortogonal
}

// DRAW DIAMOND SUIT
void createDiamond(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);       // POSITION
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.5f);     // TOP
        glVertex2f(0.5f, 0.0f);     // RIGHT
        glVertex2f(0.0f, -0.5f);    // BOT
        glVertex2f(-0.5f, 0.0f);    // LEFT
    glEnd();
    glPopMatrix();
}

// DRAW SCENE
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // RESHAPE CONFIG
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    glScalef(ex, ey, 1);
    glRotatef(angulo, 0, 0, 1);

    glColor3f(1.0f, 0.0f, 0.0f);    // RED
    createDiamond(0.0f, 0.6f);      // TOP

    glColor3f(0.0f, 1.0f, 0.0f);    // GREEN
    createDiamond(-0.5f, 0.0f);     // MID LEFT

    glColor3f(0.0f, 0.0f, 1.0f);    // BLUE
    createDiamond(0.5f, 0.0f);      // MID RIGHT

    glColor3f(1.0f, 1.0f, 0.0f);    // YELLOW
    createDiamond(0.0f, -0.6f);     // BOTTOM

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



// MAIN FUNTION
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(25, 25);
    glutCreateWindow("Losangos Coloridos - Naipe de Ouros");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    init();
    glutMainLoop();

    return 0;
}
