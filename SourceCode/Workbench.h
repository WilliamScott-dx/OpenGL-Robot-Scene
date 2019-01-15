/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Workbench.h
Author: William Scott (wrs35) SN: 11876177
*/

#pragma once
#include "Object.h"

class Workbench : public Object
{
public:
	Workbench(void);
	void draw(void);

private:
	void drawFireworkGroup();
};