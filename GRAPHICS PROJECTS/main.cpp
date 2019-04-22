
#include <stdio.h>
#include <GL/glut.h>


static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 0;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;
static GLuint axes_list;


void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}
void reset()
{
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -30.0;
}

void reshape(int w,int h)
{
	glViewport(0,0, (GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spinDisplay(void)
{
	spin=spin+spin_speed;
	if(spin>360.0)
	{
		spin=spin-360.0;
	}
	glutPostRedisplay();
}
void spinDisplayReverse(void)
{
	spin=spin-spin_speed;
	if(spin<360.0)
	{
		spin=spin+360.0;
	}
	glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if(state==GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if(state==GLUT_DOWN)
			glutIdleFunc(spinDisplayReverse);
		break;
	default:
		break;
	}
}
void keyboard(unsigned char key, int x, int y)
{

	if(key=='x')
	{
		setSpin(1.0,0.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='y')
	{
		setSpin(0.0,1.0,0.0);
		glutPostRedisplay();
	}
	else if(key=='z')
	{
		setSpin(0.0,0.0,1.0);
		glutPostRedisplay();
	}


	else if(key=='i')
	{
		translate_z++;
		glutPostRedisplay();
	}
	else if(key=='o')
	{
		translate_z--;
		glutPostRedisplay();
	}

	else if(key=='r')
	{
		reset();
		glutPostRedisplay();
	}

}


void init()
{
	glClearColor(1.0,1.0,1.0,0);
	glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
}


void drawpolygon()
{
	glTranslatef(translate_x, translate_y, translate_z);

	glRotatef(spin,spin_x,spin_y,spin_z);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(0, 10);
	glVertex2i(8, 10);
	glVertex2i(1, -10);
	glVertex2i(-1, -10);
	glVertex2i(0, 10);
	glEnd();


}



void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();



	drawpolygon();



	glutSwapBuffers();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("2D polygon");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
