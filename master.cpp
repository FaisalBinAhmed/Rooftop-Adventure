#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
using namespace std;

 //bool restart = false;

float a,b,c,d,e,f,g,h=0;
float a2 = 700;
float box2y= 0;
float hy = 0; //health y
float boxy = 0;
float posx, posy=0;
int time = 0;
float moonpos = 0;
float cloudpos = 0;
float cc= 1;
float coin1x =0;
float coin2x = 0;
float coin3x = 500;
float coin4x = 750;

float coin1y =20;
float coin2y = 20;
float coin3y = 60;
float coin4y = 60;

float mr = 1.0;
float  mg = 1.0;
float mb = 1.0;

float hr = 0;
float hg = 0;
float hb = 0.13;

float rr=0.64;
float rg = 0.8;
float rb = 0.8;

float br = 0.0;
float bg = 0.0;
float bb = 0.0;
float fc = .84;
int score = 0;
int health = 100;
float tm=15;
float starr= 1; float starg = 1; float starb = 1;
float window = 0;
int day = 1;

int o = 10 + rand()%100;
int p = 10 + rand()%100;





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

void gameover(){


    cout<<"Your score was: "<<score<<'\n';
    //restart = true;
    exit(EXIT_SUCCESS);
   // glutMainLoop();



    }

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);



//horizon
glColor3f(hr,hg,hb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(0, 160, 0);
    glVertex3f(640, 160, 0);

    glVertex3f(640, 480, 0);
    glVertex3f(0, 480, 0);


glEnd();

//stars


glColor3f(starr, starg, starb);
glBegin(GL_QUADS);

    glVertex3f(20, 260, 0);
    glVertex3f(20, 260+2, 0);
    glVertex3f(20+2, 260+2, 0);
    glVertex3f(20+2, 260, 0);
glEnd();
glColor3f(starr, starg, starb);

glBegin(GL_QUADS);

    glVertex3f(50, 350, 0);
    glVertex3f(50, 350+2, 0);
    glVertex3f(50+2, 350+2, 0);
    glVertex3f(50+2, 350, 0);
glEnd();
glColor3f(starr, starg, starb);
glBegin(GL_QUADS);

    glVertex3f(160, 410, 0);
    glVertex3f(160, 410+2, 0);
    glVertex3f(160+2, 410+2, 0);
    glVertex3f(160+2, 410, 0);
glEnd();
glColor3f(starr, starg, starb);
glBegin(GL_QUADS);

    glVertex3f(360, 430, 0);
    glVertex3f(360, 430+2, 0);
    glVertex3f(360+2, 430+2, 0);
    glVertex3f(360+2, 430, 0);
glEnd();

//glPopMatrix();
//cloud

glPushMatrix();
glTranslatef(cloudpos, 0, 0);
glColor3f(cc, cc, cc);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=120;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+156,y+170 );
	}
	glEnd();
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=60;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+250,y+270 );
	}
	glEnd();
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=100;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+330,y+240 );
	}
	glEnd();

	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=60;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+450,y+220 );
	}
	glEnd();

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=70;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+556,y+240 );
	}
	glEnd();

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=90;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+610,y+260 );
	}
	glEnd();

glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=50;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+680,y+230 );
	}
	glEnd();







glPopMatrix();

//floor
glColor3f(fc,.2,.2);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(0, 0, 0);
    glVertex3f(640, 0, 0);

    glVertex3f(640, 160, 0);
    glVertex3f(0, 160, 0);



glEnd();

glColor3f(1,1,1);//(R,G,B)
glBegin(GL_QUADS);

for(int i = 0; i<160; i+=40){
    glVertex3f(0, i, 0);
    glVertex3f(640, i, 0);

    glVertex3f(640, i+2, 0);
    glVertex3f(0, i+2, 0);}



glEnd();





//railing wall

glColor3f(rr,rg,rb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(0, 160, 0);
    glVertex3f(640, 160, 0);

    glVertex3f(640, 235, 0);
    glVertex3f(0, 235, 0);


glEnd();

glColor3f(0.1,0.1,0.1);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(0, 235, 0);
    glVertex3f(640, 235, 0);

    glVertex3f(640, 240, 0);
    glVertex3f(0, 240, 0);


glEnd();




//railing

glPushMatrix();
glTranslatef(e, 0, 0);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINES);

    for(int i=0; i<1280; i+=10){
    glVertex3f( i, 160, 0);
    glVertex3f(i, 235, 0);


    }
