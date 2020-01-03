/*
 * state.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */

typedef struct {
    void (*update)();
	void (*draw)();
} State;

