/*
 * state_manager.h
 *
 *  Created on: Jan 3, 2020
 *      Author: Ulysse
 */

#include "state.h"

#define MAX_STATES  4   // enough for combining the 3 different states (main menu, game, pause menu)

typedef struct {
    State *stack[MAX_STATES];
} StateManager;

/*!
 * @brief Initializes a state manager
 * @param state_manager pointer to the state stack
 * @return 0 on success
 */
int state_manager_init(StateManager *state_manager);

/*!
 * @brief Pushes a state onto the stack
 * @param state_manager pointer to the state stack
 * @param state pointer to the state to push
 * @return 0 on success
 */
int state_manager_push(StateManager *state_manager, State *state);

/*!
 * @brief Pops (removes) a state from the stack
 * @param state_manager pointer to the state stack
 * @return a pointer to the popped state or NULL if the stack is empty
 */
State* state_manager_pop(StateManager *state_manager);

/*!
 * @brief Updates all states
 * @param state_manager pointer to the state stack
 * @return 0 on success
 */
int state_manager_update(StateManager *state_manager);

/*!
 * @brief Draws all states
 * @param state_manager pointer to the state stack
 * @return 0 on success
 */
int state_manager_draw(StateManager *state_manager);

