/*
 * view.c
 *
 *  Created on: Jan 12, 2020
 *      Author: nds
 */

#include "view.h"



void init_bg_view(){
	left_tank_hidden =false;
	right_tank_hidden = true;
}
void switch_bg_view(){
	if(left_tank_hidden){
		left_tank_hidden=false;
		right_tank_hidden= true;
		REG_BG0HOFS = 0;
		REG_BG1HOFS = 0;

	}else{
		left_tank_hidden=true;
		right_tank_hidden= false;
		REG_BG0HOFS = 256;
		REG_BG1HOFS = 256;
	}
}
