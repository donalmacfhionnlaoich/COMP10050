/*
 * header.h
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "structs.h"

void printPlayersStatus(struct player_type player[6], int n);


void moveslot(struct player_type *player, struct slot_type *slot, int i);
void slotnum(int x, int *a);
void slotname(struct slot_type *slot, int x);


void city(struct player_type *player);
void hill(struct player_type *player);
void attack(struct player_type *attacker, struct player_type *attacked);
void playerAction(int y, int b,struct player_type player[6],struct slot_type slot[20],int i,int n);


void human(struct player_type *player);
void ogre(struct player_type *player);
void wizard(struct player_type *player);
void elf(struct player_type *player);


#endif /* FUNCTIONS_H_ */