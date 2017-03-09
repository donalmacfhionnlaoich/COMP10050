/*
 * playerTypes.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"
#include <stdlib.h>

void human(struct player_type *player){
	int attrib[5], sum, i;

	do{
		sum = 0;	//Reset sum to 0.
		for(i=0; i<5; i++){
			attrib[i] = rand() % 100 + 1;
			sum += attrib[i];
		}
	}while(sum >= 300);

	player->smartness = attrib[0];
	player->strength = attrib[1];
	player->magicskills = attrib[2];
	player->luck = attrib[3];
	player->dexterity = attrib[4];
}
void ogre(struct player_type *player){
	int attrib[2], sum;

	do{
		sum = 0;	//Reset sum to 0 if loops through again.
		attrib[0] = rand() % 21;
		attrib[1] = rand() % 101;	//Changed to 101 from 100+1 so capabilities may be zero
		sum = attrib[1] + attrib[0];
	}
	while(sum > 50);

	player->smartness = attrib[0];
	player->luck = attrib[1];
	player->strength = rand() % 21 + 80;	//Max strength possible is 100.
	player->dexterity = rand() % 21 + 80;	//Max dexterity possible is 100.
	player->magicskills = 0;
}
void wizard(struct player_type *player){

	player->smartness = rand() % 10 + 91;//Changed to 10 + 91 because all capabilities must be > 0
	player->luck = rand() % 50 + 51;	//Changed to 50 + 51 because all capabilities must be > 0
	player->strength = rand() % 20 + 1;	//Changed to 20 + 1 because all capabilities must be > 0
	player->dexterity = rand() % 100 + 1;
	player->magicskills = rand() % 20 + 81;//Changed to 20 + 81 because all capabilities must be > 0
}
void elf(struct player_type *player){

	player->smartness = rand() % 30 + 71;//Changed to 30 + 71 because all capabilities must be > 0
	player->luck = rand() % 40 + 61;	//Changed to 40 + 61 because all capabilities must be > 0
	player->strength = rand() % 50 + 1;	//Changed to 50 + 1 because all capabilities must be > 0
	player->dexterity = rand() % 100 + 1;
	player->magicskills = rand() % 29 + 51;	//Incremented 50 to 51 and changed rand ()% 31 to 29. (50<magic<80)
}