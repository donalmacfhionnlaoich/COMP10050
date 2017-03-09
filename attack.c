/*
 * attack.c
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#include "structs.h"	//Including the definition of the structs.

//Function for when one player decides to attack another.
void attack(struct player_type *attacker, struct player_type *attacked)
{
	float x = attacked->strength;	//float to hold the value of the attacked players strength.

	if(attacked->strength <= 70)		//If the attacked players strength is less than or equal to 70 then the attacked player gets half
	{									//of their strength subtracted from their life points.
		attacked->lifepoints -= (0.5 * x);
	}
	else if(attacked->strength > 70)	//If the attacked players strength is greater than 70 then the player who initiated the attack gets
	{									//three tenths of the attacked players strength taken from their lifepoints.
		attacker->lifepoints -= (0.3 * x);
	}
}
