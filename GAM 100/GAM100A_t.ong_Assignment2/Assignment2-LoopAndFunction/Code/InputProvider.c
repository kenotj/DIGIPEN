/******************************************************************************
filename    InputProvider.c
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file defines the input portion of the game engine

******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "InputProvider.h"

static char input[MAX_INPUT_LENGTH];

void InputProvider_Init() 
{
	memset(input, '\0', MAX_INPUT_LENGTH);
}

void InputProvider_Update()
{
	fgets(input, MAX_INPUT_LENGTH, stdin);
}

char* InputProvider_GetRawInput()
{
	return input;
}
