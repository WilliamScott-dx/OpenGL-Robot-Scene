/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Camera.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Camera.h"
#include <GL/freeglut.h>

Camera::Camera(void)
{
	eye_x = 10, eye_y = 15, eye_z = 80;    //Initial camera position
	look_x = 12, look_y = 1, look_z = 10;    //"Look-at" point along -z direction
	theta = 0;                              //Look angle
	step = 0;								   //camera motion
	dir_y = 0.0f;

}

void Camera::pressKey(int key, int xx, int yy)
{
	switch (key) {
	case GLUT_KEY_LEFT: theta += 0.085f; break;
	case GLUT_KEY_RIGHT: theta -= 0.085f; break;
	case GLUT_KEY_UP: step = 1; break;
	case GLUT_KEY_DOWN: step = -1; break;
	case GLUT_KEY_PAGE_UP: if (dir_y <= 0.7)
	{
		dir_y += 0.1;
	} break;
	case GLUT_KEY_PAGE_DOWN: if (dir_y >= -0.7)
	{
		dir_y -= 0.1;
	} break;
	}
}

void Camera::lookAt()
{
	float dir_x = -sin(theta);
	float dir_z = -cos(theta);
	eye_x = eye_x + 1 * dir_x * step;
	eye_z = eye_z + 1* dir_z * step;
	look_x = eye_x + 2 * dir_x;
	look_y = eye_y + 2 * dir_y;
	look_z = eye_z + 2 * dir_z;
	step = 0;

	gluLookAt(eye_x, eye_y, eye_z, look_x, look_y, look_z, 0, 1, 0);
	glutPostRedisplay();
}