/*
 * main.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */

#include <stdio.h>

#include "input.h"
#include "state_manager.h"

#include "game.h"
#include "main_menu.h"

int main(void) {

	// initialize state manager
	state_manager_init(&state_manager);

	// push game state
	state_manager_push(&state_manager, &STATE_MAIN_MENU);

	while (1) {
		// game loop
		poll_input();
		state_manager_update(&state_manager);
		state_manager_draw(&state_manager);
		swiWaitForVBlank();
	}
}
