/******************************************************************************
filename    Graphics.h
author      Cheng Ding Xiang
DP email    cheng.dingxiang@digipen.edu
course      GAM100 *Do not use as is in your game project*

Brief Description:
This file declares the graphics portion of the game engine.

Exposes the functions available for other places in code to use

******************************************************************************/

#ifndef GRAPHICS_H
#define GRAPHICS_H
void Graphics_Init();
void Graphics_Render(int characterX, int characterY, char characterIcon);
#endif // !GRAPHICS_H

