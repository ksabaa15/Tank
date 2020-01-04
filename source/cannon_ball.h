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
#define degrees(a) (a*M_PI/180.0)
#define radians(a) (a*180.0/M_PI)

/*!
 * @brief shots a cannon ball from a given tank with a given force and angle
 *        stops the game control until the end of the animation
 * @param shooter_tank, is the tank that shot the cannon ball
 * @param target_tank, is the oponent's tank
 * @param angle of the shot [0-90]
 * @param force, of the shot [0-100]
 * @param tank_got_hit, call back function when the target tank get's hit
 * @param terrain, in order to be aware if the cannon ball hit the ground
 */
void cannon_shoot(int x_from, int y_from, int angle, Terrain terrain);


#endif /* CANNON_BALL_H_ */
