/*
 * button.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */
#pragma once

typedef struct {
    int x; int y;
    int width; int height;
    void (*onPress)();
} Button;

/*!
 * @brief Tests if a button was touched
 *  and calls onPress if so
 * @param button pointer to the button to test
 * @param x the x position of the touch
 * @param y the y position of the touch
 */
void button_touch(Button *button, int x, int y);
