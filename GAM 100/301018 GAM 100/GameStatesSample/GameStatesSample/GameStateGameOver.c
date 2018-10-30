/******************************************************************************/
/*!
	\file   GameStateGameOver.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/
#include "stdafx.h"
#include "GameStateGameOver.h"
#include "GameStateManager.h"
#include "WindowsHelper.h"

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

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void GameStateGameOver_Init()
{
	/* NOTE: There is nothing to be done here.  The game results text was
		 printed to the screen before this game state was initiated. */
}

void GameStateGameOver_Update(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* TODO BASIC: Print the message "Press ENTER to continue..." to the screen. */
	printf("Press ENTER to continue...");

	/* TODO : Wait for the user to press ENTER. */
	getchar();

	/* TODO REQUIRED: Tell the game state manager to switch to the Main Menu state. */
	GameStateManager_SetNextState(GsMainMenu);
}

void GameStateGameOver_Exit()
{
	WindowsHelper_ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

