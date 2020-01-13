/*
 * score.c
 *
 *  Created on: Jan 13, 2020
 *      Author: nds
 */
#include "score.h"
#define BEGINING_SCORE 4

int id_number1[BEGINING_SCORE];
void* gfx_number1[BEGINING_SCORE];

int id_number2[BEGINING_SCORE];
void* gfx_number2[BEGINING_SCORE];

int score1;
int score2;
int displayed1;
int displayed2;

//	set_sprite_sub( gfx_number[h], id_number[h],20, 60);
void init_score(){
	score1 = BEGINING_SCORE-1;
	score2 =BEGINING_SCORE-1;
	displayed1=BEGINING_SCORE-1;
	displayed2 = BEGINING_SCORE-1;

	int i=0;
	for(i=0; i<BEGINING_SCORE; ++i){
		Illustration number = {(void*)numbersPal, (void*)&((char*)numbersTiles)[2048*i], (void*)NULL, numbersPalLen,numbersTilesLen/11,0 };
		gfx_number1[i]=allocate_sprite_sub(SpriteSize_32x64,number,&id_number1[i]);
		gfx_number2[i]=allocate_sprite_sub(SpriteSize_32x64,number,&id_number2[i]);
	}
	set_sprite_sub( gfx_number1[displayed1], id_number1[displayed1],40, 70);
	set_sprite_sub( gfx_number2[displayed2], id_number2[displayed2],170, 70);

}
void player1_loses_score(){
	--score1;
	if(score1<0)
		score1=0;
}

void player2_loses_score(){
	--score2;
	if(score2<0)
		score2=0;

}

void update_score(){

	if(score1<displayed1){
		set_sprite_sub( gfx_number1[displayed1], id_number1[displayed1],-40, 0);
		set_sprite_sub( gfx_number1[score1], id_number1[score1],40, 70);
		displayed1=score1;
	}
	if(score2<displayed2){
		set_sprite_sub( gfx_number2[displayed2], id_number2[displayed2],-40, 0);
		set_sprite_sub( gfx_number2[score2], id_number2[score2],170, 70);
		displayed2=score2;
	}
}

