/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Ground.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Ground.h"

Ground::Ground(void){}

/* Renders a checkered floor */
void Ground::draw(void)
{
	bool flag = false;
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	for (float x = -300.f; x <= 300.f; x += 10.f)
	{
		for (float z = -300.f; z <= 300.f; z += 10.f)
		{
			if (flag) glColor3f(0.6f, 0.4f, 0.f);
			else glColor3f(1.f, 0.8f, 0.4f);
			glVertex3f(x, 0.f, z);
			glVertex3f(x, 0.f, z + 10.f);
			glVertex3f(x + 10.f, 0.f, z + 10.f);
			glVertex3f(x + 10.f, 0.f, z);
			flag = !flag;
		}
	}
	glEnd();
}