glEnd();
glPopMatrix();






glPushMatrix();
glTranslatef(b, 0, 0);
//building2
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(80, 240, 0);
    glVertex3f(120, 240, 0);

    glVertex3f(120, 320, 0);
    glVertex3f(80, 320, 0);


glEnd();

/*
glColor3f(1,1,1);
glBegin(GL_LINES);

glVertex3f(80, 240, 0);
glVertex3f(80, 320, 0);

glVertex3f(120, 320, 0);
glVertex3f(80, 320, 0);

glVertex3f(120, 320, 0);
glVertex3f(120, 240, 0);

glEnd(); */

//window
glColor3f(1.0,1.0,1.0);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(85, 315, 0);
    glVertex3f(87, 315, 0);

    glVertex3f(87, 317, 0);
    glVertex3f(85, 317, 0);


glEnd();


//building1
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(10, 240, 0);
    glVertex3f(40, 240, 0);

    glVertex3f(40, 300, 0);
    glVertex3f(10, 300, 0);


glEnd();

//building3
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(120, 240, 0);
    glVertex3f(150, 240, 0);

    glVertex3f(150, 280, 0);
    glVertex3f(120, 280, 0);


glEnd();

//building4
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(240, 240, 0);
    glVertex3f(270, 240, 0);

    glVertex3f(270, 360, 0);
    glVertex3f(240, 360, 0);


glEnd();

//building5
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(275, 240, 0);
    glVertex3f(305, 240, 0);

    glVertex3f(305, 360, 0);
    glVertex3f(275, 360, 0);


glEnd();
//bridge
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(270, 320, 0);
    glVertex3f(275, 320, 0);

    glVertex3f(275, 324, 0);
    glVertex3f(270, 324, 0);


glEnd();
//antenna
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(253, 360, 0);
    glVertex3f(256, 360, 0);

    glVertex3f(256, 390, 0);
    glVertex3f(253, 390, 0);


glEnd();
//building6
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(330, 240, 0);
    glVertex3f(360, 240, 0);

    glVertex3f(360, 290, 0);
    glVertex3f(330, 290, 0);


glEnd();
//building8
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(570, 240, 0);
    glVertex3f(600, 240, 0);

    glVertex3f(600, 300, 0);
    glVertex3f(570, 300, 0);


glEnd();
//building7
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(450, 240, 0);
    glVertex3f(480, 240, 0);

    glVertex3f(480, 260, 0);
    glVertex3f(450, 260, 0);


glEnd();
//building7
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(520, 240, 0);
    glVertex3f(550, 240, 0);

    glVertex3f(550, 260, 0);
    glVertex3f(520, 260, 0);


glEnd();
//building7
glColor3f(br,bg,bb);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(650, 240, 0);
    glVertex3f(680, 240, 0);

    glVertex3f(680, 300, 0);
    glVertex3f(650, 300, 0);


glEnd();

glPopMatrix();
//moon

glPushMatrix();
glTranslatef(moonpos, 0, 0);
glColor3f(mr, mg, mb);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=20;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+560,y+420 );
	}
	glEnd();
glPopMatrix();
//coin1

glPushMatrix();
//glRotatef(30.0, 0.1, 0.0, 0.0);
glTranslatef(coin1x, coin1y, 0);

glColor3f(1.0,0.84,0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x= r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+80 );
	}
	glEnd();
	glColor3f(0.0,0.0,0.0);
	drawLetter("5", -5, 75);

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+80 );
	}
	glEnd();

glPopMatrix();

//coin2

glPushMatrix();
//glRotatef(30.0, 0.1, 0.0, 0.0);
glTranslatef(coin2x, coin2y, 0);

glColor3f(1.0,0.84,0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+100,y+80 );
	}
	glEnd();
glColor3f(0.0,0.0,0.0);
	drawLetter("5", 95, 75);


glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+100,y+80 );
	}
	glEnd();

glPopMatrix();



//coin3

