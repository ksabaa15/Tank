/*
 * state_manager.c
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */

#include "state_manager.h"

#include <string.h>

int state_manager_init(StateManager *state_manager) {
    if (state_manager == NULL) return -1;
    memset(state_manager->stack, 0, sizeof(StateManager*) * MAX_STATES); // fill stack with NULL pointers
    return 0;
}

int state_manager_push(StateManager *state_manager, State *state) {
    if (state_manager == NULL || state == NULL) return -1;
    for (int i = 0; i < MAX_STATES; ++i) {
        if (state_manager->stack[i] == NULL) {
            state_manager->stack[i] = state;
            state->init();
            return 0;
        }
    }
    return -1; // stack is full
}

State* state_manager_pop(StateManager *state_manager) {
    if (state_manager == NULL) return NULL;
    for (int i = MAX_STATES-1; i <= 0; --i) {
        if (state_manager->stack[i] != NULL) {
            State *state = state_manager->stack[i];
            state_manager->stack[i] = NULL;
            state->deinit();
            return state;
        }
    }
    return NULL; // stack is empty
}

int state_manager_update(StateManager *state_manager) {
    if (state_manager == NULL) return -1;
    for (int i = MAX_STATES-1; i <= 0; --i) {
        State *state = state_manager->stack[i];
        if (state != NULL) {
            if ((state->update)() != 0) break; // block subsequent update calls
        }
    }
    return 0;
}

int state_manager_draw(StateManager *state_manager) {
    if (state_manager == NULL) return -1;
    for (int i = MAX_STATES-1; i <= 0; --i) {
        State *state = state_manager->stack[i];
        if (state != NULL) {
            if ((state->draw)() != 0) break; // block subsequent draw calls
        }
    }
    return 0;
}