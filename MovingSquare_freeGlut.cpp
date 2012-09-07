/*
	MovingSquare_freeGlut.cpp

	A freeGLUT program in class example to move a square across the screen

	Authors:	
	Ralph Damiano
	Giorgio Arcamone‎
	Taras Zyma
	Michael Pressmar 
	Austin Fraley

	CHANGLOG:
	6Sep2012 - Initial creation - AF / RD

*/

#include <gl/freeglut.h>

int r = 1;
int g = 0;
int b = 0;
int cornerX = 10;
int cornerY = 10;
int xOffset = 0;
int yOffset = 0;
bool startDrag = false;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(r,g,b);
    glBegin(GL_POLYGON);
       glVertex2f(cornerX,cornerY );
       glVertex2f(cornerX,cornerY + 40);
       glVertex2f(cornerX + 40,cornerY + 40);
       glVertex2f(cornerX + 40,cornerY);
    glEnd();
    glutSwapBuffers();
}

static void mouseClick(int button, int state, int x, int y)
{    
    r = 0;
    g = 0;
    b = 1;
    startDrag = false;
    //cornerX = x;
    //cornerY = y;
    if ( (x > cornerX && x < cornerX + 40) && (y > cornerY && y < cornerY + 40))
    {
        r = 0;
        g = 1;
        b = 0;
        startDrag = true;
        xOffset = x - cornerX;
        yOffset = y - cornerY;
    }
}

void motionFunc(int x, int y)
{
     if(startDrag)
     {
         cornerX = x - xOffset;
         cornerY = y - yOffset;         
     }
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'Q':
    case 'q':  exit(0);
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInitWindowSize(480,480);
    glutInitWindowPosition(40,40);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("OpenGLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMouseFunc(mouseClick);
    glutMotionFunc(motionFunc);

    
    glClearColor(1,1,1,1);
    
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