glPushMatrix();
//glRotatef(30.0, 0.1, 0.0, 0.0);
glTranslatef(coin3x, coin3y, 0);

glColor3f(1.0,0.84,0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x= r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y+80 );
	}
	glEnd();
	glColor3f(0.0,0.0,0.0);
	drawLetter("5", -5, 75);

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+0,y+80 );
	}
	glEnd();

glPopMatrix();

//coin4

glPushMatrix();
//glRotatef(30.0, 0.1, 0.0, 0.0);
glTranslatef(coin4x, coin4y, 0);

glColor3f(1.0,0.84,0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+100,y+80 );
	}
	glEnd();

    glColor3f(0.0,0.0,0.0);
	drawLetter("5", 95, 75);

glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=12;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+100,y+80 );
	}
	glEnd();

glPopMatrix();




glPushMatrix();

glTranslatef(a, boxy, 0);
//box
glColor3f(1.0,0.93,0.58);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(200, 60, 0);
    glVertex3f(240, 60, 0);

    glVertex3f(240, 100, 0);
    glVertex3f(200, 100, 0);


glEnd();


glBegin(GL_QUADS);

    glVertex3f(200, 60, 0);
    glVertex3f(200, 100, 0);

    glVertex3f(180, 110, 0);
    glVertex3f(180, 70, 0);


glEnd();

glBegin(GL_QUADS);

    glVertex3f(200, 100, 0);
    glVertex3f(240, 100, 0);

    glVertex3f(220, 110, 0);
    glVertex3f(180, 110, 0);


glEnd();

glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 60, 0);
    glVertex3f(240, 60, 0);

    glVertex3f(240, 100, 0);
    glVertex3f(200, 100, 0);


glEnd();


glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(205, 65, 0);
    glVertex3f(235, 65, 0);

    glVertex3f(235, 95, 0);
    glVertex3f(205, 95, 0);


glEnd();



glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 60, 0);
    glVertex3f(200, 100, 0);

    glVertex3f(180, 110, 0);
    glVertex3f(180, 70, 0);


glEnd();

/*
glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(202, 62, 0);
    glVertex3f(202, 98, 0);

    glVertex3f(178, 108, 0);
    glVertex3f(178, 72, 0);


glEnd();
*/


glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 100, 0);
    glVertex3f(240, 100, 0);

    glVertex3f(220, 110, 0);
    glVertex3f(180, 110, 0);


glEnd();


glPopMatrix();

//box 2

glPushMatrix();


glTranslatef(a2, box2y, 0);
//box
glColor3f(1.0,0.93,0.58);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(200, 60, 0);
    glVertex3f(240, 60, 0);

    glVertex3f(240, 100, 0);
    glVertex3f(200, 100, 0);


glEnd();

glBegin(GL_QUADS);

    glVertex3f(200, 60, 0);
    glVertex3f(200, 100, 0);

    glVertex3f(180, 110, 0);
    glVertex3f(180, 70, 0);


glEnd();

glBegin(GL_QUADS);

    glVertex3f(200, 100, 0);
    glVertex3f(240, 100, 0);

    glVertex3f(220, 110, 0);
    glVertex3f(180, 110, 0);


glEnd();

glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 60, 0);
    glVertex3f(240, 60, 0);

    glVertex3f(240, 100, 0);
    glVertex3f(200, 100, 0);


glEnd();

glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(205, 65, 0);
    glVertex3f(235, 65, 0);

    glVertex3f(235, 95, 0);
    glVertex3f(205, 95, 0);


glEnd();

glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 60, 0);
    glVertex3f(200, 100, 0);

    glVertex3f(180, 110, 0);
    glVertex3f(180, 70, 0);


glEnd();
glColor3f(0.0,0.0,0.0);//(R,G,B)
glBegin(GL_LINE_LOOP);

    glVertex3f(200, 100, 0);
    glVertex3f(240, 100, 0);

    glVertex3f(220, 110, 0);
    glVertex3f(180, 110, 0);


glEnd();


glPopMatrix();


















//life

glPushMatrix();

glTranslatef(d, hy, 0);
glColor3f(1.0,0.0,0.0);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(305, 65, 0);
    glVertex3f(335, 65, 0);

    glVertex3f(335,95, 0);
    glVertex3f(305, 95, 0);


