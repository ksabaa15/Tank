/*
 * game.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#include "game.h"
#include <stdlib.h>

State STATE_GAME = {
	&init_game,
	&deinit_game,
	&update_game,
	&draw_game
};

Terrain terrain;
Tank tank_green, tank_red;
bool turn_player;
Illustration sub_background = { (void*)sub_backgroundPal, (void*)sub_backgroundTiles, (void*)sub_backgroundMap,
		sub_backgroundPalLen, sub_backgroundTilesLen, sub_backgroundMapLen};
int h =1;
int init_game() {
	configure_background_main();
	configure_background_sub();
	configure_sprites_main();
	configure_sprites_sub();
	configure_sound();
	terrain_init(&terrain,DESERT);
	init_bg_view();
	tank_init(&tank_green,LEFT_TANK, 170, terrain);
	tank_init(&tank_red,RIGHT_TANK, 150, terrain);
	turn_player=true;
	init_score();
	return 0;
}

int deinit_game() {

	// TODO:

	return 0;
}

int update_game() {

	if(turn_player){
		if(keys==KEY_A){
			tank_shoot(tank_green,&tank_red, terrain);
			turn_player=false;
		}
		if(keys==KEY_UP){
			tank_green.angle+=5;
			if(tank_green.angle>70){
				tank_green.angle =70;
			}
		}
		if(keys==KEY_DOWN){
			tank_green.angle -=5;
			if(tank_green.angle <40){
				tank_green.angle =40;
			}
		}
		if(keys==KEY_RIGHT){
			tank_move(&tank_green, true);
		}
		if(keys==KEY_LEFT){
			tank_move(&tank_green, false);
		}
	}else{
		int i;
		int forward = rand()%2;
		for(i=0; i<20;++i){
			swiWaitForVBlank();
			swiWaitForVBlank();
			tank_move(&tank_red, forward);
			draw_tank(tank_red);
			draw_sprite_main();
		}

		tank_red.angle =  angle_to_hit_green(tank_green.x,tank_red.x);
		tank_shoot(tank_red,&tank_green, terrain);
		turn_player = true;
	}
	update_score();

	return 0;
}

int draw_game() {
	terrain_draw(terrain);
	draw_tank(tank_green);
	draw_tank(tank_red);
	draw_sprite_main();
	draw_background_sub(sub_background);
	draw_sprite_sub();
	return 0;
}
