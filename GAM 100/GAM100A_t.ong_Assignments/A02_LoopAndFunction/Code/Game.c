/******************************************************************************
filename    Game.c
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file defines the game logic portion

******************************************************************************/

#include "InputProvider.h"
#include <string.h>
#include <stdlib.h>
#include "Game.h"

static bool running; /*tracks if the game is still running*/

/*Main character values*/
static char mainCharacter; /*value used to display the character*/
static int positionX, positionY;

/*SECOND character values*/
static char mainCharacter2; /*value used to display the 2nd character*/
static int position2X, position2Y;

/*Buffers to hold parsed input*/
char verb[MAX_COMMAND_VERB_LENGTH];
char noun[MAX_COMMAND_NOUN_LENGTH];
char character[MAX_COMMAND_VERB_LENGTH];

/*Forward declaration of functions within this file*/
void Game_ParseInput();
void Game_ProcessCommand();

/*Initialization function*/
void Game_Init()
{
	mainCharacter = 234;
	running = true;
	positionX = 0;
	positionY = 0;

	mainCharacter2 = 234;
	running = true;
	position2X = 0;
	position2Y = 0;
}

bool Game_Update()
{
	Game_ParseInput();
	Game_ProcessCommand();
	return running;
}

bool Game_IsRunning()
{
	return running;
}

int Game_GetPlayerXPosition()
{
	return positionX;
}

char Game_GetPlayerCharacter()
{
	return mainCharacter;
}

int Game_GetPlayerYPosition()
{
	return positionY;
}


/*2nd CHARACTER INPUT*/
int Game_GetPlayerXPosition2()
{
	return position2X;
}

char Game_GetPlayerCharacter2()
{
	return mainCharacter2;
}

int Game_GetPlayerYPosition2()
{
	return position2Y;
}


/*Where input is split into an intial verb and noun that follows after*/
void Game_ParseInput()
{
	char *nextToken = NULL;
	char *charToken, *verbToken, *nounToken;
	char * input = InputProvider_GetRawInput();


	/* tokenize the string to grab a verb, ignoring spaces, tabs, and newlines */
	charToken = strtok_s(input, " \t\n", &nextToken);

	/* tokenize the string to grab a verb, ignoring spaces, tabs, and newlines */
	verbToken = strtok_s(NULL, " \t\n", &nextToken);

	/* tokenize the remaining string to grab a noun, ignoring tabs, and newlines */
	nounToken = strtok_s(NULL, "\t\n", &nextToken);



	/* copy the verb into the CommandData structure, if any */
	if (charToken != NULL)
	{
		strcpy_s(character, MAX_COMMAND_VERB_LENGTH, charToken);
	}
	else
	{
		character[0] = '\0'; /* no verb was parsed - set the CommandData value to an empty string */
	}




	if (verbToken != NULL)
	{
		strcpy_s(verb, MAX_COMMAND_VERB_LENGTH, verbToken);
	}
	else
	{
		verb[0] = '\0'; /* no verb was parsed - set the CommandData value to an empty string */
	}

	/* copy the noun into the CommandData structure, if any */
	if (nounToken != NULL)
	{
		strcpy_s(noun, MAX_COMMAND_NOUN_LENGTH, nounToken);
	}
	else
	{
		noun[0] = '\0'; /* no noun was parsed - set the CommandData value to an empty string */
	}
}

/*uses the input to determine what game logic to execute*/
void Game_ProcessCommand()
{
	/* convert to lowercase to provide additional robustness with input */
	_strlwr_s(verb, MAX_COMMAND_VERB_LENGTH);

	if (strcmp(character, "quit") == 0)
	{
		/*Tells the game to stop running*/
		running = false;
	}

	if (strcmp(character, "1") == 0)
	{
		
		if (strcmp(verb, "left") == 0)
		{
			/*atoi converts a string to an integer as best it can*/
			positionX -= atoi(noun);
		}
		else if (strcmp(verb, "right") == 0)
		{
			positionX += atoi(noun);
		}
		else if (strcmp(verb, "up") == 0)
		{
			positionY -= atoi(noun);
		}
		else if (strcmp(verb, "down") == 0)
		{
			positionY += atoi(noun);
		}
	}
	else if (strcmp(character, "2") == 0)
	{

		if (strcmp(verb, "left") == 0)
		{
			/*atoi converts a string to an integer as best it can*/
			position2X -= atoi(noun);
		}
		else if (strcmp(verb, "right") == 0)
		{
			position2X += atoi(noun);
		}
		else if (strcmp(verb, "up") == 0)
		{
			position2Y -= atoi(noun);
		}
		else if (strcmp(verb, "down") == 0)
		{
			position2Y += atoi(noun);
		}
	}

}