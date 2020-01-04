/*
 * terrain.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Karim
 */
#pragma once
#ifndef TERRAIN_H_
#define TERRAIN_H_

#include "graphics.h"
#include "background.h"

// different terrain, we support only the flat one for now
typedef enum { FLAT_TERRAIN } Terrain_name;

/* abstraction encapsulating all the needed information about a background, the illustration (palette, tiles etc..),
*  and a function describing the behavior of the ground ( to be used for the movement of the tanks)
*/
typedef struct{
	Illustration background;
	int (*func)(int x);
}Terrain;


/*!
 * @brief initializes the given terrain pointer, with the specified terrain name configuration
 *        Fails if terrain pointer is null
 * @param terrain pointer to be initialized
 * @param name of the wanted terrain
 */
void terrain_init(Terrain* terrain,Terrain_name name);

/*!
 * @brief draws the terrain
 * @param the terrain to be drawn
 */
void terrain_draw(Terrain terrain);

#endif /* TERRAIN_H_ */
