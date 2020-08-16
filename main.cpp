#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416

    GLint i, j, k;
    static GLfloat spin = 0.0;
    static float	tx	=  0.0;
    static float	tx2	=  0.0;
    static float	ty	=  0.0;
    static float	tx1	=  0.0;
    static float	ty1	=  0.0;
    int night =0;

void init(void)
{
        glClearColor(30.0f/255.0f, 28.0f/255.0f, 78.0f/255.0f, 0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void Cloud_movement(void)
{
      tx +=0.05;
      if (tx > 200.0)
      tx = tx - 400.0;

      tx2 +=0.02;
      if (tx2 > 200.0)
      tx2 = tx2 - 400.0;

      glutPostRedisplay();

}
void comic_movement(void)
{
        ty1 -=0.1;
        tx1 -=0.1;

       glutPostRedisplay();

}

void circle(GLdouble rad, GLdouble x, GLdouble y)

{
        GLint points = 360;
        GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
        GLdouble theta = 0.0;

        glBegin(GL_TRIANGLE_FAN);
        {
            for( i = 0; i <=360; i++, theta += delTheta )
            {
                glVertex2f(x+rad * cos(theta),y+rad * sin(theta));
            }
        }
        glEnd();
}

void half_circle(GLdouble rad, GLdouble x, GLdouble y)

{
        GLint points = 180;
        GLdouble delTheta =  PI / (GLdouble)points;
        GLdouble theta = 0.0;

        glBegin(GL_TRIANGLE_FAN);
        {
            for( i = 0; i <=180; i++, theta += delTheta )
            {
                glVertex2f(x+rad * cos(theta),y+rad * sin(theta));
            }
        }
        glEnd();
}
void hill()
{

        glColor3ub(15, 23, 67);

        circle(250,250,-100);
        glColor3ub(32, 30, 84);

        int x1=150,y1=140,x2=180,y2=130;
        for(int i=0; i<=13; i++)
           {
                glRectf(x1,y1,x2,y2);
                x1=x1-30;
                x2=x2-10;
                y1=y1-10;
                y2=y2-10;

           }

        x1=320,y1=140,x2=350,y2=130;
        for( i=0; i<=13; i++)
          {
                glRectf(x1,y1,x2,y2);
                x1=x1+10;
                x2=x2+30;
                y1=y1-10;
                y2=y2-10;

          }

}


void house ()
{

        glColor3ub(15, 18, 57);
        glBegin(GL_POLYGON);
        glVertex2f(200,140);
        glVertex2f(300,140);
        glVertex2f(300,170);
        glVertex2f(200,170);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(200,170);
        glVertex2f(250,210);
        glVertex2f(300,170);
        glEnd();

        glColor3ub(108, 107, 185);
        glBegin(GL_POLYGON);
        glVertex2f(200,170);
        glVertex2f(250,210);
        glVertex2f(250,205);
        glVertex2f(200,165);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(300,170);
        glVertex2f(250,210);
        glVertex2f(250,205);
        glVertex2f(300,165);
        glEnd();

        glColor3ub(15, 18, 57);
        glBegin(GL_POLYGON);
        glVertex2f(230,140);
        glVertex2f(230,210);
        glVertex2f(250,225);
        glVertex2f(270,210);
        glVertex2f(270,140);
        glEnd();


        glColor3ub(108, 107, 185);
        glBegin(GL_POLYGON);
        glVertex2f(227.5,210);
        glVertex2f(250,225);
        glVertex2f(250,220);
        glVertex2f(230,205);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(272.5,210);
        glVertex2f(250,225);
        glVertex2f(250,220);
        glVertex2f(270,205);
        glEnd();

        //window
        glColor3ub(233, 129, 40);
        glRectf(205,150,210,160);
        glRectf(220,150,225,160);
        glRectf(290,150,295,160);
        glRectf(275,150,280,160);
        glRectf(246.25,195,253.75,210);

         //door
        glColor3ub(108, 107, 185);
        glRectf(240,140,260,170);


}

void tower()
{

        glColor3ub(15, 18, 57);
        glBegin(GL_TRIANGLES);
        glVertex2f(297.5,200);
        glVertex2f(302.5,210);
        glVertex2f(307.5,200);
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(295,135);
        glVertex2f(310,135);
        glVertex2f(307.5,200);
        glVertex2f(297.5,200);
        glEnd();

        glColor3ub(233, 129, 40);
        glRectf(301,185,304,190);

}

void moon()
{

        glColor3ub(35, 36, 96);
        circle(50,150,350);
        glColor3ub(46, 47, 119);
        circle(35,150,350);
        glColor3ub(101, 101, 155);
        circle(25,150,350);
        glColor3ub(255, 255, 255);
        circle(20,150,350);

}
void cloud()
{

        glColor3ub(49, 49, 124);

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        half_circle(20,150,250);
        half_circle(10,125,250);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(20,250,450);
        half_circle(10,225,450);
        half_circle(15,275,450);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        half_circle(25,350,300);
        half_circle(20,320,300);
        half_circle(15,375,300);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        half_circle(20,150,150);
        half_circle(10,121,150);
        half_circle(15,175,150);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(20,350,150);
        half_circle(10,375,150);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(20,425,150);
        half_circle(10,410,150);
        half_circle(15,450,150);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        half_circle(20,70,350);
        half_circle(10,50,350);
        half_circle(15,95,350);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        half_circle(20,350,400);
        half_circle(15,375,400);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(20,450,250);
        half_circle(10,421,250);
        half_circle(15,475,250);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(20,50,450);
        half_circle(10,21,450);
        half_circle(15,75,450);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx2,ty,0);
        glColor3ub(41, 40, 96);
        half_circle(20,50,220);
        half_circle(10,21,220);
        half_circle(15,75,220);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(tx,ty,0);
        half_circle(15,200,200);
        half_circle(10,180,200);
        half_circle(15,215,200);
        glPopMatrix();

}


void stars()
{

         glColor3ub(158, 249, 254);
         circle(1,50,450);
         circle(1,50,450);
         circle(1,200,400);
         circle(1,150,275);

         circle(1,250,350);
         circle(1,390,440);
         circle(1,300,250);
         circle(1,25,275);

         circle(1,450,350);
         circle(1,125,375);
         circle(1,175,475);
         circle(1,250,150);

         circle(1,50,470);
         circle(1,60,460);
         circle(1,80,485);
         circle(1,95,460);
         circle(1,102,470);

         circle(1,120,450);
         circle(1,150,420);
         circle(1,160,445);
         circle(1,200,430);
         circle(1,250,400);

         circle(1,350,470);
         circle(1,360,440);
         circle(1,390,485);
         circle(1,425,490);
         circle(1,450,470);

         circle(1,220,450);
         circle(1,280,410);
         circle(1,320,445);
         circle(1,270,480);
         circle(1,300,400);

         ////
         circle(1,10,370);
         circle(1,60,360);
         circle(1,30,385);
         circle(1,95,360);
         circle(1,102,370);

         circle(1,120,350);
         circle(1,150,320);
         circle(1,160,345);
         circle(1,200,330);
         circle(1,250,300);

         circle(1,350,370);
         circle(1,360,340);
         circle(1,390,385);
         circle(1,425,390);
         circle(1,450,370);

         circle(1,220,350);
         circle(1,280,310);
         circle(1,320,345);
         circle(1,270,380);
         circle(1,300,300);

         ///
         circle(1,10,270);
         circle(1,60,260);
         circle(1,30,285);
         circle(1,95,260);
         circle(1,102,270);

         circle(1,120,250);
         circle(1,150,220);
         circle(1,160,245);
         circle(1,200,230);
         circle(1,250,200);

         circle(1,350,270);
         circle(1,360,240);
         circle(1,390,285);
         circle(1,425,290);
         circle(1,450,270);

         circle(1,220,250);
         circle(1,280,210);
         circle(1,320,245);
         circle(1,270,280);
         circle(1,300,200);


         ////
         circle(1,10,170);
         circle(1,60,160);
         circle(1,30,185);
         circle(1,95,160);
         circle(1,102,170);

         circle(1,120,150);
         circle(1,150,120);
         circle(1,160,145);
         circle(1,200,130);
         circle(1,250,100);

         circle(1,350,170);
         circle(1,360,140);
         circle(1,390,185);
         circle(1,425,190);
         circle(1,450,170);

         circle(1,220,150);
         circle(1,280,110);
         circle(1,320,145);
         circle(1,270,180);
         circle(1,300,100);

    ///


        circle(1,470,450);
        circle(1,495,400);
        circle(1,480,340);
        circle(1,460,210);
        circle(1,490,150);


        glColor3ub(214, 224, 245);
        glPushMatrix();
        glTranslatef(tx1,ty1,0);
        circle(6,350,400);
        glBegin(GL_TRIANGLES);
        {
          glVertex2f(400,450);
          glVertex2f(355,400);
          glVertex2f(350,405);
          glEnd();

        }
        glPopMatrix();

}


void display1()
{

          if (night==1)
          {

             stars();
             tower();
             hill();
             house();

          }
         else
         {

             moon();
             cloud();
             tower();
             hill();
             house();

         }

}

void display(void)
{

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_QUADS);//gradient
        glColor3ub(30, 28, 78);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glColor3ub(38, 36, 102);
        glVertex2f(500, 500);
        glVertex2f(0, 500);
        glEnd();

        display1();
        glFlush();

}


void my_keyboard(unsigned char key, int x, int y)
{

        switch (key) {

            case 'n':
                 night=1;
                glutIdleFunc(display1);
                break;

            case 'N':
                  glutIdleFunc(display1); ;
                break;


           default:
                break;
        }
}



void my_mouse(int button, int state, int x, int y)
{
       switch (button) {
          case GLUT_LEFT_BUTTON:
             if (state == GLUT_DOWN)
             {
             glutIdleFunc(Cloud_movement);
             }
             break;
          case GLUT_MIDDLE_BUTTON:
          case GLUT_RIGHT_BUTTON:
             if (state == GLUT_DOWN)
                glutIdleFunc(comic_movement);
             break;
          default:
             break;
       }
}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(900, 1900);
	glutCreateWindow("Farm House On a Hill");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutMouseFunc(my_mouse);
	glutMainLoop();
}
