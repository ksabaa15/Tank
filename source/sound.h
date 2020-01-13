/*
 * sound.h
 *
 *  Created on: Jan 4, 2020
 *      Author: nds
 */

#ifndef SOUND_H_
#define SOUND_H_
#pragma once

#include <nds.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

void configure_sound();

void cannon_sound();

void explosion_sound();

void music_sound();

#endif /* SOUND_H_ */
