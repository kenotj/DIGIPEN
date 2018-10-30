/******************************************************************************/
/*!
\file   BulletManager.c
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This manager is in charge of spawning bullets exclusively for the player.
*/
/******************************************************************************/
#include "BulletManager.h"
#include "stdafx.h"
#include "MovingObjectManager.h"
#include <time.h>


void BulletManager_AddBulletIndex(int index);

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
static int bulletIndices[MAX_BULLETS]; /*Bullets are essentially MovingObject/s, hence we hold indices to the moving objects that are bullets*/
static float bulletLifeTimes[MAX_BULLETS]; /*Keeps track of bullet life time, updated for each Bullet that is active*/
static int bulletsInUse; /*Number of bullets currently in use*/
static float timeElapsed; /*Time elapsed since last bullet was fired. Used to control rate of fire*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Initialize the bullet manager. */
void BulletManager_Init()
{
	/*No bullets in use yet*/
	bulletsInUse = 0;

	/*Set all bullet related data to initial state*/
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		/*Initializing indices to -1. 
		Since indices can only be >= 0, -1 tells me that the bullet at this index is not active*/
		bulletIndices[i] = -1;
		bulletLifeTimes[i] = 0.0f;
	}
	timeElapsed = 0.0f;
}

/*----------------------------------------------------------------------------*/
/* Update bullet related data. */
void BulletManager_Update(float dt)
{
	timeElapsed += dt;
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (bulletIndices[i] == -1)
		{
			continue;
		}
		bulletLifeTimes[i] -= dt;
		if (bulletLifeTimes[i] <= 0.0f)
		{
			BulletManager_KillBullet(bulletIndices[i]);
		}
	}
}

/*----------------------------------------------------------------------------*/
/* Release all resources taken for use. In this case, all the moving objects that are used as bullets */
void BulletManager_Exit()
{
	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (bulletIndices[i] == -1)
		{
			continue;
		}
		BulletManager_KillBullet(bulletIndices[i]);
	}
}

/*----------------------------------------------------------------------------*/
/* Used by player to spawn bullet. Player decides the bullet's starting point and facing */
void BulletManager_SpawnBullet(float startingX, float startingY, Facing facing)
{
	if (bulletsInUse >= MAX_BULLETS)
	{
		return;
	}

	if (timeElapsed < RATE_OF_FIRE)
	{
		return;
	}
	else 
	{
		timeElapsed = 0.0f;
	}

	/*Getting an index to a moving object we can use*/
	int bulletIndex = MovingObjectManager_GetMovingObjectIndex();
	/*If all moving objects are in use, MovingObjectManager will give us an index of -1*/
	if (bulletIndex == -1)
	{
		/*Invalid index means we cannot do anything further with this bullet*/
		return;
	}
	/*Keep track of the index we got from MovingObjectManager*/
	BulletManager_AddBulletIndex(bulletIndex);

	/*Set the data for the moving object we got from MovingObjectManager*/
	MovingObjectManager_SetObjectType(bulletIndex, Bullet);
	MovingObjectManager_SetObjectPosition(bulletIndex, startingX, startingY);

	switch (facing)
	{
	case Up:
		MovingObjectManager_SetObjectVelocity(bulletIndex, 0.0f, -BULLET_SPEED);
		break;
	case Down:
		MovingObjectManager_SetObjectVelocity(bulletIndex, 0.0f, BULLET_SPEED);
		break;
	case Left:
		MovingObjectManager_SetObjectVelocity(bulletIndex, -BULLET_SPEED, 0.0f);
		break;
	case Right:
		MovingObjectManager_SetObjectVelocity(bulletIndex, BULLET_SPEED, 0.0f);
		break;
	}
}

/*----------------------------------------------------------------------------*/
/* Used by player to spawn bullet. Player decides the bullet's starting point and facing */
void BulletManager_KillBullet(int index)
{
	if (index < 0)
	{
		return;
	}

	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (bulletIndices[i] == index)
		{
			MovingObjectManager_ReturnMovingObjectIndex(bulletIndices[i]);
			bulletIndices[i] = -1;
			--bulletsInUse;
			return;
		}
	}
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/
void BulletManager_AddBulletIndex(int index)
{
	if (index < 0)
	{
		return;
	}

	for (int i = 0; i < MAX_BULLETS; ++i)
	{
		if (bulletIndices[i] == -1)
		{
			bulletIndices[i] = index;
			bulletLifeTimes[i] = BULLET_LIFETIME;
			++bulletsInUse;
			break;
		}
	}
}

