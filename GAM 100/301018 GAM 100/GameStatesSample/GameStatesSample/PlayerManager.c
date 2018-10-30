/******************************************************************************/
/*!
\file   PlayerManager.c
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This manager is in charge of processing player controls and actions
*/
/******************************************************************************/
#include "PlayerManager.h"
#include "MovingObjectManager.h"
#include <Windows.h>
#include <math.h>
#include "Enum.h"
#include "BulletManager.h"
#include "GameStateTable.h"
#include "GameStateManager.h"

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
static Facing playerFacing;
static int playerObjectIndex;

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Initialize the bullet manager. */
void PlayerManager_Init()
{
	/*Initializing player data*/
	playerFacing = Right;

	/*The player character is a moving object, so we ask the MovingObjectManager for a moving object*/
	playerObjectIndex = MovingObjectManager_GetMovingObjectIndex();
	/*Setting the player data in the moving object we got*/
	MovingObjectManager_SetObjectType(playerObjectIndex, Player);
}

/*----------------------------------------------------------------------------*/
/* Updates by getting player input. dt not used here */
void PlayerManager_Update(float dt)
{
	UNREFERENCED_PARAMETER(dt);
	/*The moving object is updated and maintained by the MovingObjectManager, so
	we get our Player moving object positions from the manager using the index we got 
	earlier*/
	float x = MovingObjectManager_GetObjectPositionX(playerObjectIndex);
	float y = MovingObjectManager_GetObjectPositionY(playerObjectIndex);

	/*Bare bones WASD controls for movement of player, and space bar for shooting*/
	if (GetAsyncKeyState(0x57))
	{
		/*Up*/
		if (playerFacing == Up)
		{
			y = max(y - 1.0f, 0.0f);
			MovingObjectManager_SetObjectPosition(playerObjectIndex,x, y);
		}
		else
		{
			playerFacing = Up;
		}
	}

	else if (GetAsyncKeyState(0x53))
	{
		/*Down*/
		if (playerFacing == Down)
		{
			y = max(y + 1.0f, 0.0f);
			MovingObjectManager_SetObjectPosition(playerObjectIndex, x, y);
		}
		else
		{
			playerFacing = Down;
		}
	}

	else if (GetAsyncKeyState(0x41))
	{
		/*Left*/
		if (playerFacing == Left)
		{
			x = max(x - 1.0f, 0.0f);
			MovingObjectManager_SetObjectPosition(playerObjectIndex, x, y);
		}
		else
		{
			playerFacing = Left;
		}
	}

	else if (GetAsyncKeyState(0x44))
	{
		/*Right*/
		if (playerFacing == Right)
		{
			x = max(x + 1.0f, 0.0f);
			MovingObjectManager_SetObjectPosition(playerObjectIndex, x, y);
		}
		else
		{
			playerFacing = Right;
		}
	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		/*Shoot*/
		switch (playerFacing)
		{
		case Up:
			BulletManager_SpawnBullet(x, y - 1, playerFacing);
			break;
		case Down:
			BulletManager_SpawnBullet(x, y + 1, playerFacing);
			break;
		case Left:
			BulletManager_SpawnBullet(x -1, y, playerFacing);
			break;
		case Right:
			BulletManager_SpawnBullet(x + 1, y, playerFacing);
			break;
		}
	}
	/*Used to escape current state*/
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		/*Used to transition to MainMenu state*/
		GameStateManager_SetNextState(GsMainMenu);
	}
}

/*----------------------------------------------------------------------------*/
/* Exit function of PlayerManager, used to return resources used */
void PlayerManager_Exit()
{
	/*Always return whatever resources you took*/
	MovingObjectManager_ReturnMovingObjectIndex(playerObjectIndex);
}

char PlayerManager_GetPlayerDisplay()
{
	switch (playerFacing)
	{
	case Up:
		return 94;
	case Down:
		return 'v';
	case Left:
		return '<';
	case Right:
		return '>';
	}

	return '0';
}




