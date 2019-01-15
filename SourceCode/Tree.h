/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Tree.h
Author: William Scott (wrs35) SN: 11876177
*/

#pragma once
#include "Object.h"

class Tree: public Object
{
public:
	float leavesX;

	Tree(void);
	void draw(void);
	void updateLeaves(void);
};