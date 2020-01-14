/*
 * score.c
 *
 *  Created on: Jan 13, 2020
 *      Author: nds
 */
#include "score.h"
#include "state_manager.h"
#include "main_menu.h"
#include "pause_menu.h"


#define BEGINING_SCORE 4

int id_number1[BEGINING_SCORE];
void* gfx_number1[BEGINING_SCORE];

int id_number2[BEGINING_SCORE];
void* gfx_number2[BEGINING_SCORE];

int score1;
int score2;

static bool initialized=false;

void init_score(){
	score1 = BEGINING_SCORE-1;
	score2 =BEGINING_SCORE-1;
}
void init_score_sprites(){
	if(!initialized){
		initialized=true;
		int i=0;
		for(i=0; i<BEGINING_SCORE; ++i){
			Illustration number = {(void*)numbersPal, (void*)&((char*)numbersTiles)[2048*i], (void*)NULL, numbersPalLen,numbersTilesLen/11,0 };
			gfx_number1[i]=allocate_sprite_sub(SpriteSize_32x64,number,&id_number1[i]);
			gfx_number2[i]=allocate_sprite_sub(SpriteSize_32x64,number,&id_number2[i]);
		}
		set_sprite_sub( gfx_number1[score1], id_number1[score1],40, 70,false);
		set_sprite_sub( gfx_number2[score2], id_number2[score2],170, 70,false);
	}
}
void player1_loses_score(){
	--score1;
	if(score1<0)
		score1=0;
	if(score1==0){
		quit();
	}
}

void player2_loses_score(){
	--score2;
	if(score2<0)
		score2=0;
	if(score2==0){
		quit();
	}
}

void update_score(){
	int i;
	for(i=0; i<BEGINING_SCORE;++i){
		set_sprite_sub( gfx_number1[i], id_number1[i],40, 70, i != score1);
		set_sprite_sub( gfx_number2[i], id_number2[i],170, 70, i != score2);
	}
}

