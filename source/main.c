/*
 * main.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Karim
 */

#include <nds.h>
#include <stdio.h>

int main(void) {
	
    consoleDemoInit();
    printf("\nTemplate nds\n");

    while(1)
        swiWaitForVBlank();	
}
