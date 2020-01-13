/*
 * button.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#include "button.h"

void button_draw(Button *button) {
    // draw image
}

void button_touch(Button *button, int x, int y) {
    int touched = (
        (button->x <= x && x <= (button->x + button->width )) &&
        (button->y <= y && y <= (button->y + button->height))
    );
    if (touched) {
        button->onPress();
    }
}