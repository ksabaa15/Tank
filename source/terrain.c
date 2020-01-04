/*
 * terrain.c
 *
 *  Created on: Jan 4, 2020
 *      Author: Karim
 */
#include "terrain.h"

Illustration flat_terrain_background = {(void*)backgroundPal, (void*)backgroundTiles,(void*)backgroundMap, backgroundPalLen, backgroundTilesLen, backgroundMapLen };
int flat_terrain_func (int x){return 110;}

void terrain_init(Terrain* terrain,Terrain_name name){
	if(name == FLAT_TERRAIN){
		terrain->background= flat_terrain_background;
		terrain->func= flat_terrain_func;
	}
}
void terrain_draw(Terrain terrain){
	set_background_main_screen(terrain.background);
}
