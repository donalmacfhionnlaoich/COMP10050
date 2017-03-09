/*
 * slotModForPlayer.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"

void city(struct player_type *player)
{
	if(player->smartness > 60)
	{
		printf("Test1");
		if(player->magicskills >= 90)	//Changed 89 to 90, if magic skills was =89 and we wanted to add ten then it should be 99, not set to 100.
		{
			player->magicskills = 100;
			printf("Test2");
		}
		else if(player->magicskills < 90)	//Changed 89 to 90, if magic skills was =89 and we wanted to add ten then it should be 99, not set to 100.
		{
			player->magicskills += 10;
			printf("Test3");
		}
	}
	else if(player->smartness <= 50)
	{
		printf("Test1a");
		if(player->magicskills <= 10)
		{
			player->magicskills = 0;
			printf("Test2a");
		}
		else if(player->magicskills > 10)
		{
			player->magicskills -= 10;
			printf("Test3a");
		}
	}
}

void hill(struct player_type *player)
{
	if(player->dexterity >= 60)
	{
		printf("Test1b");
		if(player->strength >= 90)
		{
			player->strength = 100;
			printf("Test2b");
		}
		else if(player->strength <= 89)
		{
			player->strength += 10;
			printf("Test3b");
		}
	}
	else if(player->dexterity < 50)
	{
		printf("Test1c");

		if(player->strength <= 10)
		{
			player->strength = 0;
			printf("Test2c");
		}
		else if(player->strength > 10)
		{
			printf("Test3c");
			player->strength -= 10;
		}
	}
}
