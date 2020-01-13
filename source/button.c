/*
 * button.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Ulysse
 */
#include "button.h"
#include "input.h"

void button_touch(Button *button, int x, int y) {
    int touched = (down & KEY_TOUCH) && (
        (button->x <= x && x <= (button->x + button->width )) &&
        (button->y <= y && y <= (button->y + button->height))
    );
    if (touched) {
        button->onPress();
    }
}