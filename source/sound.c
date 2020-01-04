/*
 * sound.c
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */
#include "sound.h"
void configure_sound(){
	mmInitDefaultMem((mm_addr)soundbank_bin);
	mmLoadEffect(SFX_CANNON);
	mmLoadEffect(SFX_EXPLOSION);

}

void cannon_sound(){
	mmEffect(SFX_CANNON);
}
void cannon_sound_over(){
	mmEffectCancel(SFX_CANNON);
}


void explosion_sound(){
	mmEffect(SFX_EXPLOSION);
}


void explosion_sound_over(){
	mmEffectCancel(SFX_EXPLOSION);
}
