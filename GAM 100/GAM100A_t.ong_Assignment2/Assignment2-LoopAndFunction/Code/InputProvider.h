/******************************************************************************
filename    InputProvider.h
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file declares the input portion of the game engine

******************************************************************************/

#ifndef INPUTPROVIDER_H
#define INPUTPROVIDER_H

#define MAX_INPUT_LENGTH 1000
void InputProvider_Init();
void InputProvider_Update();
char* InputProvider_GetRawInput();
#endif // !INPUTPROVIDER_H
