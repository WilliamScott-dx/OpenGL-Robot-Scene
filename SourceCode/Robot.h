/*
COSC363: Computer Graphics (2017);  University of Canterbury.
FILE NAME: Robot.h
Author: William Scott (wrs35) SN: 11876177
*/

#pragma once
#include "Object.h"

class Robot : public Object
{
public:
	Robot(void);
	void draw(void);
	void update(void);

private:
	bool bHoldingFirework;
	bool bLaunchFireworkExists;
	bool bArmsExtended;
	bool bWalking;

	float robotXPos;
	float robotYPos;
	float robotZPos;
	float robotRotation;
	float leftArmExtention;
	float rightArmExtention;
	float leftLegRotation;
	float rightLegRotation;

	// Robot
	void drawHead(void);
	void drawBody(void);
	void drawArms(void);
	void drawLegs(void);

	// Firework
	bool bFireworkLaunching;
	float launchFireworkY;
	void drawHeldFirework(void);
	void drawLaunchFirework(void);
	void drawFireworkFire(void);

	// Firework Explosion
	bool bFireworkExploding;
	float MAX_PARTICLES;
	float FIREWORK_RADIUS;
	float fwParticleX[100];
	float fwParticleY[100];
	float fwParticleZ[100];
	float fwParticleAlpha[100];
	void initializeFireworkExplosion(void);
	void updateFireworkExplosion(void);
	void drawFireworkExplosion(void);
	
	// Movement Anims
	void updateRotation(void);
	void extendArms(void);
	void retractArms(void);
	void walk(void);
};