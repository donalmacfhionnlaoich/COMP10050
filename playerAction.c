/*
 * playerAction.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */
#include <stdio.h>		//DELETE AFTER
#include "structs.h"	//Including definition of structs.
#include "Functions.h"	//Including prototypes of functions.

//Function to carry out player's actions based on their selection.
void playerAction(int y, int b,struct player_type *player,struct slot_type *slot,int i,int n,int s)
{
	int j,x, k, l;	//Declaring integers. j used as indexing variable. x is used to hold the value of a member of a player.

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
				return;
			}										//the attacking (i-th) and attacked (j-th) player.						
		}
	}
	else if(b == 4){	//If player has chosen to attack the player that is in the slot directly behind of them.
		for(j=0;j<n;j++){						//For loop to find which player the player is attacking.
			x = player[j].slot;					//Assigning value of player member slot to x.
			if(x == (y - 1)){					//Checking whether the jth player is in the slot that is directly before the slot the attacking player is in.
				attack(&player[i], &player[j]);	//When the player that is directly before the attacking player is found, the attack function is called passing in both
				return;
			}										//the attacking (i-th) and attacked (j-th) player.
		}
	}
	else if(b == 5){	//If player is in first slot and has chosen to attack the player that is in the nearest slot ahead of them.
		for(j=1;j<s;j++){						//For loop checking slots 2 upwards until it finds one thats inhabited
			if(slot[j].taken == 1){				//When it finds one 
				for(k=0; k<n; k++){				// it loops through the players 
					if(player[k].slot == j+1){	// to find the inhabitant.
						attack(&player[i], &player[k]);	//When the player that is nearest the attacking player is found, the attack function is called passing in both
						return;
					}									//the attacking (i-th) and attacked (j-th) player.
				}
			}
		}
	}
	else if(b == 6){	//If player is in last slot and has chosen to attack the player that is in the nearest slot behind of them.
		for(j=(s-1);j>-1;j--){						//For loop checking from last slot backwards until it finds one thats inhabited
			if(slot[j].taken == 1){				//When it finds one 
				for(k=0; k<n; k++){				// it loops through the players 
					if(player[k].slot == j+1){	// to find the inhabitant.
						attack(&player[i], &player[k]);	//When the player that is nearest the attacking player is found, the attack function is called passing in both
						return;
					}									//the attacking (i-th) and attacked (j-th) player.
				}
			}
		}
	}
	else if(b == 7){	//If player is in any slot with two vacant adjacent slots and has chosen to attack the player that is in the nearest slot to them.
		x = player[i].slot;						//Assigning value of player member slot to x.
		for(j=x;j<s;j++){						//Loops through slots in front of player
			if(slot[j].taken == 0){				
				k = 0;							//Incase no player is found k will stay at 0 allowing calculations on line 81 be valid
			}
			else if(slot[j].taken == 1){		// If player is found k will be assigned the slot number
				k = j+1;
				break;
			}
		}
		for(j=x-2;j>-1;j--){					//Loops through slots in behind player
			if(slot[j].taken == 0){
				l = 0;							//Incase no player is found l will stay at 0 allowing calculations on line 81 to be valid
						}
			else if(slot[j].taken == 1){
				l = j+1;						// If player is found l will be assigned the slot number
				break;
			}
		}
		if((x-k) > (x-l)){						// This calulation will determine if there are two players each side, which player is closest
			for(j=0;j<n;j++){					// Loops through player to find which is on slot l
				if(player[j].slot == l){		// is true iff k is greater therefore l is closer
					attack(&player[i], &player[j]);		
					return;
				}
			}
		}
		else{
			for(j=0;j<n;j++){					// Loops through player to find which is on slot k
				if(player[j].slot == k){		// is true iff l is greater therefore k is closer
					attack(&player[i], &player[j]);	
					return;
				}
			}
			
		}
	}
}
