/*
 * pause_menu.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Ulysse
 */
#pragma once
#ifndef PAUSE_MENU_H_
#define PAUSE_MENU_H_

#include "state.h"
#include "graphics.h"

#include "sprites.h"

extern State STATE_PAUSE_MENU;

int init_pause_menu();
int deinit_pause_menu();
int update_pause_menu();
int draw_pause_menu();

#endif /* PAUSE_MENU_H_ */
