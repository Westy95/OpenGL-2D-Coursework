#include <stdio.h>
#include <math.h>
#include "glut.h"

int frame = 0;

float fTranslate = 0.0;//speed of translation
float fRotate = 0.0;//speed of rotation
float fScale = 1.0;//speed of scaling
float efScale = 0.5;
float xf1 = 0.0;
float yf1 = 0.0;
float xf2 = 0.0;
float yf2 = 0.0;
float xf3 = 0.0;
float yf3 = 0.0;

int mode;

void init(void) {

	glClearColor(0.5, 0.0, 0.0, 0.0);// set what colour you want the background to be
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 800.0, 0.0, 600.0);//set the projection window size in x and y.
									   //window will then be mapped to the window created in the main function.
}

void squares() {
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(800, 300);
		glVertex2i(800, 250);
		glVertex2i(1100, 250);
		glVertex2i(1100, 300);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(1100, 250);
		glVertex2i(1100, 100);
		glVertex2i(1050, 100);
		glVertex2i(1050, 250);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(1000, 250);
		glVertex2i(1000, 210);
		glVertex2i(1025, 210);
		glVertex2i(1025, 250);
	glEnd();
		glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(1025, 210);
		glVertex2i(1025, 250);
		glVertex2i(1100, 250);
		glVertex2i(1100, 210);
	glEnd();
}
void squares_S2() {
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(400, 300);
		glVertex2i(400, 250);
		glVertex2i(700, 250);
		glVertex2i(700, 300);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(700, 250);
		glVertex2i(700, 100);
		glVertex2i(650, 100);
		glVertex2i(650, 250);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(600, 250);
		glVertex2i(600, 210);
		glVertex2i(625, 210);
		glVertex2i(625, 250);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(625, 210);
		glVertex2i(625, 250);
		glVertex2i(700, 250);
		glVertex2i(700, 210);
	glEnd();
}
void fire() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(300, 200);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(300, 350);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(450, 275);
	glEnd();
}

void fire2() {
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.0, 0.0);
	glVertex2i(300, 200);
	glVertex2i(300, 350);
	glVertex2i(450, 275);
	glEnd();
}
void bullet() {
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(450, 250);
		glVertex2i(500, 200);
		glVertex2i(500, 300);
	glEnd();
}

void bullet2() {
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(1000, 250);
		glVertex2i(1100, 200);
		glVertex2i(1100, 300);
	glEnd();
}

void bullet3() {
	glBegin(GL_POLYGON);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2i(800, 250);
		glVertex2i(900, 200);
		glVertex2i(900, 300);
	glEnd();
}

void black_box_seg1() {
	glBegin(GL_POLYGON);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(200, 350);
		glVertex2i(400, 350);
		glVertex2i(400, 250);
	glEnd();
}

void black_box_seg2() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(200, 350);
	glVertex2i(400, 250);
	glVertex2i(200, 200);
	glEnd();
}

void black_box_seg3() {
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(200, 200);
	glVertex2i(400, 250);
	glVertex2i(400, 200);
	glEnd();
}

void green_gem() {
	glBegin(GL_POLYGON);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i(250, 300);
		glVertex2i(300, 300);
		glVertex2i(325, 275);
		glVertex2i(325, 250);
		glVertex2i(300, 225);
		glVertex2i(250, 225);
		glVertex2i(225, 250);
		glVertex2i(225, 275);
	glEnd();
}

void renderSpacedBitmapString(float x, float y, void *font, char *string) {
	char *c;
	int x1 = x;
	for (c = string; *c != '\0'; c++) {
		glRasterPos2f(x1, y);
			glutBitmapCharacter(font, *c);
		x1 = x1 + glutBitmapWidth(font, *c);
	}
}

void scene1() {
	glViewport(0, 0, 800, 600);
	glPushMatrix();
		glTranslatef(-fTranslate, 0.0, 0.0);
		fTranslate += 4.0;
		squares();
	glPopMatrix();
}

void scene2()
{
	glViewport(0, 200, 800, 200);
	glPushMatrix();
	glTranslatef(-fTranslate, 0.0, 0.0);
	fTranslate += 12.0;
	bullet2();
	glPopMatrix();

	glViewport(200, 50, 600, 500);
	glPushMatrix();
	glTranslatef(450, 275, 0.0);
	glScalef(+efScale, +efScale, 0.0);
	glTranslatef(-450, -275, 0.0);
	efScale += 0.1;
	fire();
	glPopMatrix();

	glViewport(200, 50, 600, 500);
	glPushMatrix();
	squares_S2();
	glPopMatrix();
	glViewport(200, 50, 600, 500);
}

