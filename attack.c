/*
 * attack.c
 *
 *  Created on: 4 Mar 2017
 *      Author: Dónal
 */

#include "structs.h"

void attack(struct player_type *attacker, struct player_type *attacked)
{
	float x = attacked->strength;

	if(attacked->strength <= 70)
	{
		attacked->lifepoints -= (0.5 * x);
	}
	else if(attacked->strength > 70)
	{
		attacker->lifepoints -= (0.3 * x);
	}
}
