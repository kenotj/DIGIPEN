/******************************************************************************/
/*!
\file   BulletManager.h
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
*/
/******************************************************************************/

#pragma once
#include "Enum.h"
/*These bullet properties are hardcoded here, but can actually vary per user firing bullets.
Player and enemies should have their own versions of these numbers. In this case, all tailored for Player*/
#define MAX_BULLETS 5
#define BULLET_LIFETIME 5.0f
#define BULLET_SPEED 10.0f
#define RATE_OF_FIRE 0.5f

void BulletManager_Init();
void BulletManager_Update(float dt);
void BulletManager_Exit();
void BulletManager_SpawnBullet(float startingX, float startingY, Facing facing);
void BulletManager_KillBullet(int index);