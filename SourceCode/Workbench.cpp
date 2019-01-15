/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Workbench.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Workbench.h"

Workbench::Workbench(void){}

void Workbench::draw(void)
{
	glColor4f(0.5, 0.25, 0.0, 1.0); // Brown

	// Top
	glPushMatrix();
	glTranslatef(0.f, 6.f, 10.f);
	glScalef(16.f, 1.f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Left Leg
	glPushMatrix();
	glTranslatef(5.f, 2.f, 10.f);
	glScalef(2.f, 7.f, 2.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Right Leg
	glPushMatrix();
	glTranslatef(-5.f, 2.f, 10.f);
	glScalef(2.f, 7.f, 2.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Place Fireworks on top
	drawFireworkGroup();
}

void Workbench::drawFireworkGroup()
{
	float xPosStart = -5.f;
	float zPosStart = 9.f;
	float xPos = 0.f;
	float zPos = 0.f;

	for (int row = 0; row < 2; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			xPos = xPosStart + (col * 5);
			zPos = zPosStart + (row * 5);
			// Top
			glColor4f(1.0, 0.0, 0.0, 1.0); // Red
			glPushMatrix();
			glTranslatef(xPos, 11.f, zPos);
			glRotatef(-90, 1, 0, 0);
			glutSolidCone(2.f, 3, 5, 5);
			glPopMatrix();

			// Body
			glPushMatrix();
			glColor4f(1.0, 1.0, 1.0, 1.0); // White
			glTranslatef(xPos, 10.f, zPos);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
			gluQuadricDrawStyle(gluQuadric, GLU_FILL);
			glPopMatrix();

			glPushMatrix();
			glColor4f(1.0, 0.0, 0.0, 1.0); // Red
			glTranslatef(xPos, 9.f, zPos);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
			gluQuadricDrawStyle(gluQuadric, GLU_FILL);
			glPopMatrix();

			glPushMatrix();
			glColor4f(1.0, 1.0, 1.0, 1.0); // White
			glTranslatef(xPos, 8.f, zPos);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
			gluQuadricDrawStyle(gluQuadric, GLU_FILL);
			glPopMatrix();

			glPushMatrix();
			glColor4f(1.0, 0.0, 0.0, 1.0); // Red
			glTranslatef(xPos, 7.f, zPos);
			glRotatef(-90, 1, 0, 0);
			gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
			gluQuadricDrawStyle(gluQuadric, GLU_FILL);
			glPopMatrix();
		}
	}
}