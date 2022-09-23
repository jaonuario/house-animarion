#include "main.hpp"

char nextMove = ' ';
int posx = 400;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 140);
    glutCreateWindow("House-animation");

    glutKeyboardFunc(KeyboardManage);    
    glutTimerFunc(60, Timer, 1);
    
    glutDisplayFunc(Draw);
    Inicialize();
    glutMainLoop();

    return 0;
}

void Inicialize()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(3.0);
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
}

void Draw()
{
    DrawScenery(); 
    DrawStickMan();  
}

void DrawStickMan()
{
    int h = 80;    
    double PI = 3.141592;
    double centerx = 0, centery = 0, r;
    double p = 0, theta = 0;

    glViewport(0, 0, 500, 500);
    
    glColor3f(0.0, 0.0, 0.0);

    p = 2 * PI / 100;
    theta = p;
    r = h/8.0;
    glBegin(GL_POLYGON);
        for (int i = 0; i < 100; i++) {
            centerx = r * cos(theta) + posx;
            centery = r * sin(theta) + 500 - h;
            theta += p;

            glVertex2i(centerx, centery);
        }
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(posx,500 - 7*(h/8));
    glVertex2i(posx + 10,500 - 4*(h/8));
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(posx,500 - 7*(h/8));
    glVertex2i(posx - 10,500 - 4*(h/8));
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(posx,500 - 7*(h/8));
    glVertex2i(posx,500 - 4*(h/8));
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(posx,500 - 4*(h/8));
    glVertex2i(posx-5,500);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(posx,500 - 4*(h/8));
    glVertex2i(posx+5,500);
    glEnd();

    glFlush();
}

void DrawScenery()
{
    glViewport(0, 0, 500, 500);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.2, 0.3);
    glVertex2i(0,0);
    glVertex2i(500,0);
    glColor3f(1, 0.4, 0.0);
    glVertex2i(500,350);
    glVertex2i(0,350);
    glEnd();
    
    double PI = 3.141592;
    double centerx = 0, centery = 0, r;
    double p = 0, theta = 0;

    p = 2 * PI / 100;
    theta = p;
    r = 50;

    glBegin(GL_POLYGON);
        for (int i = 0; i < 100; i++) {
            centerx = r * cos(theta) + 300;
            centery = r * sin(theta) + 250;
            theta += p;

            glVertex2i(centerx, centery);
        }
    glEnd();

    glColor3f(0.2, 0.2, 0);

    p = 2 * PI / 500;
    theta = p;

    glBegin(GL_POLYGON);
    for(int i = 0; i < 500; i++)
    {   
        centery = 350 + sin(theta)*50;
        theta += p;

        glVertex2i(i, centery);
    }
    glVertex2i(500, 500);
    glVertex2i(0, 500);
    glEnd();

    glColor3f(0.3, 0.3, 0.3);

    glBegin(GL_POLYGON);
    glVertex2i(100,500);
    glVertex2i(100,350);
    glVertex2i(300,350);
    glVertex2i(300,500);
    glEnd();

    glColor3f(0.2, 0.1, 0.0);

    glBegin(GL_POLYGON);
    glVertex2i(100,350);
    glVertex2i(300,350);
    glVertex2i(200,275);
    glEnd();

    glFlush();
}

void KeyboardManage(unsigned char key, int x, int y)
{
    switch (key) {
        case 'a':
        case 'A':
            nextMove = 'a';
            break;
        
        case 'd':
        case 'D':
            nextMove = 'd';
            break;
    }

    glutPostRedisplay();
}

void Timer(int value)
{
    if(nextMove == 'a')
    {
        posx -= 4;
        nextMove = ' ';
    }

    if(nextMove == 'd')
    {
        posx += 4;
        nextMove = ' ';
    }

    glutPostRedisplay();
    glutTimerFunc(60, Timer, value+1);
}