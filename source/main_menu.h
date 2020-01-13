/*
 * main_menu.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#pragma once

/*!
 * @brief Takes control of both screen and posts on the upper screen an image
 * 		  composed of the name of the game(Tank) on a cool background with the
 * 		  credits("Created by Ulysse & Karim") wrote in the bottom.
 * 		  The touch screen will be composed of only one button (Play)
 * 		  When a button is clicked a sound(click sound) and visual(brighter
 * 		  color button) effect are lunched.
 * @return 0 for now, but in the future, this menu will lead to another menu
 *        where they will have to choose between playing aagainst the computer
 *        or other.
 */

#include "state.h"
#include "graphics.h"

#include "background.h"
#include "sprites.h"

extern State STATE_MAIN_MENU;

int init_main_menu();
int deinit_main_menu();
int update_main_menu();
int draw_main_menu();
