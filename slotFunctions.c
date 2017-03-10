/*
 * moveSlot.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"	//Including definition of structs.
#include "Functions.h"	//Including function prototypes.
#include <string.h>		//Including string library for strstr and strcpy functions.
#include <stdlib.h>		//Including stdlib for rand function.

void moveslot(struct player_type *player, struct slot_type *slot, int i){
	char name1[10] = "City";	// For comparison with players current slot
	char name2[10] = "Hill";	// For comparison with players current slot

	slot->taken = 1;			// Update slots taken status
	strcpy(player[i].currentSlot, slot->type);	//Copy slot type to player.currenSlot
	if(strstr(player[i].currentSlot, name1)!=NULL){		//Returns value if "City" is players slot
		city(&player[i]);				// Then calls city function (see slotModForPlayer.c)
	}
	else if(strstr(player[i].currentSlot, name2)!=NULL){//Returns value if "Hill" is players slot
		hill(&player[i]);				// Then calls hill function (see slotModForPlayer.c)
	}
}

void slotnum(int x, int *a){	// Function shuffle an array of size x (we pass through s - the number of slots - for this value)
	int i, j, swap;
	/* Fisherr Yates Shuffle */
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

void slotname(struct slot_type *slot, int x){	// This function names the slot 
											//as per randomly assigned number in main
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
