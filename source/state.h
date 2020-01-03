/*
 * state.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */
#pragma once

typedef struct {
    // prevent subsequent update/draw calls for older states by returning anything != 0
    // for example, the pause menu state's update() will return 1 so that it pauses other states
    int (*update)();
	int (*draw)();
} State;

