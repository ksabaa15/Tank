/*
 * terrain.c
 *
 *  Created on: Jan 4, 2020
 *      Author: Karim
 */
#include "terrain.h"
#define wall_height 50
#define ground_height 140

Illustration desert_terrain_background = {(void*)backgroundPal, (void*)backgroundTiles,(void*)backgroundMap, backgroundPalLen, backgroundTilesLen, backgroundMapLen };
int desert_terrain_func (int x){
	if(x>235&& x<275){
		return wall_height;
	}
	return ground_height;
}

void terrain_init(Terrain* terrain,Terrain_name name){
	if(name == DESERT){
		terrain->background= desert_terrain_background;
		terrain->func= desert_terrain_func;
		terrain->max_x=240;
	}
}
void terrain_draw(Terrain terrain){
		// wall drawing
		BG_PALETTE[255]=ARGB16(1,18,18,18);
		memset(&BG_TILE_RAM(1)[32],255,64);
		int i,j;
		for(i=0; i<24; ++i){
			for(j=0; j<32;++j){
				int y = i*8;
				if(y>terrain.func(j*8)&&terrain.func(j*8)==wall_height&& y<=(ground_height-10))
					BG_MAP_RAM(0)[i*32 +j]=1;
			}
		}
		for(i=0; i<24; ++i){
			for(j=0; j<32;++j){
				int y = i*8;
					if(y>terrain.func((j+32)*8)&&terrain.func((j+32)*8)==wall_height&&y<=(ground_height-10))
						BG_MAP_RAM(1)[i*32 +j]=1;
			}
		}

	draw_background_main(terrain.background);
}