glEnd();

glColor3f(1.0,1.0,1.0);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(310, 77, 0);
    glVertex3f(330, 77, 0);

    glVertex3f(330, 83, 0);
    glVertex3f(310, 83, 0);


glEnd();

glColor3f(1.0,1.0,1.0);//(R,G,B)
glBegin(GL_QUADS);

    glVertex3f(317, 70, 0);
    glVertex3f(323, 70, 0);

    glVertex3f(323, 90, 0);
    glVertex3f(317, 90, 0);


glEnd();

glPopMatrix();
//hero

glPushMatrix();

glTranslatef(posx+10,posy+20,0);
//hero body
glColor3f(0.2,0.0,0.2);
glBegin(GL_QUADS);
    glVertex3f(50, 80, 0);
    glVertex3f(75, 80, 0);

    glVertex3f(75, 110, 0);
    glVertex3f(50, 110, 0);


glEnd();

//hero head
glColor3f(1.0,0.88,0.74);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+62.5,y+120 );
	}
	glEnd();
//hero eye
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+67.5,y+122 );
	}
	glEnd();

//hero booster
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
    glVertex3f(40, 80, 0);
    glVertex3f(50, 80, 0);

    glVertex3f(50, 110, 0);
    glVertex3f(40, 110, 0);


glEnd();
//hero booster bottom
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
    glVertex3f(41, 80, 0);
    glVertex3f(49, 80, 0);

    glVertex3f(49, 77, 0);
    glVertex3f(41, 77, 0);


glEnd();
/*
//hero booster fire
glColor3f(0.89,0.35,0.13);
glBegin(GL_QUADS);
    glVertex3f(42, 70, 0);
    glVertex3f(48, 70, 0);

    glVertex3f(48, 77, 0);
    glVertex3f(42, 77, 0);


glEnd();
glColor3f(0.89,0.6,0.13);
glBegin(GL_QUADS);
    glVertex3f(43, 70, 0);
    glVertex3f(47, 70, 0);

    glVertex3f(47, 66, 0);
    glVertex3f(43, 66, 0);


glEnd();
glColor3f(0.89,0.72,0.13);
glBegin(GL_QUADS);
    glVertex3f(44, 66, 0);
    glVertex3f(46, 66, 0);

    glVertex3f(46, 64, 0);
    glVertex3f(44, 64, 0);


glEnd();
*/

//hero pants
glColor3f(0.0,0.2,0.4);
glBegin(GL_QUADS);
    glVertex3f(55, 70, 0);
    glVertex3f(70, 70, 0);

    glVertex3f(70, 80, 0);
    glVertex3f(55, 80, 0);


glEnd();


//hero leg
glColor3f(1.0,0.88,0.74);
glBegin(GL_QUADS);
    glVertex3f(60, 50, 0);
    glVertex3f(65, 50, 0);

    glVertex3f(65, 70, 0);
    glVertex3f(60, 70, 0);


glEnd();

//hero shoes
glColor3f(0.4,0.0,0.0);
glBegin(GL_QUADS);
    glVertex3f(59, 50, 0);
    glVertex3f(75, 50, 0);

    glVertex3f(75, 44, 0);
    glVertex3f(59, 44, 0);


glEnd();

//hero shoe wheel
glColor3f(1.0, 0.75,0.75);
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+71,y+41 );
	}
	glEnd();
glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50;
		float r=3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x+62,y+41 );
	}
	glEnd();



//hero sleeve
glColor3f(0.6,0.0,0.3);
glBegin(GL_QUADS);
    glVertex3f(57.5, 105, 0);
    glVertex3f(67.5, 105, 0);

    glVertex3f(67.5, 95, 0);
    glVertex3f(57.5, 95, 0);


glEnd();

//hero arm
glColor3f(1.0,0.88,0.74);
glBegin(GL_QUADS);
    glVertex3f(60, 90, 0);
    glVertex3f(78, 90, 0);

    glVertex3f(78, 95, 0);
    glVertex3f(60, 95, 0);


glEnd();

glPopMatrix();


