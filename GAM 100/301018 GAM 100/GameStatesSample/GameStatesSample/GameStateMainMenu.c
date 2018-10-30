/******************************************************************************/
/*!
	\file   GameStateMainMenu.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "GameStateMainMenu.h"
#include "GameStateManager.h"
#include "WindowsHelper.h"
#include "stdafx.h"
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

void GameStateMainMenu_Init()
{
	/* TODO BASIC: Display the name of your text adventure as simple text or ASCII graphics. */

	/* TODO REQUIRED: Display the following main menu options: */
	/*   Select an option: */
	/*     (P)lay */
	/*     (Q)uit */

	printf("Select an option: \n     (P)lay \n     (Q)uit \n");

	/* TODO ADVANCED: Implement one or more functions, such as PrintIndent() or PrintCentered(),
		 that procedurally determine where to display strings of text on the screen.
		 For example: PrintIndent(20, "(P)lay"); will display "(P)lay" starting at the 20th column.
		 Use these functions to display the menu text in a nicely presented fashion. */
}

void GameStateMainMenu_Update(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* TODO BASIC: Print the message "Enter command: " to the screen. */
	printf("Enter command: ");
	/* TODO: Read the user input. */
	/*int option = getchar();*/
	char in;
	scanf_s("%c", &in, 1);
	fseek(stdin, 0, SEEK_END);
	/* TODO REQUIRED: Check for 'p' or 'P' to be entered. */
	if (in == 'p' || in == 'P')
	{
		/* TODO REQUIRED: Tell the game state manager to switch to the GsTextAdventure state. */
		GameStateManager_SetNextState(GsDemo);
	}
	/* TODO REQUIRED: Check for 'q' or 'Q' to be entered. */
	else if (in == 'q' || in == 'Q')
	{
		/* TODO REQUIRED: Tell the game state manager to quit the game (GsQuit). */
		GameStateManager_SetNextState(GsQuit);
	}
	else
	{
		/* TODO ADVANCED: Display an error message if an invalid command is entered. */
		printf("invalid command\n");
	}
}

void GameStateMainMenu_Exit()
{
	WindowsHelper_ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

