/*
 * pause_menu.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#include "pause_menu.h"
#include "button.h"
#include "input.h"
#include "state_manager.h"
#include "game.h"
#include "main_menu.h"
#include <stdlib.h>
#include <string.h>

#include "pause_menu_background.h"
#include "pause_menu_sub_background.h"

State STATE_PAUSE_MENU = {
	&init_pause_menu,
	&deinit_pause_menu,
	&update_pause_menu,
	&draw_pause_menu
};

Button buttonResume;
Button buttonQuit;

void resume() {
	state_manager_pop(&state_manager); // remove pause menu
}

void quit() {
	state_manager_pop(&state_manager);
	state_manager_pop(&state_manager); // pop twice for pause menu + game state
	state_manager_push(&state_manager, &STATE_MAIN_MENU);
}

int init_pause_menu() {

	Illustration background = { pause_menu_backgroundPal, pause_menu_backgroundTiles, pause_menu_backgroundMap, pause_menu_backgroundPalLen, pause_menu_backgroundTilesLen, pause_menu_backgroundMapLen };
	Illustration subBackground = { pause_menu_sub_backgroundPal, pause_menu_sub_backgroundTiles, pause_menu_sub_backgroundMap, pause_menu_sub_backgroundPalLen, pause_menu_sub_backgroundTilesLen, pause_menu_sub_backgroundMapLen };

	oamDisable(&oamMain);
	oamDisable(&oamSub);
	BGCTRL[1]= (BGCTRL[1]& 0xFFFC)|0;
	BGCTRL[0]= (BGCTRL[0]& 0xFFFC)|1;

	draw_background_main(background);
	draw_background_sub(subBackground);

	int w = 192;
	int h = 50;
	buttonResume.x = 256 / 2 - w / 2; buttonResume.y = 32;
	buttonResume.width = w; buttonResume.height = h;
	buttonResume.onPress = &resume;

	buttonQuit.x = 256 / 2 - w / 2; buttonQuit.y = 112;
	buttonQuit.width = w; buttonQuit.height = h;
	buttonQuit.onPress = &quit;

	return 0;
}
int deinit_pause_menu() {
	BGCTRL[0]= (BGCTRL[0]& 0xFFFC)|1;
	BGCTRL[1]= (BGCTRL[1]& 0xFFFC)|0;

	oamEnable(&oamMain);
	oamEnable(&oamSub);
	return 0;
}
int update_pause_menu() {

	button_touch(&buttonResume, touch.px, touch.py);
	button_touch(&buttonQuit, touch.px, touch.py);

	return 1; // block game
}
int draw_pause_menu() {
	return 1; // block game
}
