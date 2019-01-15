/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: COSC363-Assignment1.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Clock.h"
#include "Ground.h"
#include "Launchpad.h"
#include "Robot.h"
#include "Skybox.h"
#include "Tree.h"
#include "Workbench.h"

// Camera
Camera* camera = nullptr;

// Objects
Clock* clock = nullptr;
Ground* ground = nullptr;
Launchpad* launchpad = nullptr;
Robot* robot = nullptr;
Tree* tree = nullptr;
Workbench* workbench = nullptr;
Skybox* skybox = nullptr;

void createWindow()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("COSC363 Assignment 1 - William Scott 11876177");
}

void initObjects()
{
	camera = new Camera();
	clock = new Clock();
	ground = new Ground();
	launchpad = new Launchpad();
	robot = new Robot();
	tree = new Tree();
	workbench = new Workbench();
	skybox = new Skybox();
}

void setupLighting()
{
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	// Antenna Spot Light
	float white[4] = { 1.0f, 1.0f, 1.0f, 1.0f};
	float grey[4] = { 0.2f, 0.2f, 0.2f, 1.f };
	float red[4] = { 0.3f, 0.0f, 0.0f, 0.3f };

	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, red);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, red);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 50.0f);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0001f);

	// Main Light
	float lightPos[] = { 0.0f, 50.0f, 0.0f, 1.0f };
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
}

void initialize(int argc, char **argv)
{
	glutInit(&argc, argv);
	createWindow();
	initObjects();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	setupLighting();
		glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.f, 1.f, 0.01f, 10000.f);
}

void display(void)
{
	// Setup
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Material
	float lightRed[4] = { 1.f, 0.2f, 0.2f, 1.0f };
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_SPECULAR, lightRed);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);

	// Update Camera
	camera->lookAt();
	
	// Update Light 0
	float lightPosition[4] = { 10.f, 20.f, 10.f, 1.f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	// Draw Textured Unlit Objects
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	skybox->draw();

	// Draw Textured Lit Objects
	glEnable(GL_LIGHTING);
	clock->draw();
	tree->draw();
	glDisable(GL_TEXTURE_2D);

	// Draw Untextured Lit Objects
	glEnable(GL_LIGHTING);
	ground->draw();
	robot->draw();
	workbench->draw();
	launchpad->draw();
	
	// Flush
	glFlush();
	glutSwapBuffers();
}

void pressKey(int key, int xx, int yy)
{
	camera->pressKey(key, xx, yy);
}

void animateScene(int value)
{
	const int delayMs = 10;

	// Update Objects
	robot->update(); // Also animates firework
	tree->updateLeaves();

	// Finish up
	glutPostRedisplay();
	glutTimerFunc(delayMs, animateScene, 0);
}

/* Initialize glut window and register call backs*/
int main(int argc, char **argv)
{
	// Initalize
	initialize(argc, argv);

	// Glut Functions
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutTimerFunc(1, animateScene, 0);
	glutSpecialFunc(pressKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// Loop
	glutMainLoop();
	return 0;
}

