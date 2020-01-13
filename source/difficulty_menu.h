/*
 * difficulty_menu.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Ulysse
 */
#pragma once
#ifndef DIFFICULTY_MENU_H_
#define DIFFICULTY_MENU_H_


#include "state.h"
#include "graphics.h"

#include "sprites.h"

extern State STATE_DIFFICULTY_MENU;

int init_difficulty_menu();
int deinit_difficulty_menu();
int update_difficulty_menu();
int draw_difficulty_menu();

#endif /* DIFFICULTY_MENU_H_ */
