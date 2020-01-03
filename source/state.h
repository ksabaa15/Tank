/*
 * state.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */
#pragma once

typedef struct {
    void (*update)();
	void (*draw)();
} State;

