/******************************************************************************
filename    main.c
author      Matthew Picioccio, Doug Schilling
DP email    mattpic@digipen.edu, dschilling@digipen.edu
course      GAM100

Brief Description:
This file implements the main function and loop.

******************************************************************************/
#include "stdafx.h" /* NULL, bool */
#include "Windows.h"


/* The main program loop */
int main()
{
	SetConsoleTitle(TEXT("Hello World"));

	printf("Ni hao ma\n\n");
	printf("Hello World");

	getchar();

	/* cleanly exit */
    return 0;

}