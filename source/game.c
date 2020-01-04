/*
 * game.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#include "game.h"

State STATE_GAME = {
	&init_game,
	&deinit_game,
	&update_game,
	&draw_game
};

int init_game() {

	Terrain terrain;
	terrain_init(&terrain,FLAT_TERRAIN);
	terrain_draw(terrain);

	configure_sprites_main();
	Tank tank_green, tank_red;
	tank_init(&tank_green,LEFT_TANK, 10, terrain);
	tank_init(&tank_red,RIGHT_TANK, 200, terrain);
	draw_tank(tank_green);
	draw_tank(tank_red);

	configure_sound();

	while(1){
		swiWaitForVBlank();
		scanKeys();
		int keys = keysHeld();
		if(keys==KEY_A){
			tank_shoot(tank_green,60, terrain);
			break;
		}
	}

	return 0;
}

int deinit_game() {

	// TODO:

	return 0;
}

int update_game() {

	// TODO:

	return 0;
}

int draw_game() {

	// TODO:

	return 0;
}
