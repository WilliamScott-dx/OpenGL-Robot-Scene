/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Launchpad.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Launchpad.h"

Launchpad::Launchpad(void){}

void Launchpad::draw(void)
{
	float xPos = 0.f;
	float zPos = 50.f;

	// Base
	glColor4f(0.7f, 0.7f, 0.7f, 1.0f); // Grey
	glPushMatrix();
	glTranslatef(xPos, 6.f, zPos);
	glScalef(5.f, 0.3f, 5.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Rod
	glPushMatrix();
	glTranslatef(xPos, 6.f, zPos);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, 0.2, 0.2, 4, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();
}