/******************************************************************************/
/*!
\file   GameStateManager.h
\author Doug Schilling
\par    Course: GAM100
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#pragma once

#include "GameStateTable.h"
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

/*------------------------------------------------------------------------------
// Public Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/* Initialize the game state manager. */
extern void GameStateManager_Init();

/* Update the game state manager. */
extern void GameStateManager_Update(float dt);

/* Shutdown the game state manager. */
extern void GameStateManager_Exit();

/* Determine if the game is still running. */
extern bool GameStateManager_IsRunning();

/* Set the next game state to run. */
extern void GameStateManager_SetNextState(GAMESTATE nextState);

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif

