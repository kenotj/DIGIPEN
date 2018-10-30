/******************************************************************************/
/*!
\file   GameStateManager.c
\author Doug Schilling
\par    Course: GAM100
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#include "GameStateManager.h"
#include "GameStateTable.h"
#include "stdafx.h"
/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/

typedef struct
{
	GAMESTATE	current;	/* Index of the current game state. */
	GAMESTATE	previous;	/* Index of the previous game state. */
	GAMESTATE	next;		/* Index of the next game state. */

} GameState;

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/

static GameState gameState;

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

static bool	GameState_IsChanging();

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Initialize the game state manager. */
void GameStateManager_Init()
{
	/* Set the current game state to invalid. */
	gameState.current = GsInvalid;

	/* Set the initial game state to launch the game. */
	gameState.next = GsInitial;
}

/*----------------------------------------------------------------------------*/
/* Update the game state manager. */
void GameStateManager_Update(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */

	if (GameState_IsChanging())
	{
		/* Exit the current game state. */
		GameState_ExecuteExit(gameState.current);

		/* Update previous, current and next states. */
		gameState.previous = gameState.current;
		if (gameState.next == GsRestart)
		{
			gameState.next = gameState.current;
		}
		else
		{
			gameState.current = gameState.next;
		}

		/* Initialize the new game state. */
		GameState_ExecuteInit(gameState.current);
	}

	/* Update the current game state. */
	GameState_ExecuteUpdate(gameState.current, dt);

}

/*----------------------------------------------------------------------------*/
/* Shutdown the game state manager. */
void GameStateManager_Exit()
{
}

/*----------------------------------------------------------------------------*/
/* Determine if the game is still running. */
bool GameStateManager_IsRunning()
{
	return gameState.next != GsQuit;
}

/*----------------------------------------------------------------------------*/
/* Set the next game state to run. */
void GameStateManager_SetNextState(GAMESTATE nextState)
{
	if (GameState_IsValid(nextState) || GameState_IsSpecial(nextState))
	{
		gameState.next = nextState;
	}
	else
	{
#ifdef _DEBUG
		/* In debug mode, print a message that an error has occurred. */
		printf_s("\nERROR: Invalid game state: %d\n", nextState);
#endif
	}
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Determine if a game state change has been requested. */
static bool	GameState_IsChanging()
{
	return (gameState.current != gameState.next);
}
