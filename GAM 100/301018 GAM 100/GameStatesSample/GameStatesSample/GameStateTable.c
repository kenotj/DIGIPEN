/******************************************************************************/
/*!
\file   GameStateTable.c
\author Doug Schilling
\par    Course: GAM100
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#include <stdlib.h>
#include <stdbool.h> /* bool */
#include "GameStateManager.h"
#include "GameStateTable.h"

/* Include all game state headers here. */
#include "GameStateDigiPenLogo.h"
#include "GameStateMainMenu.h"
#include "GameStateGameOver.h"
#include "GameStateDemo.h"
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

/*----------------------------------------------------------------------------*/
/* Determine if the game state is valid. */
bool GameState_IsValid(GAMESTATE gameState)
{
	return ((0 <= gameState) && (gameState < GsMax));
}

/*----------------------------------------------------------------------------*/
/* Determine if the game state is a "special" game state. */
bool GameState_IsSpecial(GAMESTATE gameState)
{
	return ((gameState == GsRestart) || (gameState == GsQuit));
}

/*----------------------------------------------------------------------------*/
/* Execute the Init function for the current game state. */
void GameState_ExecuteInit(GAMESTATE gameState)
{
	/* First validate the game state and the function pointer. */
	if (GameState_IsValid(gameState))
	{
		/* Execute the Init function. */
		switch (gameState)
		{
		case GsDemo:
			GameStateDemo_Init();
			break;
		case GsDigiPenLogo:
			GameStateDigiPenLogo_Init();
			break;
		case GsGameOver:
			GameStateGameOver_Init();
			break;
		case GsMainMenu:
			GameStateMainMenu_Init();
			break;
		default:
			break;
		}
	}
}

/*----------------------------------------------------------------------------*/
/* Execute the Update function for the current game state. */
void GameState_ExecuteUpdate(GAMESTATE gameState, float dt)
{
	/* First validate the game state and the function pointer. */
	if (GameState_IsValid(gameState))
	{
		/* Execute the Update function. */

		switch (gameState)
		{
		case GsDemo:
			GameStateDemo_Update(dt);
			break;
		case GsDigiPenLogo:
			GameStateDigiPenLogo_Update(dt);
			break;
		case GsGameOver:
			GameStateGameOver_Update(dt);
			break;
		case GsMainMenu:
			GameStateMainMenu_Update(dt);
			break;
		default:
			break;
		}
	}
}

/*----------------------------------------------------------------------------*/
/* Execute the Exit function for the current game state. */
void GameState_ExecuteExit(GAMESTATE gameState)
{
	/* First validate the game state and the function pointer. */
	if (GameState_IsValid(gameState))
	{
		/* Execute the Exit function. */

		switch (gameState)
		{
		case GsDemo:
			GameStateDemo_Exit();
			break;
		case GsDigiPenLogo:
			GameStateDigiPenLogo_Exit();
			break;
		case GsGameOver:
			GameStateGameOver_Exit();
			break;
		case GsMainMenu:
			GameStateMainMenu_Exit();
			break;
		default:
			break;
		}
	}
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

