/******************************************************************************
filename    Game.c
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file defines the game logic portion

******************************************************************************/

#ifndef  GAME_H
#define GAME_H
#include <stdbool.h> 
void Game_Init();
bool Game_Update();
bool Game_IsRunning();
int Game_GetPlayerXPosition();
char Game_GetPlayerCharacter();
int Game_GetPlayerYPosition();
int Game_GetPlayerXPosition2();
char Game_GetPlayerCharacter2();
int Game_GetPlayerYPosition2();
#define MAX_COMMAND_VERB_LENGTH 256
#define MAX_COMMAND_NOUN_LENGTH 256
#endif // ! GAME_H


