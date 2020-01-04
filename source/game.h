/*
 * game.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "state.h"
#include "game.h"
#include "background.h"
#include "terrain.h"
#include "tanks.h"

extern State STATE_GAME;

int update_game();
int draw_game();
int init_game();
int deinit_game();

#endif /* GAME_H_ */

