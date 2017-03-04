/*
 * printPlayersStatus.c
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#include "structs.h"
#include <stdio.h>

void printPlayersStatus(struct player_type player [6], int n)
{
	for(int i=0; i<n; ++i)
	{
		printf("\n-PLAYER %d-\n", i+1);
		printf("Name:\t\t%s\n", player[i].name);
		printf("Type:\t\t%s\n", player[i].type);
		printf("Life Points:\t%.1f\n", player[i].lifepoints);
		printf("Smartness:\t%d\n", player[i].smartness);
		printf("Strength:\t%d\n", player[i].strength);
		printf("Magic Skills:\t%d\n", player[i].magicskills);
		printf("Luck:\t\t%d\n", player[i].luck);
		printf("Dexterity:\t%d\n", player[i].dexterity);
		printf("Location:\tSlot %d\n", player[i].slot);
		printf("Slot Name:\t%s\n", player[i].currentSlot);
	}
}
