/*
 * cannon_ball.c
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */
#include "cannon_ball.h"
Illustration cannon_ball_sprite ={(void*)spritesPal, (void*)&((char*)spritesTiles)[2048], (void*)NULL, spritesPalLen,spritesTilesLen/3,0 };
Illustration explosion_sprite ={(void*)spritesPal, (void*)&((char*)spritesTiles)[3072], (void*)NULL, spritesPalLen,spritesTilesLen/3,0 };

int id_cannon_ball;
int id_explosion;

double x_force = 2;
double y_force = 2;
double gravity =0.05;
double x,y;

void cannon_shoot(int x_from, int y_from, int angle, Terrain terrain){
	 u16* gfx_cannon_ball=allocate_sprite_main(SpriteSize_32x32, cannon_ball_sprite, &id_cannon_ball);
	 cannon_sound();
	 x=x_from+32;
	 y= y_from;
	 while(y<=terrain.func(x)){
		 x+= x_force*cos(radians(angle));
		 y-= y_force*sin(radians(angle));
		 y_force-= gravity;
		 set_sprite_main(gfx_cannon_ball, id_cannon_ball,(int)x,(int)y);
		 swiWaitForVBlank();
	 }
	 set_sprite_main(gfx_cannon_ball, id_cannon_ball,-10,0);
	 u16* gfx_explosion =allocate_sprite_main(SpriteSize_32x32, explosion_sprite, &id_explosion);
	 set_sprite_main(gfx_explosion, id_explosion,(int)x,(int)y);
	 cannon_sound_over();
	 explosion_sound();
	 swiWaitForVBlank();

}

