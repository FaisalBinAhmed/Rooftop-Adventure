#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
using namespace std;

 //bool restart = false;
/*
*/
int disx, disy = 0;
float carx, cary = 0;
float ps =480;

float ln = 0;

int mode = 0;
int ti = 1;

void drawLetter(char ch[], int xpos, int ypos)
{
	int numofchar = strlen(ch);
	glRasterPos3f(xpos, ypos, 0);
	for (int i = 0; i <= numofchar - 1; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);
		//glutPostRedisplay();
	}
}
/*
*/

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);




//road divider
glColor3f(0.4,0.0,0.0);
glBegin(GL_QUADS);
    glVertex3f(318, 0, 0);
    glVertex3f(322, 0, 0);

    glVertex3f(322, 480, 0);
    glVertex3f(318, 480, 0);


glEnd();

//lane divider right

glPushMatrix();
glTranslatef(0, ln, 0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);

    for(int i=0; i<960; i+=80){
    glVertex3f(268 , i, 0);
    glVertex3f(268, i+40, 0);


    }
glEnd();
glPopMatrix();




//lane divider right
glPushMatrix();
glTranslatef(0, ln, 0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);

    for(int i=0; i<960; i+=80){
    glVertex3f(372 , i, 0);
    glVertex3f(372, i+40, 0);


    }
glEnd();
glPopMatrix();

//road left
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
    glVertex3f(218, 0, 0);
    glVertex3f(220, 0, 0);

    glVertex3f(220, 480, 0);
    glVertex3f(218, 480, 0);


glEnd();


//road right
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
    glVertex3f(422, 0, 0);
    glVertex3f(424, 0, 0);

    glVertex3f(424, 480, 0);
    glVertex3f(422, 480, 0);


glEnd();


//parking spot
glPushMatrix();
glTranslatef(0, ps, 0);

glColor3f(0.5,0.5,0.0);
glBegin(GL_QUADS);
    glVertex3f(218, 0, 0);
    glVertex3f(168, 0, 0);

    glVertex3f(168, 100, 0);
    glVertex3f(218, 100, 0);


glEnd();

glPopMatrix();

//car
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(carx, cary, 0);

glBegin(GL_QUADS);
    glVertex3f(230, 20, 0);
    glVertex3f(250, 20, 0);

    glVertex3f(250, 60, 0);
    glVertex3f(230, 60, 0);


glEnd();

glPopMatrix();


glColor3f(1.0,0.5,0.5);

if(mode == 0 ){
drawLetter("Driving mode", 20, 450);
}//drawLetter(sco, 130, 450);
else {drawLetter("Parking mode", 20, 420);
//drawLetter(heal , 130, 420);
}
//drawLetter("TIME:", 500, 450);
//drawLetter(tm2 , 560, 450);

glEnd();


glutSwapBuffers();

glFlush();
}


void parking(){


ti = 0;
disx = 230-178;
disy = ps;

}

void update(int value) {

    ps -= ti;

    if(ps<-480){ps+=960;}

    ln -= ti;
    if(ln<-480){ln+=480;}

    if(mode > 0 ){

            disy -=1;

    }

  //  if(mode < 0 ){ disx -=1;}
    if (disy>0){cary +=1;}
    if (!disy>0){mode = -1;}  //problem

    if(mode < 0 ){

       disx -=1;

    }


   if(disx>0 &&  mode <0 ){carx -=1;}
  //  if(disy=0){mode = -2;}
    /*
    */

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(10, update, 0);
}





void keyboard(unsigned char key, int x, int y)
{


if(key=='p'){mode = 1; parking();}


}





void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
//glEnable(GL_DEPTH_TEST);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0, 480.0);
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/



int main(int argc, char** argv)
{


  //  do{

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640, 480);
glutInitWindowPosition(300, 100);
glutCreateWindow("Rooftop Adventure!");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutTimerFunc(25, update, 0);
glutMainLoop();


  //  }
 //   while(restart);

return 0; /* ISO C requires main to return int. */
}


