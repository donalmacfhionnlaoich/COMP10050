/*
 * moveSlot.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void moveslot(struct player_type *player, struct slot_type *slot, int i){
	char name1[10] = "City";
	char name2[10] = "Hill";

	// debug test only delete afterwards
	printf("Attrib str:%d-smt:%d-dex%d-mgk%d*\n", player[i].strength, player[i].smartness, player[i].dexterity, player[i].magicskills);
	printf("player index: %d*\n", i);
	printf("slottype slotnum : %d, player slotnum: %d, type %s\n", slot->numb, player[i].slot, slot->type);
	slot->taken = 1;
	strcpy(player[i].currentSlot, slot->type);
	if(strstr(player->currentSlot, name1)!=NULL){
		printf("City move\n");
		city(&player[i]);
	}
	else if(strstr(player->currentSlot, name2)!=NULL){
		printf("hill move\n");
		hill(&player[i]);
	}
}

void slotnum(int x, int *a){
	int i, j, swap;

	for(i=0; i<x; ++i){
		a[i] = i+1;
	}
	for(i=x-1; i>1; --i){
		j = rand() % i;
		swap = a[j];
		a[j] = a[i];
		a[i] = swap;
	}
}

void slotname(struct slot_type *slot, int x){
	if(x == 1){
		strcpy(slot->type,"Level Ground");
	}
	else if(x == 2){
		strcpy(slot->type, "Hill");
	}
	else if(x == 3){
		strcpy(slot->type, "City");
	}
}
