/*
 * main.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */

#include <nds.h>
#include <stdio.h>
#include "game.h"
#include "state_manager.h"

int main(void) {

	// initialize state manager
	StateManager state_manager;
	state_manager_init(&state_manager);

	// push game state
	state_manager_push(&state_manager, &STATE_GAME);

	while (1) {
		// game loop
		polling();
		state_manager_update(&state_manager);
		state_manager_draw(&state_manager);
		swiWaitForVBlank();
	}
}
