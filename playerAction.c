/*
 * playerAction.c
 *
 *  Created on: 4 Mar 2017
 *      Author: D�nal
 */

#include "structs.h"
#include "Functions.h"

void playerAction(int y, int b,struct player_type *player,struct slot_type *slot,int i,int n)
{
	int j,x;

	if(b == 0){
		moveslot(&player[i], &slot[y-2], i);
		slot[y-1].taken = 0;
		player[i].slot -= 1;
	}

	else if(b == 1){
		moveslot(&player[i], &slot[y], i);
		slot[y-1].taken = 0;
		player[i].slot += 1;
	}
	else if(b == 3){
		for(j=0;j<n;j++){
			x = player[j].slot;
			if(x == (y + 1)){
				attack(&player[i], &player[j]);
			}
		}
	}
	else if(b == 4){
		for(j=0;j<n;j++){
			x = player[j].slot;
			if(x == (y - 1)){
				attack(&player[i], &player[j]);
			}
		}
	}
}
