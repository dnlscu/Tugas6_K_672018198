#include<stdlib.h>
#include<Windows.h>
#include<gl/GL.h>
#include<GL\glut.h>
#include <math.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;
int is_depth;

void init(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void){
	if(is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	glPushMatrix();
	
	//depan
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-20,20);
	glVertex3f(20,-20, 20);
	glVertex3f(20, -30, 20);
	glVertex3f(-50,-30,20);
	glEnd();
	
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-20,20);
	glVertex3f(-50,-20, -50);
	glVertex3f(20, -20, -50);
	glVertex3f(20,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-30,20);
	glVertex3f(-50,-30, -50);
	glVertex3f(20, -30, -50);
	glVertex3f(20,-30,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-20,10);
	glVertex3f(-50, -20, -50);
	glVertex3f(-50, -30, -50);
	glVertex3f(-50,-30,10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,-20,10);
	glVertex3f(20, -20, -50);
	glVertex3f(20, -30, -50);
	glVertex3f(20,-30,10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-20,-50);
	glVertex3f(20,-20,-50);
	glVertex3f(20, -30, -50);
	glVertex3f(-50,-30,-50);
	glEnd();
	
	//pilar1
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(15,20,20);
	glVertex3f(20,20, 20);
	glVertex3f(20, -20, 20);
	glVertex3f(15,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,20,20);
	glVertex3f(20,20, 15);
	glVertex3f(20, -20, 15);
	glVertex3f(20,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(15,20,20);
	glVertex3f(15,20, 15);
	glVertex3f(15, -20, 15);
	glVertex3f(15,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(15,20,15);
	glVertex3f(20,20, 15);
	glVertex3f(20, -20, 15);
	glVertex3f(15,-20,15);
	glEnd();
	
	//pilar2
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,20);
	glVertex3f(-45,20, 20);
	glVertex3f(-45, -20, 20);
	glVertex3f(-50,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,20);
	glVertex3f(-50,20, 15);
	glVertex3f(-50, -20, 15);
	glVertex3f(-50,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-45,20,20);
	glVertex3f(-45,20, 15);
	glVertex3f(-45, -20, 15);
	glVertex3f(-45,-20,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,15);
	glVertex3f(-45,20, 15);
	glVertex3f(-45, -20, 15);
	glVertex3f(-50,-20,15);
	glEnd();
	
	//tembok depan1
	glBegin(GL_QUADS);
	glColor3ub(241, 250, 238);
	glVertex3f(-50,20,10);
	glVertex3f(-20, 20, 10);
	glVertex3f(-20, -20, 10);
	glVertex3f(-50,-20,10);
	glEnd();
	
	//tembok depan2
	glBegin(GL_QUADS);
	glColor3ub(241, 250, 238);
	glVertex3f(-20,20,5);
	glVertex3f(20, 20, 5);
	glVertex3f(20, -20, 5);
	glVertex3f(-20,-20,5);
	glEnd();
	
	//tembok depan3
	glBegin(GL_QUADS);
	glColor3ub(241, 250, 238);
	glVertex3f(-20,20,10);
	glVertex3f(-20, 20, 5);
	glVertex3f(-20, -20, 5);
	glVertex3f(-20,-20,10);
	glEnd();
	
	//tembok kiri
	glBegin(GL_QUADS);
	glColor3ub(241, 250, 238);
	glVertex3f(-50,20,10);
	glVertex3f(-50, 20, -50);
	glVertex3f(-50, -20, -50);
	glVertex3f(-50,-20,10);
	glEnd();
	
	//tembok kanan
	glBegin(GL_QUADS);
	glColor3ub(241, 250, 238);
	glVertex3f(20,20,5);
	glVertex3f(20, 20, -50);
	glVertex3f(20, -20, -50);
	glVertex3f(20,-20,5);
	glEnd();
	
	//pintu
	glBegin(GL_QUADS);
	glColor3ub(119, 73, 54);
	glVertex3f(-20,10,5.1);
	glVertex3f(-10, 10, 5.1);
	glVertex3f(-10, -20, 5.1);
	glVertex3f(-20,-20,5.1);
	glEnd();
	
	//jendela1
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-45,10,10.1);
	glVertex3f(-25, 10, 10.1);
	glVertex3f(-25, -15, 10.1);
	glVertex3f(-45,-15,10.1);
	glEnd();
	
	//jendela2
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-5,10,5.1);
	glVertex3f(15, 10, 5.1);
	glVertex3f(15, -15, 5.1);
	glVertex3f(-5,-15,5.1);
	glEnd();
	
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,22);
	glVertex3f(-50,20, -50);
	glVertex3f(20, 20, -50);
	glVertex3f(20,20,22);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,25,20);
	glVertex3f(-50,25, -50);
	glVertex3f(20, 25, -50);
	glVertex3f(20,25,20);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,10);
	glVertex3f(-50, 20, -50);
	glVertex3f(-50, 25, -50);
	glVertex3f(-50,25,10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,20,10);
	glVertex3f(20, 20, -50);
	glVertex3f(20, 25, -50);
	glVertex3f(20,25,10);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,-20,-50);
	glVertex3f(20,-20,-50);
	glVertex3f(20, 25, -50);
	glVertex3f(-50,25,-50);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(-50,20,20);
	glVertex3f(20,20, 20);
	glVertex3f(20, 25, 20);
	glVertex3f(-50,25,20);
	glEnd();
	
	//atap
	glBegin(GL_POLYGON);
	glColor3ub(2, 195, 154);
	glVertex3f(-55,24,25);
	glVertex3f(25, 24, 25);
	glVertex3f(-15, 70, 0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(2, 195, 154);
	glVertex3f(-55,24,-55);
	glVertex3f(25, 24, -55);
	glVertex3f(-15, 70, -30);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(2, 195, 154);
	glVertex3f(-55,24,25);
	glVertex3f(-55, 24, -55);
	glVertex3f(-15, 70, -30);
	glVertex3f(-15,70,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(2, 195, 154);
	glVertex3f(25,24,25);
	glVertex3f(25, 24, -55);
	glVertex3f(-15, 70, -30);
	glVertex3f(-15,70,0);
	glEnd();
	
	
	//rumahkanan
	//depan
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,-25,5);
	glVertex3f(80,-25, 5);
	glVertex3f(80, -30, 5);
	glVertex3f(20,-30,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,-25,-50);
	glVertex3f(80,-25, -50);
	glVertex3f(80, -30, -50);
	glVertex3f(20,-30,-50);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(80,-25,5);
	glVertex3f(80,-25, -50);
	glVertex3f(80, -30, -50);
	glVertex3f(80,-30,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(80,-25,5);
	glVertex3f(80,-25, -50);
	glVertex3f(20, -25, -50);
	glVertex3f(20,-25,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(80,-30,5);
	glVertex3f(80,-30, -50);
	glVertex3f(20, -30, -50);
	glVertex3f(20,-30,5);
	glEnd();
	
	//tembok depan
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(20,20,-10);
	glVertex3f(80,20, -10);
	glVertex3f(80, -25, -10);
	glVertex3f(20,-25,-10);
	glEnd();
	
	//tembok samping
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(80,20,-10);
	glVertex3f(80,20, -50);
	glVertex3f(80, -25, -50);
	glVertex3f(80,-25,-10);
	glEnd();
	
	//tembok belakang
	glBegin(GL_QUADS);
	glColor3ub(188, 108, 37);
	glVertex3f(20,20,-50);
	glVertex3f(80,20, -50);
	glVertex3f(80, -25, -50);
	glVertex3f(20,-25,-50);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,24,5);
	glVertex3f(80,24, 5);
	glVertex3f(80, 20, 5);
	glVertex3f(20,20,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,24,-50);
	glVertex3f(80,24, -50);
	glVertex3f(80, 20, -50);
	glVertex3f(20,20,-50);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(80,24,5);
	glVertex3f(80,24, -50);
	glVertex3f(80, 20, -50);
	glVertex3f(80,20,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,24,5);
	glVertex3f(20,24, -50);
	glVertex3f(80, 24, -50);
	glVertex3f(80,24,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(108, 117, 125);
	glVertex3f(20,20,5);
	glVertex3f(20,20, -50);
	glVertex3f(80, 20, -50);
	glVertex3f(80,20,5);
	glEnd();
	
	//tiang1
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(75,20,5);
	glVertex3f(80,20, 5);
	glVertex3f(80, -25, 5);
	glVertex3f(75,-25,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(75,20,0);
	glVertex3f(80,20, 0);
	glVertex3f(80, -25, 0);
	glVertex3f(75,-25,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(75,20,5);
	glVertex3f(75,20, 0);
	glVertex3f(75, -25, 0);
	glVertex3f(75,-25,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(80,20,5);
	glVertex3f(80,20, 0);
	glVertex3f(80, -25, 0);
	glVertex3f(80,-25,5);
	glEnd();
	
	//tiang2
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(50,20,5);
	glVertex3f(55,20, 5);
	glVertex3f(55, -25, 5);
	glVertex3f(50,-25,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(50,20,0);
	glVertex3f(55,20, 0);
	glVertex3f(55, -25, 0);
	glVertex3f(50,-25,0);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(50,20,5);
	glVertex3f(50,20, 0);
	glVertex3f(50, -25, 0);
	glVertex3f(50,-25,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(57, 42, 22);
	glVertex3f(55,20,5);
	glVertex3f(55,20, 0);
	glVertex3f(55, -25, 0);
	glVertex3f(55,-25,5);
	glEnd();
	
	//pintu
	glBegin(GL_QUADS);
	glColor3ub(119, 73, 54);
	glVertex3f(30,5,-9.9);
	glVertex3f(40, 5, -9.9);
	glVertex3f(40, -25, -9.9);
	glVertex3f(30,-25,-9.9);
	glEnd();
	
	//jendela1
	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex3f(22,5,-9.9);
	glVertex3f(28, 5, -9.9);
	glVertex3f(28, -15, -9.9);
	glVertex3f(22,-15,-9.9);
	glEnd();
	
	//jendela2
	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex3f(42,5,-9.9);
	glVertex3f(48, 5, -9.9);
	glVertex3f(48, -15, -9.9);
	glVertex3f(42,-15,-9.9);
	glEnd();
	
	//atap
	glBegin(GL_POLYGON);
	glColor3ub(153, 88, 42);
	glVertex3f(15,24,-5);
	glVertex3f(85, 24,-5);
	glVertex3f(50, 60, -25);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3ub(153, 88, 42);
	glVertex3f(15,24,-55);
	glVertex3f(85, 24,-55);
	glVertex3f(50, 60, -40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(153, 88, 42);
	glVertex3f(15,24,-5);
	glVertex3f(15, 24, -55);
	glVertex3f(50, 60, -40);
	glVertex3f(50,60,-25);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(153, 88, 42);
	glVertex3f(85,24,-5);
	glVertex3f(85, 24, -55);
	glVertex3f(50, 60, -40);
	glVertex3f(50,60,-25);
	glEnd();
	
	
	//lemari
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-30,-20,-49);
	glVertex3f(10, -20, -49);
	glVertex3f(10, 10, -49);
	glVertex3f(-30,10,-49);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-30,-20,-49);
	glVertex3f(-30, -20, -40);
	glVertex3f(-30, 10, -40);
	glVertex3f(-30,10,-49);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(10,-20,-49);
	glVertex3f(10, -20, -40);
	glVertex3f(10, 10, -40);
	glVertex3f(10,10,-49);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(137, 87, 55);
	glVertex3f(-30,-20,-40);
	glVertex3f(10, -20, -40);
	glVertex3f(10, -10, -40);
	glVertex3f(-30,-10,-40);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(137, 87, 55);
	glVertex3f(-30,-10,-40);
	glVertex3f(10, -10, -40);
	glVertex3f(10, -10, -49);
	glVertex3f(-30,-10,-49);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-30,10,-40);
	glVertex3f(10, 10, -40);
	glVertex3f(10, 10, -49);
	glVertex3f(-30,10,-49);
	glEnd();
	
	//tv
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-25,5,-48);
	glVertex3f(5, 5, -48);
	glVertex3f(5, -5, -48);
	glVertex3f(-25,-5,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-25,5,-45);
	glVertex3f(5, 5, -45);
	glVertex3f(5, -5, -45);
	glVertex3f(-25,-5,-45);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-25,5,-48);
	glVertex3f(-25, 5, -45);
	glVertex3f(-25, -5, -45);
	glVertex3f(-25,-5,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(5,5,-48);
	glVertex3f(5, 5, -45);
	glVertex3f(5, -5, -45);
	glVertex3f(5,-5,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-25,5,-48);
	glVertex3f(-25, 5, -45);
	glVertex3f(5, 5, -45);
	glVertex3f(5,5,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-25,-5,-48);
	glVertex3f(-25, -5, -45);
	glVertex3f(5, -5, -45);
	glVertex3f(5,-5,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-24,4,-44.9);
	glVertex3f(4, 4, -44.9);
	glVertex3f(4, -4, -44.9);
	glVertex3f(-24,-4,-44.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-8,-5,-48);
	glVertex3f(-8, -5, -45);
	glVertex3f(-8, -10, -45);
	glVertex3f(-8,-10,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-12,-5,-48);
	glVertex3f(-12, -5, -45);
	glVertex3f(-12, -10, -45);
	glVertex3f(-12,-10,-48);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-12,-5,-45);
	glVertex3f(-8, -5, -45);
	glVertex3f(-8, -10, -45);
	glVertex3f(-12,-10,-45);
	glEnd();
	
	//meja
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-15,5);
	glVertex3f(-25, -15, 5);
	glVertex3f(-25, -15, -5);
	glVertex3f(-45,-15,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-17,5);
	glVertex3f(-25, -17, 5);
	glVertex3f(-25, -17, -5);
	glVertex3f(-45,-17,-5);
	glEnd();
	//kanan kiri
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-17,5);
	glVertex3f(-45, -17, -5);
	glVertex3f(-45, -15, -5);
	glVertex3f(-45,-15,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-25,-17,5);
	glVertex3f(-25, -17, -5);
	glVertex3f(-25, -15, -5);
	glVertex3f(-25,-15,5);
	glEnd();
	//depan belakang
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-17,5);
	glVertex3f(-25, -17, 5);
	glVertex3f(-25, -15, 5);
	glVertex3f(-45,-15,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-17,-5);
	glVertex3f(-25, -17, -5);
	glVertex3f(-25, -15, -5);
	glVertex3f(-45,-15,-5);
	glEnd();
	//kakikaki
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-20,5);
	glVertex3f(-45, -20, 3);
	glVertex3f(-45, -17, 3);
	glVertex3f(-45,-17,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-20,-5);
	glVertex3f(-45, -20, -3);
	glVertex3f(-45, -17, -3);
	glVertex3f(-45,-17,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-25,-20,5);
	glVertex3f(-25, -20, 3);
	glVertex3f(-25, -17, 3);
	glVertex3f(-25,-17,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-25,-20,-5);
	glVertex3f(-25, -20, -3);
	glVertex3f(-25, -17, -3);
	glVertex3f(-25,-17,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-20,5);
	glVertex3f(-43, -20, 5);
	glVertex3f(-43, -17, 5);
	glVertex3f(-45,-17,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-27,-20,5);
	glVertex3f(-25, -20, 5);
	glVertex3f(-25, -17, 5);
	glVertex3f(-27,-17,5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-45,-20,-5);
	glVertex3f(-43, -20, -5);
	glVertex3f(-43, -17, -5);
	glVertex3f(-45,-17,-5);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(94, 48, 35);
	glVertex3f(-27,-20,-5);
	glVertex3f(-25, -20, -5);
	glVertex3f(-25, -17, -5);
	glVertex3f(-27,-17,-5);
	glEnd();
	
	//karpet
	glBegin(GL_QUADS);
	glColor3ub(36, 85, 1);
	glVertex3f(-49.5,-19.9,9.5);
	glVertex3f(-49.5, -19.9, -9.5);
	glVertex3f(-20.5, -19.9, -9.5);
	glVertex3f(-20.5,-19.9,9.5);
	glEnd();
	
	//sofa
	glBegin(GL_QUADS);
	glColor3ub(0, 175, 185);
	glVertex3f(-30,-20,-15);
	glVertex3f(10, -20, -15);
	glVertex3f(10, -5, -15);
	glVertex3f(-30,-5,-15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 175, 185);
	glVertex3f(-30,-20,-22);
	glVertex3f(10, -20, -22);
	glVertex3f(10, -15, -22);
	glVertex3f(-30,-15,-22);
	glEnd();
	//bawah
	glBegin(GL_QUADS);
	glColor3ub(0, 175, 185);
	glVertex3f(-30,-20,-22);
	glVertex3f(10, -20, -22);
	glVertex3f(10, -20, -15);
	glVertex3f(-30,-20,-15);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(0, 175, 185);
	glVertex3f(-30,-15,-22);
	glVertex3f(10, -15, -22);
	glVertex3f(10, -15, -15);
	glVertex3f(-30,-15,-15);
	glEnd();
	
	//foto
	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex3f(-45,15,-49.9);
	glVertex3f(-35, 15, -49.9);
	glVertex3f(-35, 0, -49.9);
	glVertex3f(-45,0,-49.9);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-43,13,-49.8);
	glVertex3f(-37, 13, -49.8);
	glVertex3f(-37, 2, -49.8);
	glVertex3f(-43,2,-49.8);
	glEnd();
	
	//salib
	glBegin(GL_QUADS);
	glColor3ub(119, 73, 54);
	glVertex3f(-10,22,-49.9);
	glVertex3f(-8, 22, -49.9);
	glVertex3f(-8, 13, -49.9);
	glVertex3f(-10,13,-49.9);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3ub(119, 73, 54);
	glVertex3f(-12,20,-49.9);
	glVertex3f(-6, 20, -49.9);
	glVertex3f(-6, 18, -49.9);
	glVertex3f(-12,18,-49.9);
	glEnd();
	
	
	glPushMatrix();
	glPopMatrix();
	
	glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y){
	switch (key){
		case 'w':
			case 'W':
				glTranslatef(0,0,3);
				break;
		case 'd':
			case 'D':
				glTranslatef(3,0,0);
				break;
		case 's':
			case 'S':
				glTranslatef(0,0,-3);
				break;
		case 'a':
			case 'A':
				glTranslatef(-3,0,0);
				break;
				
		case '7':
			
				glTranslatef(0,3,0);
				break;
		case '9':
			
				glTranslatef(0,-3,0);
				break;
		case '2':
			
				glRotatef(2,1,0,0);
				break;
		case '8':
			
				glRotatef(2,1,0,0);
				break;
		case '6':
			
				glRotatef(2,0,1,0);
				break;
		case '4':
			
				glRotatef(-2,0,1,0);
				break;
		case '1':
			
				glRotatef(2,1,0,1);
				break;
		case '3':
			
				glRotatef(-2,0,0,1);
				break;
		case '5':
			if(is_depth){
				is_depth=0;
				glDisable(GL_DEPTH_TEST);
			}
			else{
				is_depth=1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();//kene
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi){
	if(tinggi==0) tinggi=1;
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(80.0, lebar/tinggi, 5.0, 500.0);
	//glTranslatef(0.0, -5.0, -150.0);
	gluPerspective(50,lebar/tinggi, 5, 500);
	glTranslatef(0,0,-200);	
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(250, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Daniel Setyo Cahyo Utomo - 672018198");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    
    glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    
    glutReshapeFunc(ukuran);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
