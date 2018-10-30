/******************************************************************************/
/*!
\file   MovingObject.h
\author Cheng Ding Xiang
\par    Course: GAM100
\par    Copyright © 2018 DigiPen (Singapore) Corporation.
\brief
Basic moving object. Has a type, position and velocity
*/
/******************************************************************************/

#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
/*List of moving object types*/
typedef enum ObjectType
{
	None,
	Taken,
	Player,
	Enemy,
	Bullet
}ObjectType;

typedef struct MovingObject
{
	/*Type of moving object.
	Used later to decide how to draw object
	*/
	ObjectType type;

	/*Accumulated position of object. Will be rounded off to put on screen*/
	float positionX;
	float positionY;

	/*Velocity of moving object, will be multiplied with delta time and added to position each frame*/
	float velocityX;
	float velocityY;
} MovingObject;
#endif // !MOVINGOBJECT_H
