/*
 * main.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */

#include <nds.h>
#include <stdio.h>
#include "game.h"
int main(void) {

	polling();
	update_game();
	draw();
	while(1)
		swiWaitForVBlank();
}
