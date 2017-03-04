/*
 * slotModForPlayer.c
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#include "structs.h"

void city(struct player_type *player)
{
	if(player->smartness > 60)
	{
		if(player->magicskills >= 90)	//Changed 89 to 90, if magic skills was =89 and we wanted to add ten then it should be 99, not set to 100.
		{
			player->magicskills = 100;
		}
		else if(player->magicskills < 90)	//Changed 89 to 90, if magic skills was =89 and we wanted to add ten then it should be 99, not set to 100.
		{
			player->magicskills += 10;
		}
	}
	else if(player->smartness <= 50)
	{
		if(player->magicskills <= 9)
		{
			player->magicskills = 0;
		}
		else if(player->magicskills < 89)
		{
			player->magicskills -= 10;
		}
	}
}

void hill(struct player_type *player)
{
	if(player->dexterity >= 60)
	{
		if(player->strength >= 89)
		{
			player->strength = 100;
		}
		else if(player->strength < 89)
		{
			player->strength += 10;
		}
	}
	else if(player->dexterity < 50)
	{
		if(player->strength <= 9)
		{
			player->strength = 0;
		}
		else if(player->strength < 89)
		{
			player->strength -= 10;
		}
	}
}
