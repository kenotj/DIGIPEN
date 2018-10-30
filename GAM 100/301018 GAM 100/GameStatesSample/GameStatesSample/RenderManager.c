/******************************************************************************/
/*!
\file   RenderManager.c
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Renders all moving objects
*/
/******************************************************************************/
#include "RenderManager.h"
#include "MovingObjectManager.h"
#include "PlayerManager.h"
#include "WindowsHelper.h"
#include <math.h>
#include <stdio.h>

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
static int width, height; /*Screen width and height*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Initialize the render manager. */
void RenderManager_Init()
{
	WindowsHelper_FullScreen();
	height = WindowsHelper_GetConsoleHeight();
	width = WindowsHelper_GetConsoleWidth();
}

/* Main render function */
void RenderManager_Draw()
{
	/*Setting up data for drawing*/
	char playerCharacter = PlayerManager_GetPlayerDisplay();
	MovingObject * objects = MovingObjectManager_GetMovingObjects();
	int activeObjectCount = MovingObjectManager_GetNumberInUse();
	int processed = 0;

	/*Clearing the screen before drawing moving objects*/
	WindowsHelper_ClearScreen();

	for (int i = 0; i < MAX_MOVING_OBJECTS; ++i)
	{
		short x = (short)(objects[i].positionX);
		short y = (short)(objects[i].positionY);

		if (x < 0 || x > width || y < 0 || y > height)
		{
			continue;
		}

		if (objects[i].type == Player)
		{
			WindowsHelper_SetCursorPosition(x, y);
			printf_s("%c", playerCharacter);
			++processed;
		}
		else if (objects[i].type == Bullet)
		{
			WindowsHelper_SetCursorPosition(x, y);
			printf_s("%c", BULLET_CHAR);
			++processed;
		}

		/*Tracking the number of objects to draw*/
		if (processed >= activeObjectCount)
		{
			return;
		}
	}
}