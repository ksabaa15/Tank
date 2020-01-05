/*
 * tanks.c
 *
 *  Created on: Jan 3, 2020
 *      Author: Karim
 */
#include "tanks.h"

Illustration left_tank_illustartion ={(void*)spritesPal, (void*)&((char*)spritesTiles)[1024], (void*)NULL, spritesPalLen,spritesTilesLen/2,0 };

Illustration right_tank_illustartion = {(void*)spritesPal, (void*)&((char*)spritesTiles)[0], (void*)NULL, spritesPalLen,spritesTilesLen/2,0 };


int tank_init(Tank* tank ,Tank_id id, int x, Terrain terrain){
	if(tank==NULL ||x<0 ||x>255){
		return -1;
	}
	tank->id = id;
	tank->x = x;
	tank->y=  terrain.func(x)-32;
	tank->health= HEALTH_START_VALUE;
	if(id == LEFT_TANK){
		tank->illustration= left_tank_illustartion;
	}else{
		tank->illustration= right_tank_illustartion;
	}
	tank->terrain = terrain;

	tank->gfx_tank = allocate_sprite_main(SpriteSize_32x32,tank->illustration,&tank->sprite_id);

	return 0;
}

int tank_move(Tank* tank, int x){
	if(tank==NULL || x<0 ||x>255){
		return -1;
	}
	tank->x=x;
	tank->y=tank->terrain.func(x);
	return 0;
}

void draw_tank(Tank tank){

	set_sprite_main(tank.gfx_tank, tank.sprite_id, tank.x, tank.y);

}


void tank_shoot(Tank shooter, Tank target,int angle, Terrain terrain){
	cannon_shoot( shooter, target, tank_got_hit, angle, terrain);
}

void tank_got_hit(Tank tank){

}


