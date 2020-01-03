/*
 * game.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#pragma once

#include <nds.h>
#include "state.h"
#include "background.h"
#include "graphics.h"
#include "sprites.h"

extern State STATE_GAME;

int update_game();
int draw_game();
int init_game();
int deinit_game();

