/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Tree.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Tree.h"

Tree::Tree(void)
{
	leavesX = 0.f;
	gluQuadric = gluNewQuadric();
	loadTexture();
}

void Tree::draw(void)
{
	float shadowMat[16] = { 50,0.1f,0.1f,0.1f, -0.1f,0.1f,-0.1f,-1,
		0.1f,0.1f,50,0.1f, 0.1f,0.1f,0.1f,50 };

	// Trunk
	glColor4f(0.9f, 0.8f, 0.7f, 1.0f);
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, txId[4]); // Wood
	gluQuadricTexture(gluQuadric, 1);
	glTranslatef(10, 13.f, 0);
	glRotatef(90, 1, 0, 0);
	glTexCoord2f(0, 1); gluCylinder(gluQuadric, 3.f, 3.f, 13.f, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();
	// Trunk Shadow
	glDisable(GL_LIGHTING);
	glPushMatrix(); //Draw Shadow Object
	glMultMatrixf(shadowMat);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glTranslatef(10.f, 13.f, 0.f);
	glRotatef(90, 1, 0, 0);
	glTexCoord2f(0, 1); gluCylinder(gluQuadric, 3.f, 3.f, 13.f, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	// Leaf Group Left
	glBindTexture(GL_TEXTURE_2D, txId[0]); // Grass
	glColor4f(0.2f, 1.f, 0.2f, 1.0f);
	glPushMatrix();
	glTranslatef(leavesX + 5, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 4.f, 10, 5);
	glPopMatrix();
	// Shadow
	glDisable(GL_LIGHTING);
	glPushMatrix(); //Draw Shadow Object
	glMultMatrixf(shadowMat);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glTranslatef(leavesX + 5, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 4.f, 10, 5);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	// Leaf Group Middle
	glColor4f(0.2f, 1.f, 0.2f, 1.0f);
	glPushMatrix();
	glTranslatef(leavesX + 10, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 6.f, 10, 5);
	glPopMatrix();
	// Shadow
	glDisable(GL_LIGHTING);
	glPushMatrix(); //Draw Shadow Object
	glMultMatrixf(shadowMat);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glTranslatef(leavesX + 10, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 6.f, 10, 5);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	// Leaf Upper Middle
	glColor4f(0.2f, 1.f, 0.2f, 1.0f);
	glPushMatrix();
	glTranslatef(leavesX + 10, 18.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 3.5f, 10, 5);
	glPopMatrix();
	// Shadow
	glDisable(GL_LIGHTING);
	glPushMatrix(); //Draw Shadow Object
	glMultMatrixf(shadowMat);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glTranslatef(leavesX + 10, 18.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 3.5f, 10, 5);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	// Leaf Group Right
	glColor4f(0.2f, 1.f, 0.2f, 1.0f);
	glPushMatrix();
	glTranslatef(leavesX + 15, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 4.f, 10, 5);
	glPopMatrix();
	// Shadow
	glDisable(GL_LIGHTING);
	glPushMatrix(); //Draw Shadow Object
	glMultMatrixf(shadowMat);
	glColor4f(0.0, 0.0, 0.0, 1.0);
	glTranslatef(leavesX + 15, 13.f, 0);
	glTexCoord2f(0, 0); gluSphere(gluQuadric, 4.f, 10, 5);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void Tree::updateLeaves(void)
{
	// Update Tree
	static bool bLeavesGoingRight = false;
	const float rustleDistance = 0.5f;
	const float rustleAmount = 0.01f;
	if (bLeavesGoingRight)
	{
		leavesX += rustleAmount;
		if (leavesX >= rustleDistance)
		{
			bLeavesGoingRight = !bLeavesGoingRight;
		}
	}
	else
	{
		leavesX -= rustleAmount;
		if (leavesX <= -rustleDistance)
		{
			bLeavesGoingRight = !bLeavesGoingRight;
		}
	}
}