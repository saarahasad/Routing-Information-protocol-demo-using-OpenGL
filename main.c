#include <math.h>        // For math routines (such as sqrt & trig).

#include <stdio.h>

#include <GLUT/glut.h>

#include<string.h>

#include<stdio.h>

#include<stdlib.h>

#
define monitor 1# define PI 3.1415927
int i;
int sflag = 0;
int count;
GLfloat right = -15.0 f;
GLfloat top = 0.0 f;
GLfloat right1 = 0.0 f;
GLfloat down = 0.0 f;
GLfloat right2 = 0.0 f;
GLfloat right3 = 0.0 f;
int finish = 0;
static int flag = 1;
int colorflag = 0;
void * fonts[] = {
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24,
};
void Timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(1400, Timer, 0);
}
int source = 0;
int dest = 0;
void draw_cylinder(GLfloat radius,
  GLfloat height,
  GLubyte R,
  GLubyte G,
  GLubyte B, GLfloat diff, GLfloat hdiff) {
  GLfloat x = 10.0;
  GLfloat y = 10.0;
  GLfloat angle = 0.0;
  GLfloat angle_stepsize = 0.1;

  /** Draw the tube */
  glColor3ub(R - 0, G - 56, B - 45);
  glBegin(GL_QUAD_STRIP);
  angle = 0.0;
  while (angle < 2 * PI) {
    x = radius * cos(angle);
    y = radius * sin(angle);
    glVertex3f(x - diff, y - hdiff, height);
    glVertex3f(x - diff, y - hdiff, 0.0);
    angle = angle + angle_stepsize;
  }
  glVertex3f(radius - diff, 0.0 - hdiff, height);
  glVertex3f(radius - diff, 0.0 - hdiff, 0.0);
  glEnd();

  /** Draw the circle on top of cylinder */
  glColor3ub(R, G, B);
  glBegin(GL_POLYGON);
  angle = 0.0;
  while (angle < 2 * PI) {
    x = radius * cos(angle);
    y = radius * sin(angle);
    glVertex3f(x - diff, y - hdiff, height);
    angle = angle + angle_stepsize;
  }
  glVertex3f(radius - diff, 0.0 - hdiff, height);

  glEnd();
}

