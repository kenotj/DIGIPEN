
/******************************************************************************/
/*!
\file   GameStateDemo.c
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief 
*/
/******************************************************************************/
#include "WindowsHelper.h"
#include "PlayerManager.h"
#include "MovingObjectManager.h"
#include "RenderManager.h"
#include "BulletManager.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
void GameStateDemo_Init()
{
	WindowsHelper_Init();
	RenderManager_Init();
	MovingObjectManager_Init();
	PlayerManager_Init();
	BulletManager_Init();
}

void GameStateDemo_Update(float dt)
{
	MovingObjectManager_Update(dt);
	PlayerManager_Update(dt);
	BulletManager_Update(dt);
	RenderManager_Draw();
}

void GameStateDemo_Exit()
{
	BulletManager_Exit();
	PlayerManager_Exit();
	WindowsHelper_ClearScreen();
}