#include <GL/glut.h>
#include <iostream>

using namespace std;

float rx,ry;
float winWid = 500.0;
float winHeight = 500.0;
float myx[5] = {125,125,250,375,375};
float myy[5] = {125,375,250,375,125};

void redraw( void )
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.00,1.00,0.0);
	//glRectf(100.0,100.0,300.0,200.0);

	glColor3f(1.0,0.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(myx[0],myy[0],0);
    glVertex3f(myx[1],myy[1],0);
    glVertex3f(myx[2],myy[2],0);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(myx[1],myy[1],0);
    glVertex3f(myx[2],myy[2],0);
    glVertex3f(myx[3],myy[3],0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(myx[3],myy[3],0);
    glVertex3f(myx[2],myy[2],0);
    glVertex3f(myx[4],myy[4],0);
    glEnd();

    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
    glVertex3f(myx[0],myy[0],0);
    glVertex3f(myx[2],myy[2],0);
    glVertex3f(myx[4],myy[4],0);
	glEnd();

	glutSwapBuffers();
}


void motion(int x, int y)
// called when a mouse is in motion with a button down
{
    y = 500 - y;
 	if(x < myx[0] + 10 && x > myx[0] - 10){
        if(y < myy[0] + 10 && y > myy[0] - 10){
            myx[0] = x;
            myy[0] = y;
        }
 	}
 	if(x < myx[1] + 10 && x > myx[1] - 10){
        if(y < myy[1] + 10 && y > myy[1] - 10){
            myx[1] = x;
            myy[1] = y;
        }
 	}
 	if(x < myx[2] + 10 && x > myx[2] - 10){
        if(y < myy[2] + 10 && y > myy[2] - 10){
            myx[2] = x;
            myy[2] = y;
        }
 	}
 	if(x < myx[3] + 10 && x > myx[3] - 10){
        if(y < myy[3] + 10 && y > myy[3] - 10){
            myx[3] = x;
            myy[3] = y;
        }
 	}
 	if(x < myx[4] + 10 && x > myx[4] - 10){
        if(y < myy[4] + 10 && y > myy[4] - 10){
            myx[4] = x;
            myy[4] = y;
        }
 	}

}


void mousebutton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
        cout << x << " " << y << endl;
	}
}

void keyboard(unsigned char key, int x, int y)
// x and y givethe mouse pos
{
	cerr << "Key " << key << " " << int(key) << "\n";
}

int main(int argc, char *argv[])
{
	cerr << "hello world\n";


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Basic example");
	glutPositionWindow(200,100);
	glutReshapeWindow(winWid,winHeight);

	glClearColor(0.0,0.0,0.0,1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,winWid,0.0,winHeight, -100.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(redraw);
	glutIdleFunc(redraw);
	glutMotionFunc( motion);
	glutMouseFunc( mousebutton);
	glutKeyboardFunc( keyboard );
	glutMainLoop();

	return 0;
}
