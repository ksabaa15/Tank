/*
 * cannon_ball.c
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */
#include "cannon_ball.h"

State STATE_CANNON = {
	&init_cannon,
	&deinit_cannon,
	&update_cannon,
	&draw_cannon
};

Illustration cannon_ball_sprite ={(void*)spritesPal, (void*)&((char*)spritesTiles)[2048], (void*)NULL, spritesPalLen,spritesTilesLen/3,0 };
Illustration explosion_sprite ={(void*)spritesPal, (void*)&((char*)spritesTiles)[3072], (void*)NULL, spritesPalLen,spritesTilesLen/3,0 };

// id to the corresponding sprites
int id_cannon_ball_sprite;
int id_explosion_sprite;

/*
 * pointer to memory where the sprites are, we will only have one cannon ball and one explosion,
 * when we finish a given animation we put them outside the screen, and reuse them later on
 */
u16* gfx_cannon_ball;
u16* gfx_explosion;

Tank shooter_i, target_i;
void(*tank_got_hit_callback_i)(Tank tank);
double angle_i;
Terrain terrain_i;

double x_force;
double y_force;
double gravity;
double x,y;
int power;
int time_explosion;

extern void cannon_shoot(Tank shooter, Tank target, void(*tank_got_hit_callback)(Tank tank), int angle, Terrain terrain){
	shooter_i = shooter;
	target_i= target;
	tank_got_hit_callback_i= tank_got_hit_callback;
	angle_i = angle;
	terrain_i = terrain;
	state_manager_push(&state_manager, &STATE_CANNON);
}

int init_cannon(){
	gfx_cannon_ball= allocate_sprite_main(SpriteSize_32x32, cannon_ball_sprite, &id_cannon_ball_sprite);
	gfx_explosion=allocate_sprite_main(SpriteSize_32x32, explosion_sprite, &id_explosion_sprite);
	cannon_sound();
	power =4;
	x_force = power*cos(radians(angle_i));
	y_force = power*sin(radians(angle_i));
	gravity =0.1;
	x= shooter_i.x;
	if(shooter_i.id==LEFT_TANK)x+=32;
	else x-=8;
	y= shooter_i.y;
	time_explosion=0;
	return 0;
}
int deinit_cannon(){
	deallocate_sprite_main(gfx_cannon_ball);
	deallocate_sprite_main(gfx_explosion);
	return 0;
}
int update_cannon(){
	if(y+32<=terrain_i.func(x)){
		set_sprite_main(gfx_cannon_ball, id_cannon_ball_sprite,(int)x,(int)y);
		if(shooter_i.id==RIGHT_TANK){
			x -= x_force;
		}else{
			x += x_force;
		}
		y -= y_force;
		y_force-= gravity;
	}else{
		if(time_explosion==0){
			explosion_sound();
			// get the cannon ball sprite out of screen
			set_sprite_main(gfx_cannon_ball, id_cannon_ball_sprite,-32,-32);
			// set explosion
			set_sprite_main(gfx_explosion, id_explosion_sprite,(int)x,(int)y);

			if(target_i.x>=x &&target_i.x+32<=x){
				tank_got_hit_callback_i(target_i);
			}
		}

		if(time_explosion++ > 10){
			// get the explosion sprite out of screen
			set_sprite_main(gfx_explosion, id_explosion_sprite,-32,-32);
			state_manager_pop(&state_manager);
		}
	}
	return 1;
}
int draw_cannon(){
	draw_sprite_main();
	return 0;
}



