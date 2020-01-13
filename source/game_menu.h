/*
 * game_menu.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#pragma once
#ifndef GAME_MENU_H_
#define GAME_MENU_H_

/*!
 * @brief Takes control of the touch screen and posts the game menu
 * 		  which is composed of three buttons ( Resume, Restart, Exit).
 * 		  When a button is clicked a sound(click sound) and visual(brighter
 * 		  color button) effect are lunched.
 * @return 0 or 1 or 2 respectively according to which button was clicked
 * 		  (resume, restart, exit)
 */
int game_menu();

#endif /* GAME_MENU_H_ */


