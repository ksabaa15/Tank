/*
 * input.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */
#pragma once
#ifndef INPUT_H_
#define INPUT_H_
#include <nds.h>

unsigned keys;
unsigned down;
touchPosition touch;

/*!
 * @brief Polls input
 * @return 0 on success
 */
int poll_input();

#endif /* INPUT_H_ */