//score
/*
std::stringstream sc;
sc << score;
std::string sco = sc.str();
*/
char sco[10]={'\0'};
sprintf(sco, "%d", score);
char heal[10]={'\0'};
sprintf(heal, "%d", health);

char tm2[10]={'\0'};
sprintf(tm2, "%f", tm);


glColor3f(1.0,0.5,!mb);


drawLetter("SCORE:", 20, 450);
drawLetter(sco, 130, 450);
drawLetter("HEALTH:", 20, 420);
drawLetter(heal , 130, 420);

drawLetter("TIME:", 500, 450);
drawLetter(tm2 , 560, 450);

glEnd();


glutSwapBuffers();

glFlush();
}

void update(int value) {

    time +=1;
    tm-=.01;
    a-= 1; //box 1
    if(a<-240){a+=880+rand()%1800; boxy=10+rand()%60;}

    a2-= 1; //box 2
    if(a2<-240){a2+=880+rand()%1800; box2y=10+rand()%60;}

    b-= .05; //building motion
    if(b<-680){b+=1300;}

    c-= .5; //coin
    if(c<0){c+=640;}

    e-= 1; //railing
    if(e<-640){e+=640;}

    cloudpos -=.05;
    if(cloudpos<-700){cloudpos+=1700+rand()%300;}

    coin1x-= 1;
    if(coin1x<-240){coin1x+=1280;}

    coin2x-= 1;
    if(coin2x<-240){coin2x+=1280;}


    coin3x-= 1;
    if(coin3x<-240){coin3x+=1280;}

    coin4x-= 1;
    if(coin4x<-240){coin4x+=1280;}

    d-=1;
    if(d<-340){d+=1880+rand()%200;}

    moonpos -= .25;
    if(moonpos<-600){moonpos+=750; day++;}
    //day detection
    if(day%2){mb=0.0; hr=.6; hg=1.0; hb=1.0; bb=0.88; bg=0.88; br = 0.88; rr=.64; rg=.8; rb=.8; fc=.8; cc=1; starr=.6;} //if day
    else {mb=1.0; hr=0.06; hg=0.3; hb = 0.38; bb=0; bg=0; br=0; rr=.2; rg=0; rb=.4; fc=.3; cc=.12; starr=1;}
    //collision detection



    if((coin1x-100)==(posx) && posy >= coin1y-20 && posy <= coin1y+10 ){coin1x= -150 + rand()%100; coin1y = 10+rand()%60;  score+=5; tm=15;}
    if((coin2x)==(posx) && posy >= coin2y-20 && posy <= coin2y+10 ){coin2x=-200 + rand()%100; coin2y = 10+rand()%60; score+=5; tm=15;}
    if((coin3x-100)==(posx) && posy >= coin3y-20 && posy <= coin3y+10 ){coin3x= -150 + rand()%100; coin3y = 10+rand()%60; score+=5; tm=15;}
    if((coin4x)==(posx) && posy >= coin4y-20 && posy <= coin4y+10 ){coin4x=-200 + rand()%100; coin4y = 10+rand()%60; score+=5; tm=15;}

    if((a+100)==(posx) && posy >= boxy-20 && posy <= boxy+20 ){a+=250 + rand()%100; health-=25; }
    if((a2+100)==(posx) && posy >= box2y-20 && posy <= box2y+20 ){a2+=250 + rand()%100; health-=25; }

    if((d+220)==(posx) && posy >= hy-20 && posy <= hy+20 ){d-=250 - rand()%100; if(health<81){health+=20;} else{health=100;} }


    //per object collision

   // if(a2>=(a-20) && a2<=(a+20) && box2y>=(boxy-30) && box2y<=(boxy+30) ){a2+=400;, box2y=10+rand()%120;}


 //game over


    if(health<1){gameover();}
    if(tm<0){gameover();}
	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(10, update, 0);
}





void keyboard(unsigned char key, int x, int y)
{


if(key=='w'){if(posy<90){posy+=10;glutPostRedisplay();}}
else if(key=='s'){if(posy>-50){posy-=10; glutPostRedisplay();}}
//else if(key=='a'){if(posx>0){a+=5; glutPostRedisplay();}}
else if(key=='d'){if(posx<500){/*a-=5; coin1x-=5; coin2x-=5;*/ glutPostRedisplay();}}

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


