/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Object.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Object.h"
#include "loadTGA.h"

Object::Object()
{
	gluQuadric = gluNewQuadric();
}

// Function to load a texture in bmp format
void Object::loadTexture()
{
	glGenTextures(numTextures, &txId[0]); 				// Create a Texture object

	// Grass
	glBindTexture(GL_TEXTURE_2D, txId[0]);
	loadTGA("./Textures/Grass.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Skybox
	glBindTexture(GL_TEXTURE_2D, txId[1]);
	loadTGA("./Textures/Skybox.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Clock Body
	glBindTexture(GL_TEXTURE_2D, txId[2]);
	loadTGA("./Textures/ClockBody.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Clock Face
	glBindTexture(GL_TEXTURE_2D, txId[3]);
	loadTGA("./Textures/ClockFace.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Wood
	glBindTexture(GL_TEXTURE_2D, txId[4]);
	loadTGA("./Textures/Wood.tga");
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

//-- Loads mesh data in OFF format    -------------------------------------
void Object::loadMeshFile(const char* fname)
{
	ifstream fp_in;
	int num, ne;

	fp_in.open(fname, ios::in);
	if (!fp_in.is_open())
	{
		cout << "Error opening mesh file" << endl;
		exit(1);
	}

	fp_in.ignore(INT_MAX, '\n');				//ignore first line
	fp_in >> nvrt >> ntri >> ne;			    // read number of vertices, polygons, edges

	x = new float[nvrt];                        //create arrays
	y = new float[nvrt];
	z = new float[nvrt];

	t1 = new int[ntri];
	t2 = new int[ntri];
	t3 = new int[ntri];

	for (int i = 0; i < nvrt; i++)                         //read vertex list 
		fp_in >> x[i] >> y[i] >> z[i];

	for (int i = 0; i < ntri; i++)                         //read polygon list 
	{
		fp_in >> num >> t1[i] >> t2[i] >> t3[i];
		if (num != 3)
		{
			cout << "ERROR: Polygon with index " << i << " is not a triangle." << endl;  //not a triangle!!
			exit(1);
		}
	}

	fp_in.close();
	cout << " File successfully read." << endl;
}

void Object::normal(int tindx)
{
	float x1 = x[t1[tindx]], x2 = x[t2[tindx]], x3 = x[t3[tindx]];
	float y1 = y[t1[tindx]], y2 = y[t2[tindx]], y3 = y[t3[tindx]];
	float z1 = z[t1[tindx]], z2 = z[t2[tindx]], z3 = z[t3[tindx]];
	float nx, ny, nz;
	nx = y1*(z2 - z3) + y2*(z3 - z1) + y3*(z1 - z2);
	ny = z1*(x2 - x3) + z2*(x3 - x1) + z3*(x1 - x2);
	nz = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
	glNormal3f(nx, ny, nz);
}

double Object::randRangeDouble(double a, double b)
{
	return a + (rand() / (RAND_MAX / (b - a)));
}