/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Clock.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Clock.h"

Clock::Clock(void)
{
	loadTexture();
	loadMeshFile("./Models/Clock.off");
}

void Clock::draw(void)
{
	gluQuadricTexture(gluQuadric, 1);
	glColor4f(1.f, 1.f, 1.f, 1.0f); // White
	// Clock Body
	glBindTexture(GL_TEXTURE_2D, txId[2]);
	glBegin(GL_TRIANGLES);
	for (int tindx = 0; tindx < ntri; tindx++)
	{
		normal(tindx);
		glTexCoord2f(0, 0); glVertex3d(x[t1[tindx]] * 2, y[t1[tindx]] * 2, z[t1[tindx]]);
		glTexCoord2f(1, 0); glVertex3d(x[t2[tindx]] * 2, y[t2[tindx]] * 2, z[t2[tindx]]);
		glTexCoord2f(0, 1); glVertex3d(x[t3[tindx]] * 2, y[t3[tindx]] * 2, z[t3[tindx]]);
	}
	glEnd();

	// Clock Face
	glBindTexture(GL_TEXTURE_2D, txId[3]);
	glPushMatrix();
	glTranslatef(25.f, 5.5f, 3.3f);
	glTexCoord2f(0, 0); gluDisk(gluQuadric, 0.0, 4.0, 20, 2);
	glPopMatrix();

	// Hour Hand
	static float hourTheta = 20.f;
	hourTheta += 0.01f;
	glColor4f(0.f, 0.f, 0.f, 1.0f); // Black
	glPushMatrix();
	glTranslatef(25.f, 5.5, 3.4f);
	glRotatef(hourTheta, 0, 0, -1);
	glTranslatef(-25.f, -5.5, -3.4f);
	glTranslatef(25.f, 4.5, 3.4f);
	glScalef(1.f, 3.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Minute Hand
	static float minuteTheta = 120.f;
	minuteTheta += 0.1f;
	glPushMatrix();
	glTranslatef(25.f, 5.5, 3.4f);
	glRotatef(minuteTheta, 0, 0, -1);
	glTranslatef(-25.f, -5.5, -3.4f);
	glTranslatef(25.f, 4.5, 3.4f);
	glScalef(1.f, 5.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}