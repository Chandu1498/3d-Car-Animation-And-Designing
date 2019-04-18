#include <stdio.h>
#include <gl/glut.h>
#include<math.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;

void reshape(int width, int heigth){
    /* window ro reshape when made it bigger or smaller*/

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //clip the windows so its shortest side is 2.0
    if (width < heigth) {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
    }
    else{
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth,2.0 , 2.0);
    }
    // set viewport to use the entire new window
    glViewport(0, 0, width, heigth);
}
 void rect(void)
 {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);

		glBegin(GL_POLYGON);
		glVertex3f (0.1,0.1,0.0);
        glVertex3f (0.1,0.2,0.0);
        glVertex3f (0.5,0.2, 0.0);
        glVertex3f (0.5,0.1,0.0);
    glEnd();

glColor3f(0.0,1.0,0.0);

		glBegin(GL_POLYGON);
		glVertex3f (0.2, 0.2, 0.0);
        glVertex3f (0.3, 0.4, 0.0);
        glVertex3f (0.4, 0.4, 0.0);
        glVertex3f (0.4, 0.2, 0.0);
    glEnd();
glColor3f(0.4,0.0,0.4);

		glBegin(GL_POLYGON);
		float t1;
		for(int i1=0;i1<360;i1++){
            t1=i1*3.142/180;
            glVertex2f(0.2+0.04*cos(t1),0.1+0.04*sin(t1));
		}
    glEnd();
glColor3f(0.4,0.0,0.4);

		glBegin(GL_POLYGON);
		float t;
		for(int i=0;i<360;i++){
            t=i*3.142/180;
            glVertex2f(0.4+0.04*cos(t),0.1+0.04*sin(t));
		}
    glEnd();


glFlush();
}


void display(){
    //Clear Window
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(posX,posY,posZ);
    rect();
    glPopMatrix();
    glFlush();
}


void init(){
    // set clear color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // set fill color to white
    glColor3f(1.0, 1.0, 1.0);

    //set up standard orthogonal view with clipping
    //box as cube of side 2 centered at origin
    //This is the default view and these statements could be removed
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

}
float move_unit = 0.1f;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv){

    //initialize mode and open a windows in upper left corner of screen
    //Windows tittle is name of program

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("GRAPHICS AND VISUAL COMPUTATION LAB EVALUATION");
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(keyboardown);
    glutMainLoop();

}

