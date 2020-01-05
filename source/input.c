/*
 * input.c
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */

#include "input.h"

int poll_input() {
		scanKeys();
		keys=keysHeld();
		swiWaitForVBlank();
		touchRead(&touch);
    return 0;
}
