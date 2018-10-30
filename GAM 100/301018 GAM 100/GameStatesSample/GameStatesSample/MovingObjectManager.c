/******************************************************************************/
/*!
\file   MovingObjectManager.c
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Backbone of all moving objects in Demo. Holds an array of moving objects to be
allocated and given out to other systems that require it. This manager is also
in charge of updating the moving objects' position with its velocity and time pass
*/
/******************************************************************************/

#include "MovingObjectManager.h"
#include <string.h>

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
static MovingObject movingObjectBuffer[MAX_MOVING_OBJECTS]; /*Array of all moving objects usable in the game*/
static int numberInUse;

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Initialize the moving object manager. */
void MovingObjectManager_Init()
{
	/*Initialize all data to a safe state*/
	memset(movingObjectBuffer, 0, sizeof(MovingObject) * MAX_MOVING_OBJECTS);
}

/*----------------------------------------------------------------------------*/
/* Used to get an index to an unused moving object. 
Returns -1 if there are no objects available*/
int MovingObjectManager_GetMovingObjectIndex()
{
	for (int i = 0; i < MAX_MOVING_OBJECTS; ++i)
	{
		if (movingObjectBuffer[i].type == None)
		{
			movingObjectBuffer[i].type = Taken;
			++numberInUse;
			return i;
		}
	}
	/*No more available objects*/
	return -1;
}

/*----------------------------------------------------------------------------*/
/* Function to return taken resource of moving object*/
void MovingObjectManager_ReturnMovingObjectIndex(int index)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return;
	}
	--numberInUse;
	/*Setting moving object back to safe state*/
	memset(&movingObjectBuffer[index], 0, sizeof(MovingObject));
}

/*----------------------------------------------------------------------------*/
/* Mainly used by RenderManager to render all moving objects*/
MovingObject * MovingObjectManager_GetMovingObjects()
{
	return movingObjectBuffer;
}

/*----------------------------------------------------------------------------*/
/* Mainly used by RenderManager when rendering all moving objects*/
int MovingObjectManager_GetNumberInUse()
{
	return numberInUse;
}

/*----------------------------------------------------------------------------*/
/*Update function to update positions of moving objects by time and their velocities*/
void MovingObjectManager_Update(float dt)
{
	int processed = 0;
	for (int i = 0; i < MAX_MOVING_OBJECTS; ++i)
	{
		if (movingObjectBuffer[i].type != None &&
			movingObjectBuffer[i].type != Taken)
		{
			movingObjectBuffer[i].positionX += movingObjectBuffer[i].velocityX * dt;
			movingObjectBuffer[i].positionY += movingObjectBuffer[i].velocityY * dt;

			++processed;
			if (processed >= numberInUse)
			{
				return;
			}
		}
	}
}

/*----------------------------------------------------------------------------*/
/*Set velocity for moving object of that index*/
void MovingObjectManager_SetObjectVelocity(int index,float x, float y)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return;
	}

	movingObjectBuffer[index].velocityX = x;
	movingObjectBuffer[index].velocityY = y;
}

/*----------------------------------------------------------------------------*/
/*Set position for moving object of that index*/
void MovingObjectManager_SetObjectPosition(int index, float x, float y)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return;
	}

	movingObjectBuffer[index].positionX = x;
	movingObjectBuffer[index].positionY = y;
}

/*----------------------------------------------------------------------------*/
/*Set type for moving object of that index*/
void MovingObjectManager_SetObjectType(int index, ObjectType type)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return;
	}

	movingObjectBuffer[index].type = type;
}

/*----------------------------------------------------------------------------*/
/*Get x position of object of index*/
float MovingObjectManager_GetObjectPositionX(int index)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return -1;
	}
	return movingObjectBuffer[index].positionX;
}

/*----------------------------------------------------------------------------*/
/*Get y position of object of index*/
float MovingObjectManager_GetObjectPositionY(int index)
{
	if (index < 0 || index >= MAX_MOVING_OBJECTS)
	{
		return -1;
	}

	return movingObjectBuffer[index].positionY;
}