/*
 * main_menu.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#include "main_menu.h"
#include "button.h"
#include "input.h"
#include <stdlib.h>
#include <string.h>

State STATE_MAIN_MENU = {
	&init_main_menu,
	&deinit_main_menu,
	&update_main_menu,
	&draw_main_menu
};

Button playButton;

{
	256 - ; int y;
    int width; int height;
    char* label;
    void (*onPress)();
}

int init_main_menu() {

	Illustration background = { backgroundPal, backgroundTiles,backgroundMap, backgroundPalLen, backgroundTilesLen, backgroundMapLen };

	set_background_main_screen(background);
	set_background_sub_screen(background);

	int w = 100;
	int h = 50;
	playButton.x = 256 / 2 - w / 2;
	playButton.y = 192 / 2 - h / 2;
	playButton.width = w;
	playButton.height = h;
	playButton.label = malloc(sizeof(char) * 32);
	strcpy(playButton.label, "PLAY");
	button_draw(&button);

	return 0;
}
int deinit_main_menu() {
	return 0;
}
int update_main_menu() {

	return 0;
}
int draw_main_menu() {
	return 0;
}