void printCust(char * ptr, GLfloat x, GLfloat y, GLfloat z) {
  int len = strlen(ptr);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(x, y, z);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ptr[i]);
}
void textures() {
  char * ptr = "10.0.0.0/8";
  int len = strlen(ptr);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-38.0, 41.0, 0.0);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-43, -21, 0.0);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr[i]);

  char * ptr1 = "F0/1";
  int len1 = strlen(ptr1);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-32., 7.0, 00.0);
  for (i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
  glRasterPos3f(30.0, 5.0, 0.0);
  for (int i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr1[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-29, -21, 0.0);
  for (int i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(32, -21, 0.0);
  for (int i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);

  char * ptr2 = "S0/0";
  int len2 = strlen(ptr2);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-19.5, 0, 00.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-9.0, -2, 00.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glRasterPos3f(16.0, -3, 00.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-29, -25, 0.0);
  for (int i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(0, -21, 0.0);
  for (int i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(32, -25, 0.0);
  for (int i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);

  char * ptr3 = "S0/1";
  int len3 = strlen(ptr3);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(5.0, 2, 00.0);
  for (i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr3[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(0, -25, 0.0);
  for (int i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr3[i]);

  char * ptr4 = "20.0.0.0/8";
  int len4 = strlen(ptr4);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(31, 41, 0.0);
  for (i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr4[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(18, -21, 0.0);
  for (int i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr4[i]);

  char * ptr5 = "192.168.1.252/30";
  int len5 = strlen(ptr5);
  glColor3f(0.0, 0.0, 0.0);
  glRasterPos3f(-20, -5, 2.0);
  for (i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);
  glRasterPos3f(-13, 4, 2.0);
  for (i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-44, -25, 0.0);
  for (int i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr5[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-15, -21, 0.0);
  for (int i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr5[i]);

  char * ptr6 = "192.168.1.248/30";
  int len6 = strlen(ptr6);
  glColor3f(0.0, 0.0, 0.0);
  glRasterPos3f(4, -5, 2.0);
  for (i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);
  glRasterPos3f(11.5, 4, 2.0);
  for (i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-15, -25, 0.0);
  for (int i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(16, -25, 0.0);
  for (int i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

  char * r1 = "R1";
  int lenr1 = strlen(r1);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-26, -10, 2.0);
  for (i = 0; i < lenr1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, r1[i]);

  char * r2 = "R2";
  int lenr2 = strlen(r2);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-1, -10, 2.0);
  for (i = 0; i < lenr2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, r2[i]);

  char * r3 = "R3";
  int lenr3 = strlen(r3);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(25, -10, 2.0);
  for (i = 0; i < lenr3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, r3[i]);

  char * r4 = "R4";
  int lenr4 = strlen(r4);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-21, 16, 2.0);
  for (i = 0; i < lenr4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, r4[i]);

  char * r5 = "R5";
  int lenr5 = strlen(r5);
  glColor3f(0.0, 0.0, 0.0);
  glRasterPos3f(18, 16, 2.0);
  for (i = 0; i < lenr5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, r5[i]);

  char * ptr7 = "Network";
  int len7 = strlen(ptr7);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-43, -17, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ptr7[i]);
  glRasterPos3f(-13, -17, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ptr7[i]);
  glRasterPos3f(17.5, -17, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ptr7[i]);
  glRasterPos3f(-22.5, 46, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ptr7[i]);
  glRasterPos3f(5.5, 46, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ptr7[i]);

  char * ptr8 = "Port";
  int len8 = strlen(ptr8);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-29, -17, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(0, -17, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(31, -17, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(-9.5, 46, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(18.5, 46, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glFlush();

}
void table(GLfloat x1, GLfloat x2, GLfloat y) {

  glColor3f(0.439, 0.502, 0.565);
  glBegin(GL_LINE_STRIP);
  glLineWidth(.2);

  glVertex2f(x1, y);
  glVertex2f(x2, y);
  glVertex2f(x2, y - 3);

  glVertex2f(x1, y - 3);
  glVertex2f(x1, y);
  glVertex2f(x1, y - 6);
  glVertex2f(x2, y - 6);
  glVertex2f(x2, y);

  glVertex2f(x2, y - 9);
  glVertex2f(x1, y - 9);
  glVertex2f(x1, y - 6);

  glVertex2f(x1, y - 12);
  glVertex2f(x2, y - 12);
  glVertex2f(x2, y - 9);

  glVertex2f(x2, y - 15);
  glVertex2f(x1, y - 15);
  glVertex2f(x1, y - 12);

  glVertex2f(x1, y - 18);
  glVertex2f(x2, y - 18);
  glVertex2f(x2, y - 15);

  glVertex2f(x2, y - 21);
  glVertex2f(x1, y - 21);
  glVertex2f(x1, y - 18);

  glEnd();
}
void Write(double x, double y, double z, double scale, char * s) {
  int i, l = strlen(s);

  glRasterPos3f(x, y, z);
  for (i = 0; i < l; i++) {
    glColor3f(0.0, 0.0, 0.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
  }
  glPopMatrix();
}
void page1() {
  glClearColor(0.75, 0.87, 0.85, 1.0);

  glClear(GL_COLOR_BUFFER_BIT);

  glLineWidth(3.0);

  glColor3f(0.71 f, 0.41 f, 0.41 f);

  Write(-1.5, 2.5, 0.0, 0.006, "    ATRIA INSTITUTE OF TECHNOLOGY");

  glColor3f(0.23 f, 0.23 f, 0.21 f);
  glLineWidth(2.0);
  Write(-1.1, 2.0, 0.1, 0.008, "    Graphical Implementation of");

  glColor3f(0.71 f, 0.41 f, 0.41 f);

  glLineWidth(2.0);

  Write(-1.6, 1.9, -0.6, 0.002, "ROUTING INFORMATION PROTOCOL");

  glColor3f(0.0, 0.0, 0.0);

  glLineWidth(2.0);

  Write(-1.2, 0.7, 0.0, 0.0015, "              Submitted By:        ");

  glColor3f(0.71 f, 0.41 f, 0.41 f);

  glLineWidth(2.3);

  Write(-2.5, -0.1, 0.0, 0.0015, "  Payal.A.Makhija                                                       Saarah Asad");

  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glLineWidth(2.3);

  Write(-2.5, -0.3, 0.0, 0.0014, " (1AT15CS062)                                                       (1AT15CS080)");

  glColor3f(0.0, 0.0, 0.0);

  Write(-0.6, -0.9, 0.0, 0.0014, "Press 'c' to continue");

  glColor3f(0.0, 0.0, 0.0);

  glLineWidth(2.0);

  Write(-1.1, -1.5, 0.0, 0.0015, "          Under The Guidance Of:    ");

  glColor3f(0.0, 0.0, 0.0);

  Write(-0.9, -1.7, 0.0, 0.0015, "           Prof. Goutam        ");

  glColor3f(0.0, 0.0, 0.0);

  Write(-1.1, -1.9, 0.0, 0.0015, "          Lecturer,Dept. of CS&E      ");
  glFlush();
}

void page2() {
  glClearColor(0.75, 0.87, 0.85, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-1.98 f, 2.8 f, 1.95 f, 2.3 f);
  // Write(-2.18,1.3,-0.6,0.002,"ROUTING INFORMATION PROTOCOL");
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-2.5 f, 2.95 f, -2.45 f, -2.3 f);
  glRectf(2.5 f, 2.95 f, 2.55 f, -2.3 f);

  printCust("MENU", -0.4, 2.45, 0);
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-1.98 f, 1.8 f, 1.95 f, 1.32 f);
  // draw rect
  printCust("-----", -0.4, 2.36, 0);
  printCust("1 ->  Introduction", -1.3, 1.5, 0);
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-1.98 f, 0.65 f, 1.95 f, 1.1 f);
  printCust("2 ->  Creation of Routing Tables", -1.3, 0.8, 0);
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-1.98 f, 0.0 f, 1.95 f, 0.42 f);
  printCust("3 ->  Advertisements", -1.3, 0.15, 0);
  glColor3f(0.71 f, 0.41 f, 0.41 f);
  glRectf(-1.98 f, -0.63 f, 1.95 f, -0.18 f);
  printCust("4 ->  Exit", -1.3, -0.45, 0);
  glFlush();
}
void texturespage3() {

  char * hop1 = "1";
  int hop1len = strlen(hop1);
  glColor3f(0.2, 0.6, 1.2);;
  glRasterPos3f(0, 44, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(-24, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(-24, -22, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(9, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(40, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(40, -22, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  char * hyphen = "-";
  int hyphenlen = strlen(hyphen);
  glColor3f(0.2, 0.6, 1.2);;
  glRasterPos3f(-11, 44, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);
  glRasterPos3f(-35, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);
  glRasterPos3f(-35, -22, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);
  glRasterPos3f(-2, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);
  glRasterPos3f(30, -19, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);
  glRasterPos3f(30, -22, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hyphen[i]);

  char * ptr = "10.0.0.0/8";
  int len = strlen(ptr);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-38.0, 41.0, 0.0);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-47, -19, 0.0);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr[i]);

  char * ptr1 = "192.168.1.242/30";
  int len1 = strlen(ptr1);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-20, 20.0, 00.0);
  for (i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-24, 44, 0.0);
  for (i = 0; i < len1; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr1[i]);

  char * ptr2 = "192.168.1.244/30";
  int len2 = strlen(ptr2);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(35, -10, 2.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(16, -22, 0.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr2[i]);

  char * ptr4 = "20.0.0.0/8";
  int len4 = strlen(ptr4);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(31, 41, 0.0);
  for (i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr4[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(18, -19, 0.0);
  for (int i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr4[i]);

  char * ptr5 = "192.168.1.252/30";
  int len5 = strlen(ptr5);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-47, -5, 2.0);
  for (i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr5[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-48, -22, 0.0);
  for (int i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);

  char * ptr6 = "192.168.1.248/30";
  int len6 = strlen(ptr6);
  glColor3f(1.0, 1.0, 1.0);
  glRasterPos3f(-20, -7, 2.0);
  for (i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-15, -19, 0.0);
  for (int i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);

  char * dest1 = "B";
  int des1len = strlen(dest1);
  glColor3f(1, 0, 0);
  glRasterPos3f(0, -10, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest1[i]);

  char * dest4 = "D";
  int des4len = strlen(dest4);
  glColor3f(1, 0, 0);
  glRasterPos3f(0, 12, 0.0);
  for (int i = 0; i < des4len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest4[i]);

  char * dest5 = "C";
  int des5len = strlen(dest5);
  glColor3f(1, 0, 0);
  glRasterPos3f(23, -10, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest5[i]);

  char * dest8 = "A";
  int des8len = strlen(dest8);
  glColor3f(1, 0, 0);
  glRasterPos3f(-25, -10, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest8[i]);

  char * ptr7 = "Dest. Network";
  int len7 = strlen(ptr7);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-47.1, -16, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr7[i]);
  glRasterPos3f(-14, -16, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr7[i]);
  glRasterPos3f(16.5, -16, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr7[i]);
  glRasterPos3f(-24, 47, 0.0);
  for (i = 0; i < len7; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr7[i]);

  char * ptr8 = "Next Router";
  int len8 = strlen(ptr8);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-37, -16, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(-4, -16, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(27, -16, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);
  glRasterPos3f(-13, 47, 0.0);
  for (i = 0; i < len8; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);

  char * ptr9 = "Hops";
  int len9 = strlen(ptr9);
  glColor3f(1.0, 0.0, 0.0);
  glRasterPos3f(-25, -16, 0.0);
  for (i = 0; i < len9; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr9[i]);
  glRasterPos3f(8, -16, 0.0);
  for (i = 0; i < len9; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr9[i]);
  glRasterPos3f(38, -16, 0.0);
  for (i = 0; i < len9; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr9[i]);
  glRasterPos3f(-1, 47, 0.0);
  for (i = 0; i < len9; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr9[i]);

}

void page3() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);

  glLineWidth(2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -50, 50);

  glClear(GL_COLOR_BUFFER_BIT); // clears the screen
  glBegin(GL_POLYGON);
  glColor3ub(201, 201, 201); //stand
  glVertex3f(-35.50, 26.0, -10.0);
  glVertex3f(-35.50, 23.0, -10.0);
  glVertex3f(-32.0, 23.0, -10.0);
  glVertex3f(-32.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(176, 176, 176); //stand
  glVertex2f(-36.5, 23.0);
  glVertex2f(-31.0, 23.0);
  glVertex2f(-31.0, 22.0);
  glVertex2f(-36.5, 22.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7); // outer monitor
  glBegin(GL_LINE_LOOP);
  glVertex2f(-40.0, 25.5);
  glVertex2f(-28.0, 25.5);
  glVertex2f(-28.0, 38.5);
  glVertex2f(-40.0, 38.5);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //inner monitor
  glBegin(GL_LINE_LOOP);
  glVertex2f(-39.5, 26.0);
  glVertex2f(-28.5, 26.0);
  glVertex2f(-28.5, 38.0);
  glVertex2f(-39.5, 38.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_LINE_LOOP);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-28.0, 21.0);
  glVertex2f(-39.0, 21.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_POLYGON);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-27.0, 16.0);
  glVertex2f(-40.0, 16.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //horizontal lines of keyboard
  glBegin(GL_LINES);
  glVertex2f(-39.8, 18);
  glVertex2f(-27.2, 18);
  glVertex2f(-39.5, 19);
  glVertex2f(-27.5, 19);
  glVertex2f(-39.2, 20);
  glVertex2f(-27.8, 20);
  glVertex2f(-33.2, 21);
  glVertex2f(-33.2, 17);
  glVertex2f(-35, 21);
  glVertex2f(-35.4, 17);
  glVertex2f(-37, 21);
  glVertex2f(-37.8, 17);

  glEnd();
  glFlush();

  //COMPUTER 2
  glBegin(GL_POLYGON);
  glColor3ub(164, 211, 238); //stand
  glVertex3f(34.50, 26.0, -10.0);
  glVertex3f(34.50, 23.0, -10.0);
  glVertex3f(38.0, 23.0, -10.0);
  glVertex3f(38.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(0.2, 0.3, .4); //stand
  glVertex2f(33.5, 23.0);
  glVertex2f(39.0, 23.0);
  glVertex2f(39.0, 22.0);
  glVertex2f(33.5, 22.0);
  glEnd();
  glBegin(GL_QUAD_STRIP);
  glColor3ub(141, 182, 205);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 25.0);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 38.5);
  glVertex2f(42.0, 25.0);
  glEnd();

  glBegin(GL_POLYGON); //monitor
  glColor3ub(191, 239, 255);
  glVertex2f(31.0, 26.0);
  glVertex2f(41.0, 26.0);
  glVertex2f(41.0, 38.0);
  glVertex2f(31.0, 38.0);
  glEnd();
  //keyboard
  glBegin(GL_POLYGON);
  glColor3ub(224, 255, 255);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(42.0, 21.0);
  glVertex2f(31.0, 21.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(108, 166, 205);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(43.0, 16.0);
  glVertex2f(30.0, 16.0);
  glEnd();

  //Computer 1 and router 1 connection
  glLineWidth(0);
  glBegin(GL_LINES);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-35.0, 17.0);
  glVertex2f(-26.0, 6.0);
  glEnd();

  //router 1 and network 252
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-26.0, 0.0);
  glVertex2f(-36.0, -5.0);
  glEnd();

  //router 1 and router 2 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-20.00, 0.00);

  glVertex2f(0.00, 0.00);
  glEnd();

  //router 2 and network 248
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(0, 0.0);
  glVertex2f(-11, -5.0);
  glEnd();

  //router 3 and network 244
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(22, 0.0);
  glVertex2f(35, -7.0);
  glEnd();

  //router 4 and network 242
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-2, 22.0);
  glVertex2f(-10, 20.0);
  glEnd();

  //router 2 and router 3 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(5.00, 0.00);
  glVertex2f(20.00, 0.00);
  glEnd();

  //router 3 and computer 2 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(25.00, 0.00);
  glVertex2f(35.00, 16.00);
  glEnd();

  //router 1 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-25.00, 3.00);
  glVertex2f(0, 20);
  glEnd();

  //router 3 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(4, 20);
  glVertex2f(23.00, 1);

  glEnd();

  //text

  texturespage3();

  char * ptr3 = "Press 's' to send out advertisements";
  int len3 = strlen(ptr3);
  glColor3ub(188, 143, 143);
  glRasterPos3f(-10.0, -40, 00.0);
  for (i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr3[i]);

  //tables
  //table for router 1
  table(-49.00, -39.0, -14);
  table(-39.00, -29.0, -14);
  table(-29.00, -19.0, -14);

  //table for router 2
  table(-16.00, -6.0, -14);
  table(-6.00, 4.0, -14);
  table(4.00, 14.0, -14);

  //table for router 3
  table(15.00, 25.0, -14);
  table(25.00, 35.0, -14);
  table(35.00, 45.0, -14);

  //table for router 4
  table(-25.00, -15.0, 49);
  table(-15.00, -5.0, 49);
  table(-5.00, 5.0, 49);

  /*  //table for router 5
   table(3.00, 15.0, 49);
   table(15.00, 27.0, 49);*/

  //ROUTERS
  glTranslatef(0.0, -0.4, -3.0);
  glRotatef(-5, 1.0, 0.0, 0.0);
  draw_cylinder(5.24, 19.20, 187, 255, 255, 25, 0);
  draw_cylinder(5.24, 19.20, 255, 255, 153, 0, 0);
  draw_cylinder(5.24, 19.20, 255, 192, 203, -25, 0);
  draw_cylinder(5.24, 19.20, 193, 255, 193, 0, -22);
  // draw_cylinder(5.24, 19.20, 23, 160, 100,-13,-22);

  glutSwapBuffers();
  glFlush();

}
int x;

//animation
void page4() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);

  glLineWidth(2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -50, 50);

  glClear(GL_COLOR_BUFFER_BIT); // clears the screen
  glBegin(GL_POLYGON);
  glColor3ub(201, 201, 201); //stand
  glVertex3f(-35.50, 26.0, -10.0);
  glVertex3f(-35.50, 23.0, -10.0);
  glVertex3f(-32.0, 23.0, -10.0);
  glVertex3f(-32.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(176, 176, 176); //stand
  glVertex2f(-36.5, 23.0);
  glVertex2f(-31.0, 23.0);
  glVertex2f(-31.0, 22.0);
  glVertex2f(-36.5, 22.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7); //vertical stand
  glBegin(GL_LINES);
  glVertex2f(105, 380);
  glVertex2f(105, 375);
  glVertex2f(129, 380);
  glVertex2f(129, 375);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //horizontal stand
  glBegin(GL_QUADS);
  glVertex2f(98, 370);
  glVertex2f(98, 375);
  glVertex2f(138, 375);
  glVertex2f(138, 370);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //CPU
  glBegin(GL_LINE_LOOP);
  glVertex2f(80, 350);
  glVertex2f(80, 370);
  glVertex2f(155, 370);
  glVertex2f(155, 350);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //CPU
  glBegin(GL_QUADS);
  glVertex2f(95, 360);
  glVertex2f(95, 365);
  glVertex2f(115, 365);
  glVertex2f(115, 360);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //CPU
  glBegin(GL_QUADS);
  glVertex2f(132, 358);
  glVertex2f(132, 361);
  glVertex2f(140, 361);
  glVertex2f(140, 358);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); // outer monitor
  glBegin(GL_LINE_LOOP);
  glVertex2f(-40.0, 25.5);
  glVertex2f(-28.0, 25.5);
  glVertex2f(-28.0, 38.5);
  glVertex2f(-40.0, 38.5);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //inner monitor
  glBegin(GL_LINE_LOOP);
  glVertex2f(-39.5, 26.0);
  glVertex2f(-28.5, 26.0);
  glVertex2f(-28.5, 38.0);
  glVertex2f(-39.5, 38.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_LINE_LOOP);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-28.0, 21.0);
  glVertex2f(-39.0, 21.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_POLYGON);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-27.0, 16.0);
  glVertex2f(-40.0, 16.0);
  glEnd();
  glFlush();

  glColor3f(0.9, 0.5, 0.7); //horizontal lines of keyboard
  glBegin(GL_LINES);
  glVertex2f(-39.8, 18);
  glVertex2f(-27.2, 18);
  glVertex2f(-39.5, 19);
  glVertex2f(-27.5, 19);
  glVertex2f(-39.2, 20);
  glVertex2f(-27.8, 20);
  glVertex2f(-33.2, 21);
  glVertex2f(-33.2, 17);
  glVertex2f(-35, 21);
  glVertex2f(-35.4, 17);
  glVertex2f(-37, 21);
  glVertex2f(-37.8, 17);

  glEnd();
  glFlush();

  //COMPUTER 2
  glBegin(GL_POLYGON);
  glColor3ub(164, 211, 238); //stand
  glVertex3f(34.50, 26.0, -10.0);
  glVertex3f(34.50, 23.0, -10.0);
  glVertex3f(38.0, 23.0, -10.0);
  glVertex3f(38.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(0.2, 0.3, .4); //stand
  glVertex2f(33.5, 23.0);
  glVertex2f(39.0, 23.0);
  glVertex2f(39.0, 22.0);
  glVertex2f(33.5, 22.0);
  glEnd();
  glBegin(GL_QUAD_STRIP);
  glColor3ub(141, 182, 205);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 25.0);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 38.5);
  glVertex2f(42.0, 25.0);
  glEnd();

  glBegin(GL_POLYGON); //monitor
  glColor3ub(191, 239, 255);
  glVertex2f(31.0, 26.0);
  glVertex2f(41.0, 26.0);
  glVertex2f(41.0, 38.0);
  glVertex2f(31.0, 38.0);
  glEnd();
  //keyboard
  glBegin(GL_POLYGON);
  glColor3ub(224, 255, 255);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(42.0, 21.0);
  glVertex2f(31.0, 21.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(108, 166, 205);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(43.0, 16.0);
  glVertex2f(30.0, 16.0);
  glEnd();

  //Computer 1 and router 1 connection
  glLineWidth(0);
  glBegin(GL_LINES);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-35.0, 17.0);
  glVertex2f(-26.0, 6.0);
  glEnd();

  //router 1 and network 252
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-26.0, 0.0);
  glVertex2f(-36.0, -5.0);
  glEnd();

  //router 1 and router 2 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-20.00, 0.00);

  glVertex2f(0.00, 0.00);
  glEnd();

  //router 2 and network 248
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(0, 0.0);
  glVertex2f(-11, -5.0);
  glEnd();

  //router 3 and network 244
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(22, 0.0);
  glVertex2f(35, -7.0);
  glEnd();

  //router 4 and network 242
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-2, 22.0);
  glVertex2f(-10, 20.0);
  glEnd();

  //router 2 and router 3 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(5.00, 0.00);
  glVertex2f(20.00, 0.00);
  glEnd();

  //router 3 and computer 2 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(25.00, 0.00);
  glVertex2f(35.00, 16.00);
  glEnd();

  //router 1 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-25.00, -3.00);
  glVertex2f(0, 21);
  glEnd();

  //router 3 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(4, 20);
  glVertex2f(23.00, 1);

  glEnd();

  //text

  texturespage3();

  //tables
  //table for router 1
  table(-49.00, -39.0, -14);
  table(-39.00, -29.0, -14);
  table(-29.00, -19.0, -14);

  //table for router 2
  table(-16.00, -6.0, -14);
  table(-6.00, 4.0, -14);
  table(4.00, 14.0, -14);

  //table for router 3
  table(15.00, 25.0, -14);
  table(25.00, 35.0, -14);
  table(35.00, 45.0, -14);

  //table for router 4
  table(-25.00, -15.0, 49);
  table(-15.00, -5.0, 49);
  table(-5.00, 5.0, 49);

  /*  //table for router 5
   table(3.00, 15.0, 49);
   table(15.00, 27.0, 49);*/

  //ROUTERS
  glTranslatef(0.0, -0.4, -3.0);
  glRotatef(-5, 1.0, 0.0, 0.0);
  draw_cylinder(5.24, 19.20, 187, 255, 255, 25, 0);
  draw_cylinder(5.24, 19.20, 255, 255, 153, 0, 0);
  draw_cylinder(5.24, 19.20, 255, 192, 203, -25, 0);
  draw_cylinder(5.24, 19.20, 193, 255, 193, 0, -22);
  // draw_cylinder(5.24, 19.20, 23, 160, 100,-13,-22);

  glutSwapBuffers();
  glFlush();
}
void page5() {

  glClearColor(0.75, 0.87, 0.85, 1.0);

  glClear(GL_COLOR_BUFFER_BIT);

  glLineWidth(3.0);

  glColor3f(0.71 f, 0.41 f, 0.41 f);

  Write(-1.5, 2.5, 0.0, 0.006, "    ROUTING INFORMATION PROTOCOL");

  glColor3f(0.23 f, 0.23 f, 0.21 f);

  glLineWidth(2.0);

  Write(-4.3, 2.0, 0.1, 0.008, "The Routing Information Protocol (RIP) is one of the oldest distance-vector routing protocols which employ the hop");
  Write(-4.3, 1.8, 0.1, 0.008, "count as a routing metric. Each RIP router maintains a routing table, which is a list of all the destinations (networks)");
  Write(-4.3, 1.6, 0.1, 0.008, "it knows how to reach, along with the distance to that destination. RIP uses a distance vector algorithm to decide which ");
  Write(-4.3, 1.4, 0.1, 0.008, " path to put a packet on to get to its destination. It stores in its routing table the distance for each network it knows");
  Write(-4.3, 1.2, 0.1, 0.008, "how to reach, along with the address of the next hop router (another router that is on one of the same networks) through");
  Write(-4.3, 1.0, 0.1, 0.008, "which a packet has to travel to get to that destination. Routers prefer shorter routes to longer routes when deciding which");
  Write(-4.3, 0.8, 0.1, 0.008, "of two versions of a route to program in the routing table.");
  Write(-4.3, 0.6, 0.1, 0.008, "                                                                                                                           ");
  Write(-4.3, 0.4, 0.1, 0.008, "Using RIP, each router sends its entire routing table to its closest neighbors (other routers to which this router is");
  Write(-4.3, 0.2, 0.1, 0.008, "directly) every 30 seconds. The neighbors in turn will pass the information on to their nearest neighbors, and so on,");
  Write(-4.3, 0.0, 0.1, 0.008, "until all RIP hosts within the network have the same knowledge of routing paths, a state known as convergence.");
  Write(-4.3, -0.2, 0.1, 0.008, "                                                                                                                           ");

  Write(-4.3, -0.4, 0.1, 0.008, "RIP uses a modified hop count as a way to determine network distance.  By default, if a router's neighbor owns a");
  Write(-4.3, -0.6, 0.1, 0.008, "destination network without using any other routers), that route has one hop, described as a cost of 1.");
  Write(-4.3, -0.8, 0.1, 0.008, "The maximum metric permitted by RIP is 16, which means that a route is unreachable.This means that the protocol");
  Write(-4.3, -1.0, 0.1, 0.008, "cannot scale to networks where there may be more than 15 hops to a given destination.");
  Write(-4.3, -1.2, 0.1, 0.008, "                                                                                                                           ");
  Write(-4.3, -1.4, 0.1, 0.008, "If a router crashes or a network connection is severed, the network discovers this because that router stops sending");
  Write(-4.3, -1.6, 0.1, 0.008, "updates to its neighbors, or stops sending and receiving updates along the severed connection.");
  Write(-4.3, -1.8, 0.1, 0.008, "If a given route in the routing table isn't updated across six successive update cycles (that is, for 180 seconds)");
  Write(-4.3, -2.0, 0.1, 0.008, " a RIP router will drop that route, letting the rest of the network know via its own updates");
  Write(-4.3, -2.2, 0.1, 0.008, " about the problem and begin the process of reconverging on a new network topology. From this project, we hope to");
  Write(-4.3, -2.4, 0.1, 0.008, " present this protocol graphically using the C language. ");

  glFlush();

}
void texturespage6() {
  glColor3f(0.2, 0.6, 1.2);
  char * ptr1_6 = "192.168.1.252/30";
  int len1_6 = strlen(ptr1_6);
  glRasterPos3f(-15, -22, 0.0);
  for (i = 0; i < len1_6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr1_6[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(16, -34, 0.0);
  for (i = 0; i < len1_6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr1_6[i]);
  glRasterPos3f(-24, 38, 0.0);
  for (i = 0; i < len1_6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr1_6[i]);

  char * ptr2 = "10.0.0.0/8";
  int len2 = strlen(ptr2);
  glRasterPos3f(-14, -25, 0.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr2[i]);
  glRasterPos3f(17, -31, 0.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr2[i]);
  glRasterPos3f(-23, 41, 0.0);
  for (i = 0; i < len2; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr2[i]);

  char * ptr3 = "20.0.0.0/8";
  int len3 = strlen(ptr3);
  glRasterPos3f(-14, -28, 0.0);
  for (i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr3[i]);
  glRasterPos3f(-47, -28, 0.0);
  for (int i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr3[i]);
  glRasterPos3f(-23, 35, 0.0);
  for (i = 0; i < len3; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr3[i]);

  char * ptr4 = "192.168.1.244/30";
  int len4 = strlen(ptr4);
  glRasterPos3f(-15, -31, 0.0);
  for (i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr4[i]);
  glRasterPos3f(-48, -31, 0.0);
  for (int i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr4[i]);
  glRasterPos3f(-24, 32, 0.0);
  for (i = 0; i < len4; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr4[i]);

  char * ptr5 = "192.168.1.242/30";
  int len5 = strlen(ptr5);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-15, -34, 0.0);
  for (i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);
  glRasterPos3f(-48, -34, 0.0);
  for (int i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);
  glRasterPos3f(16, -28, 0.0);
  for (i = 0; i < len5; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr5[i]);

  char * ptr6 = "192.168.1.248/30";
  int len6 = strlen(ptr6);
  glRasterPos3f(-48, -25, 0.0);
  for (int i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);
  glRasterPos3f(16, -25, 0.0);
  for (i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);
  glRasterPos3f(-24, 29, 0.0);
  for (i = 0; i < len6; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr6[i]);

  char * hop1 = "2";
  int hop1len = strlen(hop1);
  glRasterPos3f(-24, -25, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(-24, -34, 0.0);
  for (int i = 0; i < hop1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);
  glRasterPos3f(9, -22, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(9, -25, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(9, -28, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(9, -31, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(40, -25, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(40, -28, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(0, 41, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(0, 38, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(0, 35, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  glRasterPos3f(0, 32, 0.0);

  for (int i = 0; i < hop1len; i++)

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop1[i]);

  char * hop2 = "3";
  int hop2len = strlen(hop2);
  glRasterPos3f(-24, -28, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);
  glRasterPos3f(-24, -31, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);
  glRasterPos3f(9, -34, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);
  glRasterPos3f(40, -31, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);
  glRasterPos3f(40, -34, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);
  glRasterPos3f(0, 29, 0.0);
  for (int i = 0; i < hop2len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, hop2[i]);

  char * dest1 = "B";
  int des1len = strlen(dest1);
  glColor3f(1, 0, 0);
  glRasterPos3f(0, -10, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest1[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-34, -31, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);
  glRasterPos3f(-34, -28, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);
  glRasterPos3f(-34, -25, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);
  glRasterPos3f(30, -25, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);
  glRasterPos3f(30, -31, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);
  glRasterPos3f(30, -34, 0.0);
  for (int i = 0; i < des1len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest1[i]);

  char * dest4 = "D";
  int des4len = strlen(dest4);
  glColor3f(1, 0, 0);
  glRasterPos3f(0, 12, 0.0);
  for (int i = 0; i < des4len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest4[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-34, -34, 0.0);
  for (int i = 0; i < des4len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest4[i]);
  glRasterPos3f(30, -28, 0.0);
  for (int i = 0; i < des4len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest4[i]);

  char * dest5 = "C";
  int des5len = strlen(dest5);
  glColor3f(1, 0, 0);
  glRasterPos3f(23, -10, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest5[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-1, -34, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest5[i]);
  glRasterPos3f(-1, -31, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest5[i]);
  glRasterPos3f(-1, -28, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest5[i]);
  glRasterPos3f(-11, 32, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest5[i]);
  glRasterPos3f(-11, 35, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest5[i]);

  char * dest8 = "A";
  int des8len = strlen(dest8);
  glColor3f(1, 0, 0);
  glRasterPos3f(-25, -10, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dest8[i]);
  glColor3f(0.2, 0.6, 1.2);
  glRasterPos3f(-1, -25, 0.0);
  for (int i = 0; i < des5len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest8[i]);
  glRasterPos3f(-1, -22, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest8[i]);
  glRasterPos3f(-11, 29, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest8[i]);
  glRasterPos3f(-11, 38, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest8[i]);
  glRasterPos3f(-11, 41, 0.0);
  for (int i = 0; i < des8len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, dest8[i]);

}

void page6() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 0.0, 0.0);

  glLineWidth(2);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50, 50, -50, 50, -50, 50);

  glClear(GL_COLOR_BUFFER_BIT); // clears the screen
  glBegin(GL_POLYGON);
  glColor3ub(201, 201, 201); //stand
  glVertex3f(-35.50, 26.0, -10.0);
  glVertex3f(-35.50, 23.0, -10.0);
  glVertex3f(-32.0, 23.0, -10.0);
  glVertex3f(-32.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(176, 176, 176); //stand
  glVertex2f(-36.5, 23.0);
  glVertex2f(-31.0, 23.0);
  glVertex2f(-31.0, 22.0);
  glVertex2f(-36.5, 22.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.9, 0.5, 0.7); //outer monitor
  glVertex2f(-40.0, 25.5);
  glVertex2f(-28.0, 25.5);
  glVertex2f(-28.0, 38.5);
  glVertex2f(-40.0, 38.5);
  glEnd();

  //inner monitor
  glBegin(GL_LINE_LOOP);
  glVertex2f(-39.5, 26.0);
  glVertex2f(-28.5, 26.0);
  glVertex2f(-28.5, 38.0);
  glVertex2f(-39.5, 38.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_LINE_LOOP);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-28.0, 21.0);
  glVertex2f(-39.0, 21.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7); //keyboard outline
  glBegin(GL_POLYGON);
  glVertex2f(-40.0, 17.0);
  glVertex2f(-27.0, 17.0);
  glVertex2f(-27.0, 16.0);
  glVertex2f(-40.0, 16.0);
  glEnd();

  glColor3f(0.9, 0.5, 0.7); //horizontal lines of keyboard
  glBegin(GL_LINES);
  glVertex2f(-39.8, 18);
  glVertex2f(-27.2, 18);
  glVertex2f(-39.5, 19);
  glVertex2f(-27.5, 19);
  glVertex2f(-39.2, 20);
  glVertex2f(-27.8, 20);
  glVertex2f(-33.2, 21);
  glVertex2f(-33.2, 17);
  glVertex2f(-35, 21);
  glVertex2f(-35.4, 17);
  glVertex2f(-37, 21);
  glVertex2f(-37.8, 17);

  glEnd();

  //COMPUTER 2
  glBegin(GL_POLYGON);
  glColor3ub(164, 211, 238); //stand
  glVertex3f(34.50, 26.0, -10.0);
  glVertex3f(34.50, 23.0, -10.0);
  glVertex3f(38.0, 23.0, -10.0);
  glVertex3f(38.0, 26.0, -10.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(0.2, 0.3, .4); //stand
  glVertex2f(33.5, 23.0);
  glVertex2f(39.0, 23.0);
  glVertex2f(39.0, 22.0);
  glVertex2f(33.5, 22.0);
  glEnd();
  glBegin(GL_QUAD_STRIP);
  glColor3ub(141, 182, 205);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 25.0);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 38.5);
  glVertex2f(30.0, 25.0);
  glVertex2f(42.0, 38.5);
  glVertex2f(42.0, 25.0);
  glEnd();

  glBegin(GL_POLYGON); //monitor
  glColor3ub(191, 239, 255);
  glVertex2f(31.0, 26.0);
  glVertex2f(41.0, 26.0);
  glVertex2f(41.0, 38.0);
  glVertex2f(31.0, 38.0);
  glEnd();
  //keyboard
  glBegin(GL_POLYGON);
  glColor3ub(224, 255, 255);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(42.0, 21.0);
  glVertex2f(31.0, 21.0);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3ub(108, 166, 205);
  glVertex2f(30.0, 17.0);
  glVertex2f(43.0, 17.0);
  glVertex2f(43.0, 16.0);
  glVertex2f(30.0, 16.0);
  glEnd();

  //Computer 1 and router 1 connection
  glLineWidth(0);
  glBegin(GL_LINES);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-35.0, 17.0);
  glVertex2f(-26.0, 6.0);
  glEnd();

  //router 1 and network 252
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-26.0, 0.0);
  glVertex2f(-36.0, -5.0);
  glEnd();

  //router 1 and router 2 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-20.00, 0.00);

  glVertex2f(0.00, 0.00);
  glEnd();

  //router 2 and network 248
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(0, 0.0);
  glVertex2f(-11, -5.0);
  glEnd();

  //router 3 and network 244
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(22, 0.0);
  glVertex2f(35, -7.0);
  glEnd();

  //router 4 and network 242
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glVertex2f(-2, 22.0);
  glVertex2f(-10, 20.0);
  glEnd();

  //router 2 and router 3 connection
  glBegin(GL_LINE_STRIP);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(5.00, 0.00);
  glVertex2f(20.00, 0.00);
  glEnd();

  //router 3 and computer 2 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(25.00, 0.00);
  glVertex2f(35.00, 16.00);
  glEnd();

  //router 1 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(-25.00, -3.00);
  glVertex2f(0, 21);
  glEnd();

  //router 3 and router 4 connection
  glBegin(GL_LINES);
  glLineWidth(4);
  glColor3f(0.3, 0.3, 0.6);
  glVertex2f(4, 20);
  glVertex2f(23.00, 1);

  glEnd();

  //text

  texturespage3();
  texturespage6();

  //tables
  //table for router 1
  table(-49.00, -39.0, -14);
  table(-39.00, -29.0, -14);
  table(-29.00, -19.0, -14);

  //table for router 2
  table(-16.00, -6.0, -14);
  table(-6.00, 4.0, -14);
  table(4.00, 14.0, -14);

  //table for router 3
  table(15.00, 25.0, -14);
  table(25.00, 35.0, -14);
  table(35.00, 45.0, -14);

  //table for router 4
  table(-25.00, -15.0, 49);
  table(-15.00, -5.0, 49);
  table(-5.00, 5.0, 49);

  /*  //table for router 5
   table(3.00, 15.0, 49);
   table(15.00, 27.0, 49);*/

  //ROUTERS
  glTranslatef(0.0, -0.4, -3.0);
  glRotatef(-5, 1.0, 0.0, 0.0);
  draw_cylinder(5.24, 19.20, 187, 255, 255, 25, 0);
  draw_cylinder(5.24, 19.20, 255, 255, 153, 0, 0);
  draw_cylinder(5.24, 19.20, 255, 192, 203, -25, 0);
  draw_cylinder(5.24, 19.20, 193, 255, 193, 0, -22);
  // draw_cylinder(5.24, 19.20, 23, 160, 100,-13,-22);

  glutSwapBuffers();
  glFlush();

}
void print_table(char * ptr, float x, float y, float z) {
  int len = strlen(ptr);
  glColor3f(0.2, 0.6, 1.2);
  if (colorflag == 1) {
    glColor3f(0, 0, 0);
    colorflag = 0;
  }
  glRasterPos3f(x, y, z);
  for (int i = 0; i < len; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ptr[i]);

}
void anim() {
  finish = 1;
  float i, temp = 0.2;
  for (i = 3; i < 17; i = i + temp) // packets from router 4 to 3
  {
    glColor3f(0.137255, 0.556863, 0.198039);
    glBegin(GL_QUADS);
    glVertex2i(4 + i, 22 - i);
    glVertex2i(4 + i, 23 - i);
    glVertex2i(5 + i, 23 - i);
    glVertex2i(5 + i, 22 - i);
    glEnd();
    glFlush();
    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(4 + i, 22 - i);
    glVertex2i(4 + i, 23 - i);
    glVertex2i(5 + i, 23 - i);
    glVertex2i(5 + i, 22 - i);
    glEnd();
    glFlush();
  }
  print_table("192.168.1.242/30", 16, -27.5, 0.0);
  print_table("D", 30, -27.5, 0.0);
  print_table("2", 40, -27.5, 0.0);

  for (i = 3; i < 18; i = i + temp) // packets from router 4 to 1
  {

    glColor3f(0.137255, 0.556863, 0.198039);
    glBegin(GL_QUADS);
    glVertex2i(-2 - i, 22 - i);
    glVertex2i(-2 - i, 23 - i);
    glVertex2i(-3 - i, 23 - i);
    glVertex2i(-3 - i, 22 - i);
    glEnd();
    glFlush();
    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(-2 - i, 22 - i);
    glVertex2i(-2 - i, 23 - i);
    glVertex2i(-3 - i, 23 - i);
    glVertex2i(-3 - i, 22 - i);
    glEnd();
    glFlush();
  }
  print_table("192.168.1.242/30", -48, -33, 0.0);
  print_table("D", -35, -33, 0.0);
  print_table("2", -25, -33, 0.0);

  for (i = 13; i > 1; i = i - temp) //packets from router 3 to 2
  {
    glColor3f(0.917647, 0.560784, 0.560784);
    glBegin(GL_QUADS);
    glVertex2i(5 + i, 1);
    glVertex2i(5 + i, 2);
    glVertex2i(6 + i, 2);
    glVertex2i(6 + i, 1);
    glEnd();
    glFlush();

    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(5 + i, 1);
    glVertex2i(5 + i, 2);
    glVertex2i(6 + i, 2);
    glVertex2i(6 + i, 1);
    glEnd();
    glFlush();

  }
  /* print_table("192.168.1.242",16,-27.5,0.0);
    print_table("-",30,-27.5,0.0);
    print_table("2",40,-27.5,0.0);*/
  print_table("20.0.0.0/8", -14, -27.5, 0.0);
  print_table("C", -1, -27.5, 0.0);
  print_table("2", 8, -27.5, 0.0);

  print_table("192.168.1.244/30", -15, -30.5, 0.0);
  print_table("C", -1, -30.5, 0.0);
  print_table("2", 8, -30.5, 0.0);

  print_table("192.168.1.242/30", -15, -33.5, 0.0);
  print_table("C", -1, -33.5, 0.0);
  print_table("3", 8, -33.5, 0.0);

  for (i = 0; i < 12; i = i + temp) //packets from router 1 to 2
  {
    glColor3f(0.196078, 0.6, 0.8);
    glBegin(GL_QUADS);
    glVertex2i(-18 + i, 1);
    glVertex2i(-18 + i, 2);
    glVertex2i(-19 + i, 2);
    glVertex2i(-19 + i, 1);
    glEnd();
    glFlush();

    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(-18 + i, 1);
    glVertex2i(-18 + i, 2);
    glVertex2i(-19 + i, 2);
    glVertex2i(-19 + i, 1);
    glEnd();
    glFlush();
  }

  print_table("192.168.1.252/30", -15, -21.5, 0.0);
  print_table("A", -1, -21.5, 0.0);
  print_table("2", 8, -21.5, 0.0);

  print_table("10.0.0.0/8", -14, -24.5, 0.0);
  print_table("A", -1, -24.5, 0.0);
  print_table("2", 8, -24.5, 0.0);

  glColor3f(1.0 f, 1.0 f, 0.0 f);
  for (i = 1; i < 14; i = i + temp) //packets from router 2 to 3
  {
    glColor3f(0.9, 0.998039, 0);
    glBegin(GL_QUADS);
    glVertex2i(5 + i, 1);
    glVertex2i(5 + i, 2);
    glVertex2i(6 + i, 2);
    glVertex2i(6 + i, 1);
    glEnd();
    glFlush();

    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(5 + i, 1);
    glVertex2i(5 + i, 2);
    glVertex2i(6 + i, 2);
    glVertex2i(6 + i, 1);
    glEnd();
    glFlush();
  }
  print_table("192.168.1.248/30", 16, -24.5, 0.0);
  print_table("B", 30, -24.5, 0.0);
  print_table("2", 40, -24.5, 0.0);

  print_table("10.0.0.0/8", 16, -30.5, 0.0);
  print_table("B", 30, -30.5, 0.0);
  print_table("3", 40, -30.5, 0.0);

  print_table("192.168.1.252/30", 16, -33.5, 0.0);
  print_table("B", 30, -33.5, 0.0);
  print_table("3", 40, -33.5, 0.0);

  for (i = 14; i > 1; i = i - temp) //packets from router 2 to 1
  {
    glColor3f(0.917647, 0.560784, 0.560784);
    glBegin(GL_QUADS);
    glVertex2i(-20 + i, 1);
    glVertex2i(-20 + i, 2);
    glVertex2i(-21 + i, 2);
    glVertex2i(-21 + i, 1);
    glEnd();
    glFlush();

    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(-20 + i, 1);
    glVertex2i(-20 + i, 2);
    glVertex2i(-21 + i, 2);
    glVertex2i(-21 + i, 1);
    glEnd();
    glFlush();
  }
  print_table("192.168.1.248/30", -48, -24.5, 0.0);
  print_table("B", -35, -24.5, 0.0);
  print_table("2", -25, -24.5, 0.0);

  print_table("20.0.0.0/8", -47, -27.5, 0.0);
  print_table("B", -35, -27.5, 0.0);
  print_table("3", -25, -27.5, 0.0);

  print_table("192.168.1.244/30", -48, -30.5, 0.0);
  print_table("B", -35, -30.5, 0.0);
  print_table("3", -25, -30.5, 0.0);

  for (i = 4; i < 18; i = i + temp) // packets from router 1 to 4
  {
    glColor3f(0.196078, 0.6, 0.8);
    glBegin(GL_QUADS);
    glVertex2i(-23 + i, 1 + i);
    glVertex2i(-23 + i, 2 + i);
    glVertex2i(-24 + i, 2 + i);
    glVertex2i(-24 + i, 1 + i);
    glEnd();
    glFlush();
    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(-23 + i, 1 + i);
    glVertex2i(-23 + i, 2 + i);
    glVertex2i(-24 + i, 2 + i);
    glVertex2i(-24 + i, 1 + i);
    glEnd();
    glFlush();
  }
  print_table("10.0.0.0/8", -23, 42, 0.0);
  print_table("A", -11, 42, 0.0);
  print_table("2", 0, 42, 0.0);

  print_table("192.168.1.252/30", -24, 39, 0.0);
  print_table("A", -11, 39, 0.0);
  print_table("2", 0, 39, 0.0);

  print_table("20.0.0.0/8", -23, 36, 0.0);
  print_table("A", -11, 36, 0.0);
  print_table("4", 0, 36, 0.0);

  print_table("192.168.1.244/30", -24, 33, 0.0);
  print_table("A", -11, 33, 0.0);
  print_table("4", 0, 33, 0.0);

  print_table("192.168.1.248/30", -24, 30, 0.0);
  print_table("A", -11, 30, 0.0);
  print_table("3", 0, 30, 0.0);

  for (i = 4; i < 17; i = i + temp) // packets from router 3 to 4
  {
    glColor3f(0.917647, 0.560784, 0.560784);
    glBegin(GL_QUADS);
    glVertex2i(22 - i, 1 + i);
    glVertex2i(22 - i, 2 + i);
    glVertex2i(23 - i, 2 + i);
    glVertex2i(23 - i, 1 + i);
    glEnd();
    glFlush();
    glColor4f(0.0, 0.0, 0.0, 0);
    glBegin(GL_QUADS);
    glVertex2i(22 - i, 1 + i);
    glVertex2i(22 - i, 2 + i);
    glVertex2i(23 - i, 2 + i);
    glVertex2i(23 - i, 1 + i);
    glEnd();
    glFlush();
  }
  colorflag = 1;
  print_table("20.0.0.0/8", -23, 36, 0.0);
  colorflag = 1;
  print_table("A", -11, 36, 0.0);
  colorflag = 1;
  print_table("4", 0, 36, 0.0);
  colorflag = 1;
  print_table("192.168.1.244/30", -24, 33, 0.0);
  colorflag = 1;
  print_table("A", -11, 33, 0.0);
  colorflag = 1;
  print_table("4", 0, 33, 0.0);

  print_table("20.0.0.0/8", -23, 36, 0.0);
  print_table("C", -11, 36, 0.0);
  print_table("2", 0, 36, 0.0);

  print_table("192.168.1.244/30", -24, 33, 0.0);
  print_table("C", -11, 33, 0.0);
  print_table("2", 0, 33, 0.0);
  page6();

}
void sourcedesttable(char * s) {

  glBegin(GL_POLYGON);
  glVertex2i(10, 45);
  glVertex2i(28, 45);
  glVertex2i(28, 23);
  glVertex2i(10, 23);
  glEnd();
  glFlush();
  glColor3f(1, 1, 1);

  int lens = strlen(s);
  glRasterPos3f(11, 43, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "1. 10.0.0.0/8";
  lens = strlen(s);
  glRasterPos3f(11, 40, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "2. 20.0.0.0/8";
  lens = strlen(s);
  glRasterPos3f(11, 37, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "3. 192.168.1.252/30";
  lens = strlen(s);
  glRasterPos3f(11, 34, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "4. 192.168.1.248/30";
  lens = strlen(s);
  glRasterPos3f(11, 31, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "5. 192.168.1.244/30";
  lens = strlen(s);
  glRasterPos3f(11, 28, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
  s = "6. 192.168.1.242/30";
  lens = strlen(s);
  glRasterPos3f(11, 25, 0.0);
  for (i = 0; i < lens; i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
}
void animStoD() {
  float i, temp = 0.2;
  if (source == 1 || source == 3) {
    if (dest == 4 || dest == 2 || dest == 5) {
      for (i = 0; i < 12; i = i + temp) //packets from router 1 to 2
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-18 + i, 1);
        glVertex2i(-18 + i, 2);
        glVertex2i(-19 + i, 2);
        glVertex2i(-19 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-18 + i, 1);
        glVertex2i(-18 + i, 2);
        glVertex2i(-19 + i, 2);
        glVertex2i(-19 + i, 1);
        glEnd();
        glFlush();
      }
    }
    if (dest == 2 || dest == 5) {
      for (i = 1; i < 14; i = i + temp) //packets from router 2 to 3
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();
      }
    }
    if (dest == 6) {
      for (i = 4; i < 18; i = i + temp) // packets from router 1 to 4
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-23 + i, 1 + i);
        glVertex2i(-23 + i, 2 + i);
        glVertex2i(-24 + i, 2 + i);
        glVertex2i(-24 + i, 1 + i);
        glEnd();
        glFlush();
        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-23 + i, 1 + i);
        glVertex2i(-23 + i, 2 + i);
        glVertex2i(-24 + i, 2 + i);
        glVertex2i(-24 + i, 1 + i);
        glEnd();
        glFlush();
      }
    }
  } else if (source == 2 || source == 5) {
    if (dest == 4 || dest == 1 || dest == 3) {
      for (i = 13; i > 1; i = i - temp) //packets from router 3 to 2
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();
      }

    }
    if (dest == 1 || dest == 3) {
      for (i = 14; i > 1; i = i - temp) //packets from router 2 to 1
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-20 + i, 1);
        glVertex2i(-20 + i, 2);
        glVertex2i(-21 + i, 2);
        glVertex2i(-21 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-20 + i, 1);
        glVertex2i(-20 + i, 2);
        glVertex2i(-21 + i, 2);
        glVertex2i(-21 + i, 1);
        glEnd();
        glFlush();
      }

    }
    if (dest == 6) {
      for (i = 4; i < 17; i = i + temp) // packets from router 3 to 4
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(22 - i, 1 + i);
        glVertex2i(22 - i, 2 + i);
        glVertex2i(23 - i, 2 + i);
        glVertex2i(23 - i, 1 + i);
        glEnd();
        glFlush();
        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(22 - i, 1 + i);
        glVertex2i(22 - i, 2 + i);
        glVertex2i(23 - i, 2 + i);
        glVertex2i(23 - i, 1 + i);
        glEnd();
        glFlush();
      }
    }

  } else if (source == 4) {
    if (dest == 1 || dest == 3) {
      for (i = 14; i > 1; i = i - temp) //packets from router 2 to 1
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-20 + i, 1);
        glVertex2i(-20 + i, 2);
        glVertex2i(-21 + i, 2);
        glVertex2i(-21 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-20 + i, 1);
        glVertex2i(-20 + i, 2);
        glVertex2i(-21 + i, 2);
        glVertex2i(-21 + i, 1);
        glEnd();
        glFlush();
      }
    }
    if (dest == 2 || dest == 5 || dest == 6) {
      for (i = 1; i < 14; i = i + temp) //packets from router 2 to 3
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(5 + i, 1);
        glVertex2i(5 + i, 2);
        glVertex2i(6 + i, 2);
        glVertex2i(6 + i, 1);
        glEnd();
        glFlush();
      }
    }
    if (dest == 6) {
      for (i = 4; i < 17; i = i + temp) // packets from router 3 to 4
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(22 - i, 1 + i);
        glVertex2i(22 - i, 2 + i);
        glVertex2i(23 - i, 2 + i);
        glVertex2i(23 - i, 1 + i);
        glEnd();
        glFlush();
        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(22 - i, 1 + i);
        glVertex2i(22 - i, 2 + i);
        glVertex2i(23 - i, 2 + i);
        glVertex2i(23 - i, 1 + i);
        glEnd();
        glFlush();
      }
    }
  }
  if (source == 6) {
    if (dest == 1 || dest == 3 || dest == 4) {

      for (i = 3; i < 18; i = i + temp) // packets from router 4 to 1
      {

        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-2 - i, 22 - i);
        glVertex2i(-2 - i, 23 - i);
        glVertex2i(-3 - i, 23 - i);
        glVertex2i(-3 - i, 22 - i);
        glEnd();
        glFlush();
        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-2 - i, 22 - i);
        glVertex2i(-2 - i, 23 - i);
        glVertex2i(-3 - i, 23 - i);
        glVertex2i(-3 - i, 22 - i);
        glEnd();
        glFlush();
      }

    }
    if (dest == 4) {
      for (i = 0; i < 12; i = i + temp) //packets from router 1 to 2
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(-18 + i, 1);
        glVertex2i(-18 + i, 2);
        glVertex2i(-19 + i, 2);
        glVertex2i(-19 + i, 1);
        glEnd();
        glFlush();

        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(-18 + i, 1);
        glVertex2i(-18 + i, 2);
        glVertex2i(-19 + i, 2);
        glVertex2i(-19 + i, 1);
        glEnd();
        glFlush();
      }
    }
    if (dest == 2 || dest == 5) {
      for (i = 3; i < 17; i = i + temp) // packets from router 4 to 3
      {
        glColor3f(1.000, 0.078, 0.576);
        glBegin(GL_QUADS);
        glVertex2i(4 + i, 22 - i);
        glVertex2i(4 + i, 23 - i);
        glVertex2i(5 + i, 23 - i);
        glVertex2i(5 + i, 22 - i);
        glEnd();
        glFlush();
        glColor4f(0.0, 0.0, 0.0, 0);
        glBegin(GL_QUADS);
        glVertex2i(4 + i, 22 - i);
        glVertex2i(4 + i, 23 - i);
        glVertex2i(5 + i, 23 - i);
        glVertex2i(5 + i, 22 - i);
        glEnd();
        glFlush();
      }

    }
  }
  sflag = 0;
  glColor3f(0.957, 0.643, 0.376);
  sourcedesttable("Enter source network:");

}
void display() {
  glClearColor(1.0, 1.0, 1.0, 1.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_FLAT);

  if (flag == 1) {
    page1();
  } else if (flag == 2) {
    page2();
  } else if (flag == 3) {
    page5();
  } else if (flag == 4) {
    //router creation
    page3();

    finish = 0;
  } else if (flag == 5) {
    //updated routers
    page6();
    if (sflag == 0) {
      glColor3f(0.957, 0.643, 0.376);
      sourcedesttable("Enter source network:");

    } else if (sflag == 1) {
      glColor3f(0.627, 0.322, 0.176);
      sourcedesttable("Enter destination network:");
    } else if (sflag == 2) {
      animStoD();
    }

  } else if (flag == 6) {
    //animation
    page4();
  }
  if (count == 1 && flag == 6) {
    if (finish == 0) {
      anim();
      flag = 5;
    }

  }
  glFlush();
  glutSwapBuffers();
}

