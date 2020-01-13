/*
 * state.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */
#pragma once
#ifndef STATE_H_
#define STATE_H_

typedef struct {
    // prevent subsequent calls for older states by returning anything != 0
    // for example, the pause menu state's update() will return 1 so that it pauses other states
    int (*init)();
    int (*deinit)();
    int (*update)();
	int (*draw)();
} State;

#endif /* STATE_H_ */

