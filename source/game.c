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

Terrain terrain;
Tank tank_green, tank_red;
int angle=50;

int init_game() {
	configure_background_main();
	configure_sprites_main();
	configure_sound();

	terrain_init(&terrain,FLAT_TERRAIN);

	tank_init(&tank_green,LEFT_TANK, 10, terrain);
	tank_init(&tank_red,RIGHT_TANK, 200, terrain);

	return 0;
}

int deinit_game() {

	// TODO:

	return 0;
}

int update_game() {

	if(keys==KEY_A)
		tank_shoot(tank_green,tank_red,angle, terrain);
	if(keys==KEY_Y)
		tank_shoot(tank_red,tank_green,angle, terrain);
	if(keys==KEY_UP){
		angle+=5;
		if(angle>70){
			angle =70;
		}
	}
	if(keys==KEY_DOWN){
		angle -=5;
		if(angle <30){
			angle =30;
		}
	}
	return 0;
}

int draw_game() {
	terrain_draw(terrain);
	draw_tank(tank_green);
	draw_tank(tank_red);
	draw_sprite_main();
	return 0;
}
