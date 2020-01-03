/*
 * graphics.h
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#pragma once

#include <nds.h>
typedef struct{
	void * palette;
	void* tiles;
	void* map;
	int palette_length;
	int tiles_length;
	int map_length;
}Illustration;

/*!
 * @brief Sets the upper screen with a given background,
 * 		   it uses the VRAM_A and the Background 0 in Mode 0,
 * 		   (Tile mode). It saves the map in BG_MAP_RAM_SUB(0) and
 * 			the tiles in BG_TILE_RAM_SUB(1)
 * @param b the background to set
 */
void set_background_main_screen(Illustration background);

/*!
 * @brief Sets the upper screen with a given background,
 * 		   it uses the VRAM_C and the Background 0 in Mode 0,
 * 		   (Tile mode). It saves the map in BG_MAP_RAM(0) and
 * 			the tiles in BG_TILE_RAM(1)
 * @param b the background to set
 */
void set_background_sub_screen(Illustration background);

/*
 *@brief Initializes the 2D sprite engine and enables the Vram B
 *
 */
void configure_sprites_main();

// global variable to keep track of the last sprite id number
static int sprite_id=0;
/*
 *@brief Allocates graphics memory for the supplied sprite attributes,
 *		 copy the sprite tiles and palette ( WARNING: a unique palette,
 *		 must be used between all the sprites( 2 ways to do this:
 *		 1- putting all the sprites in a single png file before generating
 *		 the corresponding pallette.  or
 *		 2- Setting an upper limit of the size of each palette when generating
 *		 them, to a sum of maximum total of 256.)
 *
 *@param The size of the Sprite 32*32 or 8*8 etc..
 *@param The sprite to be allocated
 *@param id to be assigned the id number of the allocated sprite
 *
 *@return *gfx, the address in vram of the allocated sprite (*gfx)
 */
void* allocate_sprite_main(SpriteSize s, Illustration sprite, int *id);

/*
 *
 */
void set_sprite_main(const void* gfx, int id,int x, int y, bool horizontal_flip);
