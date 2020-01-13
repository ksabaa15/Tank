/*
 * sound.c
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */
#include "sound.h"
void configure_sound(){
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoad(MOD_MUSIC);
	mmLoadEffect(SFX_CANNON);
	mmLoadEffect(SFX_EXPLOSION);

}

void cannon_sound(){
	mmEffect(SFX_CANNON);
}


void explosion_sound(){
	mmEffect(SFX_EXPLOSION);
}
void music_sound(){
	mmStart(MOD_MUSIC,MM_PLAY_LOOP);
}


