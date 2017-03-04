/*
 * structs.h
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#ifndef STRUCTS_H_
#define STRUCTS_H_

struct player_type {
	char name[20];
	char type[20];
	char currentSlot[20];
	float lifepoints;
	int smartness;
	int strength;
	int magicskills;
	int luck;
	int dexterity;
	int slot;
};

struct slot_type {
	char type[20];
	int numb;
	int taken;
};

#endif /* STRUCTS_H_ */
