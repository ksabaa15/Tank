/*
 * cannon_ball.h
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */

#ifndef CANNON_BALL_H_
#define CANNON_BALL_H_
#pragma once
#include "terrain.h"
#include "graphics.h"
#include "sprites.h"
#include <math.h>
#include <nds.h>
#include "sound.h"
#include "tanks.h"
#include "state.h"
#include "state_manager.h"
#define radians(a) (a*M_PI/180.0)

/*!
 * @brief shots a cannon ball from a given tank with a given angle,
 *        stops the game control until the end of the animation,
 *        cannon ball shot from tank (with  sound) until hitting an
 *        object and turns into an explosion (with sound)
 * @param x_tank horizontal coordinate
 * @param y_tank vertical coordinate
 * @param angle of the shot [0-90]
 * @param terrain, in order to be aware if the cannon ball hit the ground
 */
 extern void cannon_shoot(Tank shooter, Tank target, void(*tank_got_hit)(Tank tank), int angle, Terrain terrain);

 int init_cannon();
 int deinit_cannon();
 int update_cannon();
 int draw_cannon();

#endif /* CANNON_BALL_H_ */
