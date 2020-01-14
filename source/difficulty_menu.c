/*
 * difficulty_menu.c
 *
 *  Created on: Jan 13, 2020
 *      Author: Ulysse
 */
#include "difficulty_menu.h"
#include "button.h"
#include "input.h"
#include "state_manager.h"
#include "game.h"
#include <stdlib.h>
#include <string.h>

#include "difficulty_menu_background.h"
#include "difficulty_menu_sub_background.h"

State STATE_DIFFICULTY_MENU = {
	&init_difficulty_menu,
	&deinit_difficulty_menu,
	&update_difficulty_menu,
	&draw_difficulty_menu
};

Button buttonEasy;
Button buttonMedium;
Button buttonHard;

void easy() {
	state_manager_pop(&state_manager);
	state_manager_push(&state_manager, &STATE_GAME);
	ai_mode = true;
	difficulty=2;
}

void medium() {
	state_manager_pop(&state_manager);
	state_manager_push(&state_manager, &STATE_GAME);
	ai_mode = true;
	difficulty=1;
}

void hard() {
	state_manager_pop(&state_manager);
	state_manager_push(&state_manager, &STATE_GAME);
	ai_mode = true;
	difficulty=0;
}

int init_difficulty_menu() {

	Illustration background = { difficulty_menu_backgroundPal, difficulty_menu_backgroundTiles, difficulty_menu_backgroundMap, difficulty_menu_backgroundPalLen, difficulty_menu_backgroundTilesLen, difficulty_menu_backgroundMapLen };
	Illustration subBackground = { difficulty_menu_sub_backgroundPal, difficulty_menu_sub_backgroundTiles, difficulty_menu_sub_backgroundMap, difficulty_menu_sub_backgroundPalLen, difficulty_menu_sub_backgroundTilesLen, difficulty_menu_sub_backgroundMapLen };

	configure_background_main();
	configure_background_sub();
	draw_background_main(background);
	draw_background_sub(subBackground);

	int w = 140;
	int h = 36;
	buttonEasy.x = 256 / 2 - w / 2; buttonEasy.y = 32;
	buttonEasy.width = w; buttonEasy.height = h;
	buttonEasy.onPress = &easy;

	buttonMedium.x = 256 / 2 - w / 2; buttonMedium.y = 80;
	buttonMedium.width = w; buttonMedium.height = h;
	buttonMedium.onPress = &medium;

	buttonHard.x = 256 / 2 - w / 2; buttonHard.y = 128;
	buttonHard.width = w; buttonHard.height = h;
	buttonHard.onPress = &hard;

	return 0;
}
int deinit_difficulty_menu() {
	return 0;
}
int update_difficulty_menu() {

	button_touch(&buttonEasy, touch.px, touch.py);
	button_touch(&buttonMedium, touch.px, touch.py);
	button_touch(&buttonHard, touch.px, touch.py);

	return 0;
}
int draw_difficulty_menu() {
	return 0;
}
