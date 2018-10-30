/******************************************************************************/
/*!
\file   GameStateDigiPenLogo.c
\author Doug Schilling
\par    Course: GAM100
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#include "stdafx.h"
#include "GameStateDigiPenLogo.h"
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

static const char * DigiPenLogo[] =
{
	"                                _______                  ________              ",
	"             /### /#######     |       \\                |        \\             ",
	"             /### /#########   |        \\  _          _ |   ___   |            ",
	"             /### /##########  |    |    ||_|        |_||         |            ",
	"             /### /########### |    |    | _   ____   _ |    ____/____   _____ ",
	"             /### /########### |    |    || | /    \\ | ||   |    /    \\ |     \\",
	"             /### /##########  |    |    || ||  __  || ||   |   |  --  ||     |",
	"             /### /#########   |        / | ||      || ||   |   |  ____||  |  |",
	"             /### /#######/    |_______/  |_| \\___  ||_||___|    \\____\\ |__|__|",
	"    /####### /### ///////                     /     |                          ",
	"  /######### /###                             \\____/                           ",
	" /########## /###                                                              ",
	"/########### /###                                                              ",
	"/########### /###      _____ ___   ___ __  _  __ ___ __ __       _     _  _    ",
	"//########## /### ||\\||_  | | | | | | |__ | ||__  | |__|  |_||\\|| ||  | || _|_|",
	" //######### /### || |__| | | | |_| | |__ |_||    | |__|__| || ||_||__|_||_| | ",
	"  ///####### /###                                                              ",
	"    ///////  ///                                                               ",
};

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void GameStateDigiPenLogo_Init()
{
	/* TODO BASIC: Print the DigiPen Logo to the screen. */

	/* First, determine the number of lines in the logo.  Hint "_countof(DigiPenLogo)" */
	int count = _countof(DigiPenLogo);

	/* Second, print each line in the DigiPenLogo[] array. */
	for (int i = 0; i < count; ++i)
	{
		printf(DigiPenLogo[i]);
		printf("\n");
	}

	/* Third, print a couple extra blank lines. */
	printf("\n\n\n\n\n");
}

void GameStateDigiPenLogo_Update(float dt)
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

void GameStateDigiPenLogo_Exit()
{
	WindowsHelper_ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

