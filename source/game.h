/*
 * game.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#pragma once

#include "state.h"
#include "graphics.h"

#include "background.h"
#include "sprites.h"

extern State STATE_GAME;

int init_game();
int deinit_game();
int update_game();
int draw_game();

