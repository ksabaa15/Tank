/*
 * cannon_ball.c
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */
#include "cannon_ball.h"
#define radians(a) (a*M_PI/180.0)
#include <math.h>
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

Tank  shooter_i;
Tank * target_i;

void(*tank_got_hit_callback_i)(Tank* tank);
double angle_i;bool left_bg=true;
Terrain terrain_i;
double x,y;
double x_force;
double y_force;
double gravity;
int power;
int time_explosion;
bool switch_bg;

extern void cannon_shoot(Tank shooter, Tank* target, void(*tank_got_hit_callback)(Tank* tank), Terrain terrain){
	shooter_i = shooter;
	target_i= target;
	tank_got_hit_callback_i= tank_got_hit_callback;
	angle_i = shooter.angle;
	terrain_i = terrain;
	state_manager_push(&state_manager, &STATE_CANNON);
	state_manager_update(&state_manager);
	switch_bg=false;
}

int init_cannon(){
	gfx_cannon_ball= allocate_sprite_main(SpriteSize_32x32, cannon_ball_sprite, &id_cannon_ball_sprite);
	gfx_explosion=allocate_sprite_main(SpriteSize_32x32, explosion_sprite, &id_explosion_sprite);
	cannon_sound();
	power =7;
	x_force = power*cos(radians(angle_i));
	y_force = power*sin(radians(angle_i));
	gravity =0.1;
	x_cannon_ball= shooter_i.x;
	if(shooter_i.id==LEFT_TANK)x_cannon_ball+=32;
	else x_cannon_ball-=8;
	y_cannon_ball= shooter_i.y;
	time_explosion=0;
	return 0;
}
int deinit_cannon(){
	deallocate_sprite_main(gfx_cannon_ball);
	deallocate_sprite_main(gfx_explosion);
	return 0;
}
int update_cannon(){
	if(((y_cannon_ball)+16)<terrain_i.func(x_cannon_ball)){
		if(y_cannon_ball<0){
			set_sprite_main(gfx_cannon_ball, id_cannon_ball_sprite,(int)x_cannon_ball,(int)y_cannon_ball,true);
		}else{
			set_sprite_main(gfx_cannon_ball, id_cannon_ball_sprite,(int)x_cannon_ball,(int)y_cannon_ball,false);
		}

		if(shooter_i.id==RIGHT_TANK){
			if(x_cannon_ball<0 && !right_tank_hidden){
				x=x_cannon_ball;
				x_cannon_ball=256;
				switch_bg_view();
				switch_bg=true;
			}
			x_cannon_ball -= x_force;
		}else{
			if(x_cannon_ball>256 && !left_tank_hidden){
				x = x_cannon_ball;
				x_cannon_ball=0;
				switch_bg_view();
				switch_bg=true;
			}
			x_cannon_ball += x_force;
		}
		y_cannon_ball -= y_force;
		y_force-= gravity;
	}else{
		if(time_explosion==0){
			explosion_sound();
			// get the cannon ball sprite out of screen
			set_sprite_main(gfx_cannon_ball, id_cannon_ball_sprite,-32,-32,false);
			// set explosion
			set_sprite_main(gfx_explosion, id_explosion_sprite,(int)x_cannon_ball-2,(int)y_cannon_ball-8,false);

			//tank_got_hit_callback_i(target_i);
			if(target_i->id==RIGHT_TANK &&x_cannon_ball > (target_i->x-7 ) && x_cannon_ball <(target_i->x+25)&&
								((!right_tank_hidden&&target_i->id==RIGHT_TANK) || (!left_tank_hidden&&target_i->id==LEFT_TANK)))
									tank_got_hit_callback_i(target_i);

			if(target_i->id==LEFT_TANK &&x_cannon_ball > (target_i->x-7 ) && x_cannon_ball <(target_i->x+25)&&
								((!right_tank_hidden&&target_i->id==RIGHT_TANK) || (!left_tank_hidden&&target_i->id==LEFT_TANK)))
									tank_got_hit_callback_i(target_i);


		}

		if(time_explosion++ > 10){
			// get the explosion sprite out of screen
			set_sprite_main(gfx_explosion, id_explosion_sprite,-32,-32,false);
			state_manager_pop(&state_manager);
			if(!switch_bg){
				switch_bg_view();
			}
		}
	}
	return 1;
}
int draw_cannon(){
	draw_sprite_main();
	return 0;
}

double angle_to_hit_green(int x_green,int x_red, int level){
	double y_cannon_ball,x_cannon_ball;
	int angle;
	double power =7;
	double gravity=0.1;
	double x_force, y_force;
	int min_diff=2000;
	int min_diff_angle;
	for(angle=30; angle<90; ++angle){
		x_force = power*cos(radians(angle));
		y_force = power*sin(radians(angle));
		y_cannon_ball=terrain_i.func(x_red)+32;
		x_cannon_ball=x_red+256;

		while(((y_cannon_ball)-8)>terrain_i.func(x_cannon_ball)){
					x_cannon_ball -= x_force;
					y_cannon_ball += y_force;
					y_force-= gravity;
		}
			if(abs(x_cannon_ball-(x_green+7))<min_diff){
				min_diff=abs(x_cannon_ball-(x_green+5));
				min_diff_angle = angle;
			}
	}
	int r= rand();
	if(r%3==0)
		return min_diff_angle;
	if(r%3==1)
		return min_diff_angle + 5*level;
	if(r%3==2)
		return min_diff_angle - 5*level;
}



