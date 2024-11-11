#include <GL/glut.h>
#include <stdlib.h>

int tx = 0, ty = 0, angulo = 0, ex = 1, ey = 1;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // BLACK
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // RESHAPE CONFIG
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);
    glScalef(ex, ey, 1);
    glRotatef(angulo, 0, 0, 1);

    glColor3f(1.0, 1.0, 1.0);    // WHITE

    // CENTER SQUARE
    float squareSize = 0.2f;
    glBegin(GL_LINE_LOOP);
        glVertex2f(-squareSize, -squareSize);
        glVertex2f( squareSize, -squareSize);
        glVertex2f( squareSize,  squareSize);
        glVertex2f(-squareSize,  squareSize);
    glEnd();

    // VERTICAL LINE
    glBegin(GL_LINES);
        glVertex2f(0.0, -0.5);          // BOT TO TOP, OUTSIDE SQUARE
        glVertex2f(0.0, -squareSize);   // BOT SQUARE
        glVertex2f(0.0, squareSize);    // TOP SQUARE
        glVertex2f(0.0, 0.5);           // TOP TO BOT, OUTSIDE SQUARE
    glEnd();

    // HORIZONTAL LINE
    glBegin(GL_LINES);
        glVertex2f(-0.5, 0.0);          // LEFT TO RIGHT, OUTSIDE SQUARE
        glVertex2f(-squareSize, 0.0);   // LEFT SQUARE
        glVertex2f(squareSize, 0.0);    // RIGHT SQUARE
        glVertex2f(0.5, 0.0);           // RIGHT TO LEFT, OUTSIDE SQUARE
    glEnd();

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
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(25, 25);
    glutCreateWindow("Mira do aspas");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();
    glutMainLoop();

    return 0;
}