void myreshape2(int w, int h) {
  printf(w + " " + h);
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 0.0, -5.0);
}
void key(unsigned char key, int x, int y) {
  if (flag == 1) {
    if (key == 'c') {
      flag = 2;
      glutPostRedisplay();
    }
  } else if (flag == 2) {
    switch (key) {
    case '1':
      flag = 3;
      glutPostRedisplay();
      break;
    case '2':
      flag = 4;
      glutPostRedisplay();
      break;
    case '3':
      flag = 5;
      glutPostRedisplay();
      break;
    case '4':
      exit(0);
    case 'b':
      flag = 1;
      glutPostRedisplay();
      break;
    case 27:
      exit(0);
    }
  } else if (flag == 3) {
    switch (key) {
    case 'b':
      flag = 2;
      glutPostRedisplay();
      break;

    case 27:
      exit(0);
    }
  } else if (flag == 4) {
    switch (key) {
    case 'b':
      flag = 2;
      myreshape2(1300, 700);
      glutPostRedisplay();
      break;

    case 's':
      flag = 6;
      glutPostRedisplay();
      break;
    case 27:
      exit(0);
    }
  } else if (flag == 5) {

    if (sflag == 0) {
      switch (key) {
      case 'b':
        flag = 2;
        myreshape2(1300, 700);
        glutPostRedisplay();
        break;
      case '1':
        source = 1;
        sflag = 1;
        glutPostRedisplay();
        break;
      case '2':
        source = 2;
        sflag = 1;
        glutPostRedisplay();
        break;
      case '3':
        source = 3;
        sflag = 1;
        glutPostRedisplay();
        break;
      case '4':
        source = 4;
        sflag = 1;
        glutPostRedisplay();
        break;
      case '5':
        source = 5;
        sflag = 1;
        glutPostRedisplay();
        break;
      case '6':
        source = 6;
        sflag = 1;
        glutPostRedisplay();
        break;
      case 27:
        exit(0);
      }

    } else if (sflag == 1) {
      switch (key) {
      case 'b':
        flag = 2;
        myreshape2(1300, 700);
        glutPostRedisplay();
        break;
      case '1':
        dest = 1;
        sflag = 2;
        glutPostRedisplay();
        break;
      case '2':
        dest = 2;
        sflag = 2;
        glutPostRedisplay();
        break;
      case '3':
        dest = 3;
        sflag = 2;
        glutPostRedisplay();
        break;
      case '4':
        dest = 4;
        sflag = 2;
        glutPostRedisplay();
        break;
      case '5':
        dest = 5;
        sflag = 2;
        glutPostRedisplay();
        break;
      case '6':
        dest = 6;
        sflag = 2;
        glutPostRedisplay();
        break;
      case 27:
        exit(0);
      }
    }
  } else if (flag == 6) {
    switch (key) {
    case 'b':
      flag = 4;
      glutPostRedisplay();
      break;

    case 27:
      exit(0);
    }
  }
  if (key == 's') {
    count = 1;
    x += 1.5;

  }

}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Routing Information Protocol");
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  printf("H");
  glLoadIdentity();
  glutDisplayFunc(display);
  glutReshapeFunc(myreshape2);
  glutKeyboardFunc(key);
  glutMainLoop();
  return 0; // This line is never reached.
}
