/*
 * game.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "input.h"
#include "state.h"
#include "game.h"
#include "terrain.h"
#include "tanks.h"
#include "sound.h"
#include <nds.h>
extern State STATE_GAME;

int init_game();
int deinit_game();
int update_game();
int draw_game();

#endif /* GAME_H_ */

