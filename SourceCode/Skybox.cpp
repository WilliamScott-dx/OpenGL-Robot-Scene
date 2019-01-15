/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Skybox.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Skybox.h"

Skybox::Skybox(void)
{
	loadTexture();
}

void Skybox::draw(void)
{
	float skyboxSize = 300.f;
	float groundLevel = 0.f;

	// Load Skybox Texture
	glBindTexture(GL_TEXTURE_2D, txId[1]);
	// Clear color before drawing
	glColor4f(1.0, 1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
	glTexCoord2f(0, 0); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
	glTexCoord2f(1, 0); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
	glTexCoord2f(1, 1); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
	glTexCoord2f(0, 0); glVertex3f(-skyboxSize, groundLevel, skyboxSize);
	glTexCoord2f(1, 0); glVertex3f(skyboxSize, groundLevel, skyboxSize);
	glTexCoord2f(1, 1); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
	glTexCoord2f(0, 0); glVertex3f(-skyboxSize, groundLevel, -skyboxSize);
	glTexCoord2f(1, 0); glVertex3f(skyboxSize, groundLevel, -skyboxSize);
	glTexCoord2f(1, 1); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3f(-skyboxSize, skyboxSize, -skyboxSize);
	glTexCoord2f(0, 0); glVertex3f(-skyboxSize, groundLevel, -skyboxSize);
	glTexCoord2f(1, 0); glVertex3f(-skyboxSize, groundLevel, skyboxSize);
	glTexCoord2f(1, 1); glVertex3f(-skyboxSize, skyboxSize, skyboxSize);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 1); glVertex3f(skyboxSize, skyboxSize, -skyboxSize);
	glTexCoord2f(0, 0); glVertex3f(skyboxSize, groundLevel, -skyboxSize);
	glTexCoord2f(1, 0); glVertex3f(skyboxSize, groundLevel, skyboxSize);
	glTexCoord2f(1, 1); glVertex3f(skyboxSize, skyboxSize, skyboxSize);
	glEnd();
}