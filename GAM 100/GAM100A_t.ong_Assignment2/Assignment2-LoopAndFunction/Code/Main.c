/******************************************************************************
filename    Main.c
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
Entry point to the entire application

******************************************************************************/

#include "Graphics.h"
#include "Game.h"
#include "InputProvider.h"

int main()
{
	Graphics_Init();
	InputProvider_Init();
	Game_Init();

	/*Check if the game is running*/
	while (Game_IsRunning())
	{
		Graphics_Render(Game_GetPlayerXPosition(), Game_GetPlayerYPosition(), Game_GetPlayerCharacter(), Game_GetPlayerXPosition2(), Game_GetPlayerYPosition2(), Game_GetPlayerCharacter2());
		InputProvider_Update();
		Game_Update();
	}

	//Pause before exiting application
	getchar();
	return 0;
}
