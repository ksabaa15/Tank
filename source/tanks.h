/*
 * tanks.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Karim
 */
#pragma once
#ifndef TANKS_H_
#define TANKS_H_

#include "terrain.h"
#include "sprites.h"
#include "graphics.h"
#define HEALTH_START_VALUE 5

// defines which tank, the game will support only two tanks (1 vs 1)
typedef enum {LEFT_TANK, RIGHT_TANK} Tank_id;




// Abstraction representing a Tank, encapsulating all the needed data
typedef struct{
	Tank_id id; //{0,1}  0 is the left tank
	int x;
	int y;
	int health; // initialized to HEALTH_START_VALUE
	Illustration illustration; // sprite
	Terrain terrain;  // the background
	u16* gfx_tank;  // pointer to the allocated sprite
	int sprite_id;  // 0 or 1
 }Tank;

/*!
 * @brief initializes the given tank on the position (x,y)
 *        looking right or left
 *        Fails if - the given tank pointer is null
 *                 - the x coordinates is out of the terrain [0-255]
 *
 * @param Tank to be initialized
 * @param id of the tank
 * @param x, horizontal position of the tank
 * @param terrain where the tank is going to displayed
 * @return 0 on success
 */
int tank_init(Tank*,Tank_id, int x, Terrain);

/*!
 * @brief moves the tank number(id) to the new location
 * fails if - the tank pointer is null
 * 			-x is out of the terrain [0-255]
 * @param tank to be moved
 * @param x position of the new location
 * @return 0 if success
 */
int tank_move(Tank* tank, int x);

/*!
 *@brief shoots a cannon ball from the tank number (id),
 *       with the given power and angle
 * @param tank that is going to shoot
 * @param power of the shot [0-100]
 * @param angle of shot, relative to which direction the tank is looking
 */
void tank_shoot(Tank tank, int power, int angle);

/*!
 *@brief when the tank gets hit, it looses health
 *       and makes an explosion animation.
 * @param tank that is going to get hit
 */
void tank_got_hit(Tank tank);

/*!
 * @brief draws the tank
 * @param tank to be drawn
 */
void draw_tank(Tank tank);

#endif /* TANKS_H_ */
