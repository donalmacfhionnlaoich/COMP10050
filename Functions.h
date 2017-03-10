/*
 * header.h
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "structs.h"

void printPlayersStatus(struct player_type *player, int n);

/* -----SLOT ASSIGN FUNCTIONS------ */
void moveslot(struct player_type *player, struct slot_type *slot, int i);
void slotnum(int x, int *a);
void slotname(struct slot_type *slot, int x);

/* -----SLOT MOVE AND ATTACK FUNCTIONS------ */
void city(struct player_type *player);
void hill(struct player_type *player);
void attack(struct player_type *attacker, struct player_type *attacked);
void playerAction(int y, int b,struct player_type *player,struct slot_type *slot,int i,int n,int s);

/* PLAYER TYPES SLOTS */
void human(struct player_type *player);
void ogre(struct player_type *player);
void wizard(struct player_type *player);
void elf(struct player_type *player);


#endif /* FUNCTIONS_H_ */
