/*
 * main_menu.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#include "main_menu.h"
#include "button.h"
#include "input.h"
#include "state_manager.h"
#include "game.h"
#include <stdlib.h>
#include <string.h>

#include "main_menu_background.h"
#include "main_menu_sub_background.h"

State STATE_MAIN_MENU = {
	&init_main_menu,
	&deinit_main_menu,
	&update_main_menu,
	&draw_main_menu
};

Button button2P;
Button buttonCPU;

void play2P() {
	state_manager_pop(&state_manager);
	state_manager_push(&state_manager, &STATE_GAME);
	//TODO: use 2 players mode
}

void playCPU() {
	state_manager_pop(&state_manager);
	state_manager_push(&state_manager, &STATE_GAME);
	//TODO: use AI mode
}

int init_main_menu() {

	Illustration background = { main_menu_backgroundPal, main_menu_backgroundTiles, main_menu_backgroundMap, main_menu_backgroundPalLen, main_menu_backgroundTilesLen, main_menu_backgroundMapLen };
	Illustration subBackground = { main_menu_sub_backgroundPal, main_menu_sub_backgroundTiles, main_menu_sub_backgroundMap, main_menu_sub_backgroundPalLen, main_menu_sub_backgroundTilesLen, main_menu_sub_backgroundMapLen };

	configure_background_main();
	configure_background_sub();
	draw_background_main(background);
	draw_background_sub(subBackground);

	int w = 140;
	int h = 50;
	button2P.x = 256 / 2 - w / 2; button2P.y = 32;
	button2P.width = w; button2P.height = h;
	button2P.onPress = &play2P;

	buttonCPU.x = 256 / 2 - w / 2; buttonCPU.y = 112;
	buttonCPU.width = w; buttonCPU.height = h;
	buttonCPU.onPress = &playCPU;

	return 0;
}
int deinit_main_menu() {
	return 0;
}
int update_main_menu() {

	button_touch(&button2P, touch.px, touch.py);
	button_touch(&buttonCPU, touch.px, touch.py);

	return 0;
}
int draw_main_menu() {
	return 0;
}