void scene3() {
	glViewport(0, 0, 800, 600);
	glPushMatrix();
		glTranslatef(-fTranslate, 0.0, 0.0);
		fTranslate += 5.0;
		bullet3();
	glPopMatrix();
}

void scene4() {
	glViewport(0, 0, 800, 600);
	glPushMatrix();
		glTranslatef(-fTranslate, 0.0, 0.0);
		fTranslate += 2.0;
		bullet3();
	glPopMatrix();

	glViewport(0, 0, 500, 500);
	glPushMatrix();
		green_gem();
	glPopMatrix();

	glPushMatrix();
		black_box_seg1();
		black_box_seg2();
		black_box_seg3();
	glPopMatrix();
}


void scene5() {
	glViewport(0, 0, 500, 500);
	glPushMatrix();
		glTranslatef(275, 262, 0.0);
		glRotatef(fRotate, 0, 0, 1);
		glTranslatef(-275, -262, 0.0);
		green_gem();
	glPopMatrix();

	glViewport(0, 0, 800, 600);
	glPushMatrix();
		glTranslatef(-fTranslate, 0.0, 0.0);
		fTranslate += 6.0;
		bullet3();
	glPopMatrix();

	glViewport(0, 0, 500, 600);
	glPushMatrix();
		xf1 += 2; yf1 += 4;
		glTranslatef(xf1, yf1, 0.0);
		glTranslatef(300, 325, 0.0);
		glRotatef(fRotate, 0, 0, 1);
		glTranslatef(-300, -325, 0.0);
		black_box_seg1();
	glPopMatrix();
	
	glPushMatrix();
		xf2 += -4; yf2 += 0;
		glTranslatef(xf2, yf2, 0.0);
		glTranslatef(300, 275, 0.0);
		glRotatef(fRotate, 0, 0, 1);
		glTranslatef(-300, -275, 0.0);
		black_box_seg2();
	glPopMatrix();

	glPushMatrix();
		xf3 += 2; yf3 += -4;
		glTranslatef(xf3, yf3, 0.0);
		glTranslatef(300, 225, 0.0);
		glRotatef(fRotate, 0, 0, 1);
		glTranslatef(-300, -225, 0.0);
		black_box_seg3();
	glPopMatrix();
}

void scene6() {
	glViewport(0, 0, 800, 600);
	glPushMatrix();
		renderSpacedBitmapString(450, 150, GLUT_BITMAP_HELVETICA_18, "Jim Beam Apple Whiskey");
		renderSpacedBitmapString(400,200,GLUT_BITMAP_HELVETICA_18,"Straight to the good stuff...");
		glTranslatef(275, 262, 0.0);
		glRotatef(fRotate, 0, 0, 1);
		glTranslatef(-275, -262, 0.0);
		green_gem();
	glPopMatrix();
}

void display(void) {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	frame++;

	if ((frame > 0) && (frame < 100)) {//gun enters screen
		
		scene1();
		
	}
	if ((frame > 100) && (frame < 220)) {//re-draw sqaures to give effect of gun stopping & gun shoots bullet
		
		scene2();
	}


	if ((frame >= 220) && (frame < 300)) {//travelling bullet
		if (frame == 220) fTranslate = 0.0;
		scene3();
	}
	if ((frame >= 300) && (frame < 400)) {//bullet arrives at box
		scene4();
	}
	if ((frame >= 400) && (frame < 500)) {//bullet dissappears & box shatters into peices to present the gem
		scene5();
	}
	if ((frame >= 500) && (frame < 600)) {//rotating gem with message
		scene6();
	}

	fprintf(stdout, "Frame number = %i\n", frame);
	if (frame > 600) {
		frame = 0;
		fScale = 1.0f;
		fTranslate = 0.0f;
	}

	fRotate += 5.0f;
	fScale += 2.5f;

	glFlush();
}

void Timer(int value)
{
	if (value) glutPostRedisplay();
	glutTimerFunc(40, Timer, value);
}

void visibility(int state)
{
	switch (state)
	{
	case GLUT_VISIBLE:
		Timer(1);
		break;
	case GLUT_NOT_VISIBLE:
		Timer(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  //perform the GLUT initialization

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//more initialisation
	glutInitWindowSize(800, 600);//set window size
	glutInitWindowPosition(0, 0);//set window position
	glutCreateWindow("OpenGL_EXC"); // create a display with a given caption for the title bar.
									//glutFullScreen();
	init();
	printf("%s\n", "Abracadabra......");
	glutDisplayFunc(display); //the picture definition of “display” to be displayed in the window.	
	glutVisibilityFunc(visibility);
	glutMainLoop();// the last function in the program puts the program into infinite loop
	return 0;
}