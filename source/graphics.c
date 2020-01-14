/*
 * graphics.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#include "graphics.h"
void configure_background_main(){

	// configure Vram for main engine
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;
	// configure the display controller register
	REG_DISPCNT= MODE_0_2D | DISPLAY_BG0_ACTIVE | DISPLAY_BG1_ACTIVE;
	// configure the background controller
	BGCTRL[0]= BG_64x32 | BG_COLOR_256 |
			BG_MAP_BASE(0) | BG_TILE_BASE(1);
	BGCTRL[1]= BG_32x32 | BG_COLOR_256 |
				BG_MAP_BASE(2) | BG_TILE_BASE(2);



}
void draw_background_main(Illustration background){
	// copying palette
	dmaCopy(background.palette,(void*)BG_PALETTE,background.palette_length);
	// copying tiles
	dmaCopy(background.tiles,(void*)BG_TILE_RAM(2),background.tiles_length);
	// copying map
	dmaCopy(background.map,(void*)BG_MAP_RAM(2),background.map_length);

}

void configure_background_sub(){
	// configure Vram for main engine
	VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
	// configure the display controller register
	REG_DISPCNT_SUB= MODE_0_2D | DISPLAY_BG0_ACTIVE;
	// configure the background controller
	BGCTRL_SUB[0]= BG_32x32 | BG_COLOR_256 |
			BG_MAP_BASE(0) | BG_TILE_BASE(1);
}
void draw_background_sub(Illustration background){
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
void configure_sprites_sub(){
	VRAM_I_CR = VRAM_ENABLE | VRAM_I_SUB_SPRITE;
	oamInit(&oamSub, SpriteMapping_1D_32,false);
}

void* allocate_sprite_main(SpriteSize s, Illustration sprite, int *id){
	// allocate sprite
	u16* gfx= oamAllocateGfx(&oamMain, s, SpriteColorFormat_256Color);
	// copying palette
	dmaCopy(sprite.palette,(void*)SPRITE_PALETTE,sprite.palette_length);

	// copying tiles
	dmaCopy(sprite.tiles,(void*)gfx,sprite.tiles_length);

	*id= sprite_id_main++;

	return gfx;
}
void deallocate_sprite_main(void* gfx){
	oamFreeGfx(&oamMain, gfx);
}


void* allocate_sprite_sub(SpriteSize s, Illustration sprite, int *id){
	// allocate sprite
	u16* gfx_sub= oamAllocateGfx(&oamSub, s, SpriteColorFormat_256Color);
	// copying palette
	dmaCopy(sprite.palette,(void*)SPRITE_PALETTE_SUB,sprite.palette_length);

	// copying tiles
	dmaCopy(sprite.tiles,(void*)gfx_sub,sprite.tiles_length);

	*id= sprite_id_sub++;

	return gfx_sub;
}

void deallocate_sprite_sub(void * gfx){
	oamFreeGfx(&oamSub,gfx);
}

void set_sprite_main(const void* gfx, int id,int x, int y,bool hide){
	oamSet(&oamMain,
						id,
						x,y,
						0,
						0,
						SpriteSize_32x32,
						SpriteColorFormat_256Color,
						gfx,
						-1,
						false,
						hide,
						false, false,
						false
						);

}


void set_sprite_sub(const void* gfx_sub, int id,int x, int y, bool hidden){
	oamSet(&oamSub,
						id,
						x,y,
						0,
						0,
						SpriteSize_32x64,
						SpriteColorFormat_256Color,
						gfx_sub,
						-1,
						false,
						hidden,
						false, false,
						false
						);

			oamUpdate(&oamSub);
}

void draw_sprite_main(){
	oamUpdate(&oamMain);
}

void draw_sprite_sub(){
	oamUpdate(&oamSub);
}
