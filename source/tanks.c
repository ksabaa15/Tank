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
	tank->y= (terrain.func(x)) -32;
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

int tank_move(Tank* tank, bool forward ){
	if(tank==NULL){
		return -1;
	}
	if((forward &&(tank->id== LEFT_TANK))||(!forward &&!(tank->id== LEFT_TANK)))
		tank->x+=3;
	else
		tank->x-=3;
	if(tank->x >= tank->terrain.max_x-32){
		tank->x=tank->terrain.max_x-32;
	}
	if(tank->x<0){
		tank->x=0;
	}
	if(tank->x<70 && tank->id==RIGHT_TANK){
		tank->x=70;
	}
	tank->y=tank->terrain.func(tank->x)-32;
	return 0;
}
int tank_angle(Tank* tank, bool up){
	if(up){
		tank->angle+=2;
	}else{
		tank->angle-=2;
	}
	if(tank->angle>70){
		tank->angle=70;
	}
	if(tank->angle<30){
		tank->angle=30;
	}
}

void draw_tank(Tank tank){
	if(tank.id== LEFT_TANK){
		set_sprite_main(tank.gfx_tank, tank.sprite_id, tank.x, tank.y,left_tank_hidden);
	}else{
		set_sprite_main(tank.gfx_tank, tank.sprite_id, tank.x, tank.y,right_tank_hidden);
	}

}


void tank_got_hit(Tank* tank){
	if(tank->id==LEFT_TANK)
		player1_loses_score();
	else
		player2_loses_score();
}

void tank_shoot(Tank shooter, Tank* target, Terrain terrain){
	cannon_shoot( shooter, target, tank_got_hit, terrain);
}

