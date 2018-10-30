/******************************************************************************/
/*!
\file   PlayerManager.h
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
This manager is in charge of processing player controls and actions
*/
/******************************************************************************/

#pragma once

void PlayerManager_Init();
void PlayerManager_Update(float dt);
void PlayerManager_Exit();
char PlayerManager_GetPlayerDisplay();

