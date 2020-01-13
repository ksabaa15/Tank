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
#include "view.h"
#include "sub_background.h"
#include "graphics.h"
#include "numbers.h"
#include "score.h"
#include "cannon_ball.h"

extern State STATE_GAME;
extern Terrain terrain;
extern Tank tank_green, tank_red;
extern bool turn_player;
extern bool ai_mode;

int init_game();
int deinit_game();
int update_game();
int draw_game();

#endif /* GAME_H_ */

