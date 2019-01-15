/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Robot.cpp
Author: William Scott (wrs35) SN: 11876177
*/

#include "stdafx.h"
#include "Robot.h"

Robot::Robot(void)
{
	bHoldingFirework = false;
	bFireworkExploding = false;
	MAX_PARTICLES = 100;
	FIREWORK_RADIUS = 100;

	robotXPos = 0.f;
	robotYPos = 10.f;
	robotZPos = 40.f;
	robotRotation = 180.f;

	bFireworkLaunching = false;
	launchFireworkY = 4.f; // Launch pad height

	bArmsExtended = false;
	leftArmExtention = 0.f;
	rightArmExtention = 0.f;

	leftLegRotation = 0.f;
	rightLegRotation = 0.f;
}

void Robot::updateRotation(void)
{
	glTranslatef(robotXPos, robotYPos, robotZPos);
	glRotatef(robotRotation, 0, 1, 0);
	glTranslatef(-robotXPos, -robotYPos, -robotZPos);
}

void Robot::drawHead(void)
{
	// Antenna Light
	glDisable(GL_LIGHTING);
	glColor4f(1.f, 0.f, 0.f, 1.0f);  // Red
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, 13.f, robotZPos);
	gluSphere(gluQuadric, 0.5, 10, 5);
	glPopMatrix();
	glEnable(GL_LIGHTING);

	//Set light Antenna Light and enable
	float lightPosition[4] = { robotXPos, 15.f, robotZPos, 1.0 };
	float spotDirection[4] = { 0.f, -1.f, 0.f };
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection);

	// Antenna Connector
	glColor4f(0.7f, 0.7f, 0.7f, 1.0f); // Grey
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, robotYPos + 3.f, robotZPos);
	glRotatef(90, 1, 0, 0);
	gluCylinder(gluQuadric, 0.2, 0.2, 4, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	// Head
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, robotYPos, robotZPos);
	glScalef(2.f, 2.f, 2.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Eye
	glDisable(GL_LIGHTING);
	glColor4f(1.f, 0.f, 0.f, 1.0f); // Red
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, robotYPos, robotZPos + 0.5f);
	glScalef(1.5f, 0.5f, 1.5f);
	glutSolidCube(1.f);
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

void Robot::drawBody(void)
{
	// Body
	glColor4f(0.7f, 0.7f, 0.7f, 1.0f); // Grey
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, robotYPos - 3.5f, robotZPos);
	glScalef(3.f, 5.f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Winder
	glColor4f(1.0f, 0.9f, 0.7f, 1.f); // Gold
	static float winderRotation = 0;
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos, 6.5f, robotZPos - 2.f);
	glRotatef(winderRotation, 0, 0, 1);
	glScalef(1.f, 2.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
	winderRotation += 0.05f;
}

