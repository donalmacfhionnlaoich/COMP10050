/*
 * moveSlot.c
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#include "structs.h"
#include "Functions.h"
#include <string.h>
#include <stdlib.h>

void moveslot(struct player_type *player, struct slot_type *slot, int i){
	char name1[10] = "City";
	char name2[10] = "Hill";

	slot->taken = 1;
	strcpy(player->currentSlot, slot->type);
	if(strstr(player->currentSlot, name1)!=NULL){
		city(&player[i]);
	}
	else if(strstr(player->currentSlot, name2)!=NULL){
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
