/*
 * game.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */
#include "game.h"

void polling(){};

void update_game(){

	Illustration background = { backgroundPal, backgroundTiles,backgroundMap, backgroundPalLen, backgroundTilesLen, backgroundMapLen };

	set_background_main_screen(background);
	set_background_sub_screen(background);

	int id_tank, id_target_mark;
	Illustration tank = { spritesPal, (void*)&((void*)spritesTiles)[1024],NULL, spritesPalLen, spritesTilesLen/2,0 };
	Illustration target_mark = { spritesPal, (void*)spritesTiles,NULL, spritesPalLen, spritesTilesLen/2,0 };

	configure_sprites_main();
	configure_sprites_sub();

	u16* gfx_tank_main = allocate_sprite_main(SpriteSize_32x32,tank,&id_tank);
	u16* gfx_target_mark_main = allocate_sprite_main(SpriteSize_32x32,target_mark,&id_target_mark);

	set_sprite_main(gfx_tank_main, id_tank, 10, 110,false);
	set_sprite_main(gfx_target_mark_main, id_target_mark, 25, 108,false);

	u16* gfx_tank_sub = allocate_sprite_sub(SpriteSize_32x32,tank,&id_tank);
	set_sprite_sub(gfx_tank_sub, id_tank, 100, 110,false);

}
void draw(){};
