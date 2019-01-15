/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Object.h
Author: William Scott (wrs35) SN: 11876177
*/

#pragma once

class Object
{
public:
	GLUquadric* gluQuadric;
	// Textures
	const int numTextures = 5;
	GLuint txId[5];

	// Model Loading
	float *x, *y, *z;  //vertex coordinate arrays
	int *t1, *t2, *t3; //triangles
	int nvrt, ntri;    //total number of vertices and triangles


	Object(void);
	void loadTexture();
	void loadMeshFile(const char* fname);
	void normal(int tindx);
	static double randRangeDouble(double a, double b);
};