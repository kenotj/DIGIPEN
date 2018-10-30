/******************************************************************************/
/*!
\file   MovingObjectManager.h
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Backbone of all moving objects in Demo. Holds an array of moving objects to be
allocated and given out to other systems that require it. This manager is also
in charge of updating the moving objects' position with its velocity and time pass
*/
/******************************************************************************/
#ifndef MOVINGOBJECTMANAGER_H
#define MOVINGOBJECTMANAGER_H

#include "MovingObject.h"
#define MAX_MOVING_OBJECTS 240

void MovingObjectManager_Init();
int MovingObjectManager_GetMovingObjectIndex();
void MovingObjectManager_ReturnMovingObjectIndex(int index);
MovingObject * MovingObjectManager_GetMovingObjects();
int MovingObjectManager_GetNumberInUse();
void MovingObjectManager_Update(float dt);
void MovingObjectManager_SetObjectVelocity(int index, float x, float y);
void MovingObjectManager_SetObjectPosition(int index, float x, float y);
void MovingObjectManager_SetObjectType(int index, ObjectType type);
float MovingObjectManager_GetObjectPositionX(int index);
float MovingObjectManager_GetObjectPositionY(int index);
#endif // !MOVINGOBJECTMANAGER_H