void Robot::drawArms(void)
{
	// Left Arm
	glColor4f(0.7f, 0.7f, 0.7f, 1.0f); // Grey
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos + 2.f, 6.5f, robotZPos + leftArmExtention);
	glRotatef(90.f, 1, 0, 0);
	glScalef(1.f, 4.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Right Arm
	glPushMatrix();
	updateRotation();
	glTranslatef(robotXPos - 2.f, 6.5f, robotZPos + rightArmExtention);
	glRotatef(90.f, 1, 0, 0);
	glScalef(1.f, 4.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Robot::drawLegs(void)
{
	glColor4f(0.7f, 0.7f, 0.7f, 1.0f); // Grey

									   // Left Leg
	glPushMatrix();
	updateRotation();
	// Update Leg Rotation
	glTranslatef(robotXPos + 2.f, 5.5f, robotZPos);
	glRotatef(leftLegRotation, 1, 0, 0);
	glTranslatef(-robotXPos - 2.f, -5.5f, -robotZPos);
	// Actual translation
	glTranslatef(robotXPos + 2.f, 3.5f, robotZPos);
	glRotatef(0.f, 1, 0, 0);
	glScalef(1.f, 4.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	// Right Leg
	glPushMatrix();
	updateRotation();
	// Update Leg Rotation
	glTranslatef(robotXPos + 2.f, 5.5f, robotZPos);
	glRotatef(rightLegRotation, 1, 0, 0);
	glTranslatef(-robotXPos - 2.f, -5.5f, -robotZPos);
	// Actual translation
	glTranslatef(robotXPos - 2.f, 3.5f, robotZPos);
	glRotatef(0.f, 1, 0, 0);
	glScalef(1.f, 4.f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void Robot::drawHeldFirework(void)
{
	float fireworkX = robotXPos + 0.f;
	float fireworkZ = robotZPos + 4.f;

	// Top
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glPushMatrix();
	updateRotation();
	glTranslatef(fireworkX, 11.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(2.f, 3, 5, 5);
	glPopMatrix();

	// Body
	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 1.0, 1.0, 1.0); // White
	glTranslatef(fireworkX, 10.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glTranslatef(fireworkX, 9.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 1.0, 1.0, 1.0); // White
	glTranslatef(fireworkX, 8.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glTranslatef(fireworkX, 7.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();
}

void Robot::drawLaunchFirework(void)
{
	float fireworkX = 0.f;
	float fireworkZ = 50.f;

	// Top
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glPushMatrix();
	updateRotation();
	glTranslatef(fireworkX, launchFireworkY + 7.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(2.f, 3, 5, 5);
	glPopMatrix();

	// Body
	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 1.0, 1.0, 1.0); // White
	glTranslatef(fireworkX, launchFireworkY + 6.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glTranslatef(fireworkX, launchFireworkY + 5.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 1.0, 1.0, 1.0); // White
	glTranslatef(fireworkX, launchFireworkY + 4.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	glPushMatrix();
	updateRotation();
	glColor4f(1.0, 0.0, 0.0, 1.0); // Red
	glTranslatef(fireworkX, launchFireworkY + 3.f, fireworkZ);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(gluQuadric, 1.f, 1.f, 1, 5, 5);
	gluQuadricDrawStyle(gluQuadric, GLU_FILL);
	glPopMatrix();

	if (bFireworkLaunching)
	{
		drawFireworkFire();
	}
}

void Robot::drawFireworkFire(void)
{
	const int MAX_PARTICLES = 30;
	const int FIREWORK_RADIUS = 3;

	static float posX[MAX_PARTICLES];
	static float posY[MAX_PARTICLES];
	static float posZ[MAX_PARTICLES];
	static float alpha[MAX_PARTICLES];

	glDisable(GL_LIGHTING);
	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		int randomRadius = rand() % FIREWORK_RADIUS;
		int randomAngle = rand() % 360;

		double x = randomRadius * cos(randomAngle);
		double y = rand() % 3;
		double z = randomRadius * sin(randomAngle);

		posX[i] = (float)x;
		posY[i] = (float)y + launchFireworkY + 0.5f; // Place below the rocket
		posZ[i] = (float)z + 50.f;
	}

	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		glPointSize(randRangeDouble(10.f, 20.f));
		float red = randRangeDouble(0.7f, 1.f);
		float green = randRangeDouble(0.f, 0.3f);
		float blue = randRangeDouble(0.f, 0.3f);
		glColor4f(red, green, blue, 1.f);
		glBegin(GL_POINTS);
		glVertex3f(posX[i], posY[i], posZ[i]);
		glEnd();
	}
	glEnable(GL_LIGHTING);
}


void Robot::draw(void)
{
	drawHead();
	drawBody();
	drawArms();
	drawLegs();
	if (bHoldingFirework)
	{
		drawHeldFirework();
	}
	else if (bLaunchFireworkExists)
	{
		drawLaunchFirework();
	}
	else if (bFireworkExploding)
	{
		drawFireworkExplosion();
	}
}

void Robot::update(void)
{
	static int currentStep = 0;

	// Walk to table
	if (currentStep == 0)
	{
		if (robotZPos > 20.f)
		{
			robotZPos -= 0.05f;
		}
		else
		{
			currentStep++;
		}
		walk();
	}
	// Stop and extend arms
	else if (currentStep == 1)
	{
		if (!bArmsExtended)
		{
			extendArms();
		}
		else
		{
			currentStep++;
		}
	}
	// Pick up firework
	else if (currentStep == 2)
	{
		bHoldingFirework = true;
		currentStep++;
	}
	// Rotate 180
	else if (currentStep == 3)
	{
		static float currRotation = 0.f;
		const float rotationSpeed = 1.f;

		walk();
		robotRotation += rotationSpeed;
		currRotation += rotationSpeed;

		if (currRotation >= 180.f)
		{
			currRotation = 0.f;
			currentStep++;
		}
	}
	// Walk to launchpad
	else if (currentStep == 4)
	{
		if (robotZPos < 44.f)
		{
			robotZPos += 0.05f;
		}
		else
		{
			currentStep++;
		}
		walk();
	}
	//Stop Place firework
	else if (currentStep == 5)
	{
		bHoldingFirework = false;
		bLaunchFireworkExists = true;
		leftLegRotation = 0.f;
		rightLegRotation = 0.f;
		currentStep++; // Placeholder
	}
	// Retract arms
	else if (currentStep == 6)
	{
		if (bArmsExtended)
		{
			retractArms();
		}
		else
		{
			currentStep++;
		}
	}
	// Pause before launch
	else if (currentStep == 7)
	{
		static int pauseCount = 0;
		pauseCount++;
		if (pauseCount >= 40)
		{
			currentStep++;
			pauseCount = 0;
			bFireworkLaunching = true;
		}
	}
	// Engage Rocket
	else if (currentStep == 8)
	{
		static int pauseCount = 0;
		pauseCount++;
		if (pauseCount >= 60)
		{
			currentStep++;
			pauseCount = 0;
		}
	}
	// Make Firework Fly up
	else if (currentStep == 9)
	{
		const float fireworkSpeed = 2.f;
		launchFireworkY += fireworkSpeed;

		if (launchFireworkY >= 100)
		{
			bLaunchFireworkExists = false;
			launchFireworkY = 4.f; // Reset to height of launch pad
			currentStep++;
		}
	}
	// Create firework explosion
	else if (currentStep == 10)
	{
		if (!bFireworkExploding)
		{
			initializeFireworkExplosion();
			bFireworkExploding = true;
		}
		else
		{
			updateFireworkExplosion();
		}

		if (!bFireworkExploding)
		{
			currentStep++;
		}
	}
	// Rotate 180
	else if (currentStep == 11)
	{
		static float currRotation = 0.f;
		const float rotationSpeed = 1.f;

		walk();
		robotRotation += rotationSpeed;
		currRotation += rotationSpeed;

		if (currRotation >= 180.f)
		{
			currRotation = 0.f;
			currentStep = 0; // Go back to the beginning
		}
	}
}

void Robot::extendArms(void)
{
	if (leftArmExtention <= 3.f)
	{
		leftArmExtention += 0.5f;
	}
	if (rightArmExtention <= 3.f)
	{
		rightArmExtention += 0.5f;
	}
	if (leftArmExtention >= 3.f)
	{
		bArmsExtended = true;
	}
}

void Robot::retractArms(void)
{
	if (leftArmExtention >= 0.f)
	{
		leftArmExtention -= 0.5f;
	}
	if (rightArmExtention >= 0.f)
	{
		rightArmExtention -= 0.5f;
	}
	if (leftArmExtention <= 0.f)
	{
		bArmsExtended = false;
	}
}

void Robot::walk(void)
{
	static bool bLeftLegTurnToMove = false;
	static bool bRaising = true;
	const float speed = 2.5f;
	const float maxRaiseRot = -50.f;

	if (bLeftLegTurnToMove)
	{
		if (bRaising)
		{
			leftLegRotation -= speed;
			if (leftLegRotation <= maxRaiseRot)
			{
				bRaising = false;
			}
		}
		else
		{
			leftLegRotation += speed;
			if (leftLegRotation >= 0.f)
			{
				bRaising = true;
				bLeftLegTurnToMove = false;
			}
		}
	}
	else // Right leg moving
	{
		if (bRaising)
		{
			rightLegRotation -= speed;
			if (rightLegRotation <= maxRaiseRot)
			{
				bRaising = false;
			}
		}
		else
		{
			rightLegRotation += speed;
			if (rightLegRotation >= 0.f)
			{
				bRaising = true;
				bLeftLegTurnToMove = true;
			}
		}
	}
}

void Robot::initializeFireworkExplosion(void)
{
	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		int randomRadius = rand() % 50; // Firework radius
		int randomAngle = rand() % 360;

		float x = randomRadius * cos(randomAngle);
		float y = rand() % 30 + 100; // add 100 to place at explosion hegiht
		float z = randomRadius * sin(randomAngle) + 50; // places above launchpad

		fwParticleX[i] = x;
		fwParticleY[i] = y;
		fwParticleZ[i] = z;
		fwParticleAlpha[i] = 1.f;
		bFireworkExploding = true;
	}
}

void Robot::updateFireworkExplosion(void)
{
	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		fwParticleX[i] -= randRangeDouble(-0.1f, 0.1f);
		fwParticleY[i] -= randRangeDouble(0.01f, 0.05f);
		fwParticleZ[i] -= randRangeDouble(-0.1f, 0.1f);
		fwParticleAlpha[i] -= 0.001f;
		if (fwParticleAlpha[i] <= 0)
		{
			bFireworkExploding = false;
		}
	}
}

void Robot::drawFireworkExplosion(void)
{
	glDisable(GL_LIGHTING);

	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		float red = randRangeDouble(0.7f, 1.f);
		float green = randRangeDouble(0.f, 0.3f);
		float blue = randRangeDouble(0.f, 0.3f);
		glColor4f(red, green, blue, fwParticleAlpha[i]);
		glPointSize(randRangeDouble(10.f, 25.f));

		glBegin(GL_POINTS);
		glVertex3f(fwParticleX[i], fwParticleY[i], fwParticleZ[i]);
		glEnd();
	}
	glEnable(GL_LIGHTING);
}