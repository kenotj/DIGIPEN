/******************************************************************************/
/*!
\file   GameStateTable.h
\author Doug Schilling
\par    Course: GAM100
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#include <stdbool.h>
#pragma once
#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

/*------------------------------------------------------------------------------
// Public Consts:
//----------------------------------------------------------------------------*/

typedef enum
{
	/* Special Game States */
	GsQuit = -3,
	GsRestart = -2,
	GsInvalid = -1,

	/* Normal Game States: */
	GsDigiPenLogo,
	GsMainMenu,
	GsDemo,
	GsGameOver,

	/* Bookkeeping States: */
	GsMax,
	GsLimit = GsMax - 1,

	/* Specify the initial game state */
	GsInitial = GsDigiPenLogo,

} GAMESTATE;

/*------------------------------------------------------------------------------
// Public Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/* Determine if the game state is valid. */
extern bool GameState_IsValid(GAMESTATE gameState);

/* Determine if the game state is a "special" game state. */
extern bool GameState_IsSpecial(GAMESTATE gameState);

/* Execute the Init function for the current game state. */
extern void GameState_ExecuteInit(GAMESTATE gameState);

/* Execute the Update function for the current game state. */
extern void GameState_ExecuteUpdate(GAMESTATE gameState, float dt);

/* Execute the Exit function for the current game state. */
extern void GameState_ExecuteExit(GAMESTATE gameState);

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif

