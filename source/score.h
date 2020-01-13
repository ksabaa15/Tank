/*
 * score.h
 *
 *  Created on: Jan 13, 2020
 *      Author: nds
 */

#ifndef SCORE_H_
#define SCORE_H_

#include <nds.h>
#include "numbers.h"
#include "graphics.h"


void init_score();
void player1_loses_score();
void player2_loses_score();

void update_score();

#endif /* SCORE_H_ */
