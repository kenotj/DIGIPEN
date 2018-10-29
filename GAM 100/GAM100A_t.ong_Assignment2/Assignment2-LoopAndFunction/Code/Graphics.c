/******************************************************************************
filename    Graphics.c
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file defines the graphics portion of the game engine

******************************************************************************/
#include "Helper\WindowsHelper.h"
#include <stdio.h>
/*Initialize the graphics part of the engine*/
void Graphics_Init()
{
	WindowsHelper_Init();
	WindowsHelper_FullScreen();
}

/*Draws the character on screen and sets the cursor to input position*/
void Graphics_Render(int characterX, int characterY, char characterIcon, int character2X, int character2Y, char characterIcon2)
{
	WindowsHelper_ClearScreen();
	WindowsHelper_SetCursorPosition(characterX, characterY);
	printf("%c", characterIcon);

	WindowsHelper_SetCursorPosition(character2X, character2Y);
	printf("%c", characterIcon2);

	WindowsHelper_SetCursorPosition(WindowsHelper_GetConsoleWidth() / 3, WindowsHelper_GetConsoleHeight() / 3);
	printf("How to control Characters: Character Direction How_many_steps   eg  ( 2 right 10 )");

	WindowsHelper_SetCursorPosition(WindowsHelper_GetConsoleWidth() / 2, WindowsHelper_GetConsoleHeight() / 2);

}

