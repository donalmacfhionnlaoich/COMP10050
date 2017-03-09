/*
 * playerAction.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"	//Including definition of structs.
#include "Functions.h"	//Including prototypes of functions.

//Function to carry out player's actions based on their selection.
void playerAction(int y, int b,struct player_type *player,struct slot_type *slot,int i,int n)
{
	int j,x;	//Declaring integers. j used as indexing variable. x is used to hold the value of a member of a player.

	if(b == 0){			//If player has chosen to move backwards one slot.
		moveslot(&player[i], &slot[y-2], i);	//Calling moveslot function to move player.
		slot[y-1].taken = 0;					//Changing taken value of the slot that was previously occupied to signify that it is now empty.
		player[i].slot -= 1;					//Decrementing the slot member of the player since they have moved back one slot.
	}

	else if(b == 1){	//If player has chosen to move forwards one slot.
		moveslot(&player[i], &slot[y], i);		//Calling moveslot function to move player.
		slot[y-1].taken = 0;					//Changing taken value of the slot that was previously occupied to signify that it is now empty.
		player[i].slot += 1;					//Incrementing the slot member of the player since they have moved forward one slot.
	}
	else if(b == 3){	//If player has chosen to attack the player that is in the slot directly infront of them.
		for(j=0;j<n;j++){						//For loop to find which player the player is attacking.
			x = player[j].slot;					//Assigning value of player member slot to x.
			if(x == (y + 1)){					//Checking whether the jth player is in the slot that is directly after the slot the attacking player is in.
				attack(&player[i], &player[j]);	//When the player that is directly after the attacking player is found, the attack function is called passing in both
			}										//the attacking (i-th) and attacked (j-th) player.						
		}
	}
	else if(b == 4){	//If player has chosen to attack the player that is in the slot directly behind of them.
		for(j=0;j<n;j++){						//For loop to find which player the player is attacking.
			x = player[j].slot;					//Assigning value of player member slot to x.
			if(x == (y - 1)){					//Checking whether the jth player is in the slot that is directly before the slot the attacking player is in.
				attack(&player[i], &player[j]);	//When the player that is directly before the attacking player is found, the attack function is called passing in both
			}										//the attacking (i-th) and attacked (j-th) player.
		}
	}
}
