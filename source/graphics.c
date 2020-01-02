/*
 * graphics.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#include "graphics.h"
#include <math.h>
#define degrees(a) (a*M_PI/180.0)
#define radians(a) (a*180.0/M_PI)


void set_background_main_screen(Illustration background){

	// configure Vram for main engine
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	// configure the display controller register
	REG_DISPCNT= MODE_0_2D | DISPLAY_BG0_ACTIVE;
	// configure the background controller
	BGCTRL[0]= BG_32x32 | BG_COLOR_256 |
			BG_MAP_BASE(0) | BG_TILE_BASE(1);
	// copying palette
	dmaCopy(background.palette,(void*)BG_PALETTE,background.palette_length);
	// copying tiles
	dmaCopy(background.tiles,(void*)BG_TILE_RAM(1),background.tiles_length);
	// copying map
	dmaCopy(background.map,(void*)BG_MAP_RAM(0),background.map_length);
}

void set_background_sub_screen(Illustration background){
	// configure Vram for main engine
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	// configure the display controller register
	REG_DISPCNT_SUB= MODE_0_2D | DISPLAY_BG0_ACTIVE;
	// configure the background controller
	BGCTRL_SUB[0]= BG_32x32 | BG_COLOR_256 |
			BG_MAP_BASE(0) | BG_TILE_BASE(1);
	// copying palette
	dmaCopy(background.palette,(void*)BG_PALETTE_SUB,background.palette_length);
	// copying tiles
	dmaCopy(background.tiles,(void*)BG_TILE_RAM_SUB(1),background.tiles_length);
	// copying map
	dmaCopy(background.map,(void*)BG_MAP_RAM_SUB(0),background.map_length);
}

void configure_sprites_main(){
	VRAM_B_CR = VRAM_ENABLE |VRAM_B_MAIN_SPRITE_0x06400000;
	oamInit(&oamMain, SpriteMapping_1D_32,false);
}
void* allocate_sprite_main(SpriteSize s, Illustration sprite, int *id){
	// allocate sprite
	u16* gfx= oamAllocateGfx(&oamMain, s, SpriteColorFormat_256Color);
	// copying palette
	dmaCopy(sprite.palette,(void*)SPRITE_PALETTE,sprite.palette_length);

	// copying tiles
	dmaCopy(sprite.tiles,(void*)gfx,sprite.tiles_length);

	*id= sprite_id++;

	return gfx;
}

void set_sprite_main(const void* gfx, int id,int x, int y, bool horizontal_flip){
	oamSet(&oamMain,
						id,
						x,y,
						0,
						0,
						SpriteSize_32x32,
						SpriteColorFormat_256Color,
						gfx,
						0,
						false,
						false,
						horizontal_flip, false,
						false
						);

			oamUpdate(&oamMain);
}
