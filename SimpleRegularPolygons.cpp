#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;


void drawPolygon(double x_center, double y_center, int n, double depth){
    glBegin(GL_POLYGON);
    double r = 50;
    double x = 0;
    double y = 0;
    double i = 0;
    double theta = M_PI/n;
    if (n % 2 == 1)
        theta = (M_PI/(n))/2;

    for(i = 0; i < n; i++)
    {
        x = r * cos(2*M_PI*i/n + theta) + x_center;
        y = r * sin(2*M_PI*i/n + theta) + y_center;
        glVertex3f(x, y, depth);
    }
    glEnd();
}

void redraw(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Regular Polygons
    glColor4f(0, 0, 1, 1);
    drawPolygon(100, 100, 3,1);

    glColor4f(0,1,0,0.5);
    drawPolygon(100, 100, 4, 2);

    glColor4f(0, 1, 1, 1);
    drawPolygon(100, 300, 5, 2);

    glColor4f(1, 0, 1, 1);
    drawPolygon(100, 500, 6, 2);

    glColor4f(1, 1, 0, 1);
    drawPolygon(300, 100, 7, 2);

    glColor4f(1, 1, 1, 1);
    drawPolygon(300, 300, 8, 2);

    glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Polygons");
    glutPositionWindow(10,10);
    glutReshapeWindow(800,800);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,800.0,0.0,800.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(redraw);
    glutMainLoop();
    return 0;
}
