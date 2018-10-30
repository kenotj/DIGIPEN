#include "stdafx.h"
#include <time.h>
#include "GameStateManager.h"

int main()
{
	clock_t ticksThen, ticksNow;
	float difference;
	ticksThen = clock();
	/* ------------------------------------------------------------------------ */
	/* Initilization and Setup */
	/* ------------------------------------------------------------------------ */

	/* Initialize the game state manager. */
	GameStateManager_Init();

	/* ------------------------------------------------------------------------ */
	/* GAME LOOP */
	/* ------------------------------------------------------------------------ */

	/* Loop until the game is no longer running. */
	while (GameStateManager_IsRunning())
	{
		ticksNow = clock();
		difference = (ticksNow - ticksThen) / (float)CLOCKS_PER_SEC;

		if (difference >= 0.016f)
		{
			/* Update the game state manager. */
			ticksThen = ticksNow;
			GameStateManager_Update(difference);
		}
	}

	/* ------------------------------------------------------------------------ */
	/* Cleanup and Exit */
	/* ------------------------------------------------------------------------ */

	/* Exit the game state manager. */
	GameStateManager_Exit();

	getchar();
	/* cleanly exit */
	return 0;
}