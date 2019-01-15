/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Camera.h
Author: William Scott (wrs35) SN: 11876177
*/

#pragma once

#include "stdafx.h"

class Camera
{
public:
	float  eye_x, eye_y, eye_z;    //Initial camera position
	float look_x, look_y, look_z;    //"Look-at" point along -z direction
	float  theta;                              //Look angle
	int step;								   //camera motion

public:
	Camera(void);
	void pressKey(int key, int xx, int yy);
	void lookAt();

private:
	float dir_y;
};