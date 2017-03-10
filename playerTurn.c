/*
 * playerTurn.c
 *
 *  Created on: 10 Mar 2017
 *      Author: Dónal
 */
#include "structs.h"
#include "functions.h"

void playerTurn(struct player_type *player,struct slot_type *slot,int n, int s)
{
	int b;

	for(int i=0; i<n; i++)
	{
		int y = player[i].slot;		// Assign slot number to y for comparison with other slots
		printf("\nPlayer %d - %s\nYou are on slot %d, a %s slot\n", i+1, player[i].name, player[i].slot, player[i].currentSlot);
		/* Option for player with no opponents on adjacent slots */
		if((y != 1) && (y != s)) {
			if(slot[y-2].taken == 0 && slot[y].taken == 0 ){
				printf("Would you like to move to the next or the previous slot\nor attack the nearest player?\n");
				printf("Press 1 for forward move or 0 for backward move or 7 for nearest player attack that is more than one slot away.\n");
				scanf("%d",&b);
				while(b!=0 && b!=1 && b!=7)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
			/* Option for player that has opponent ahead and empty slot behind */
			else if(slot[y-2].taken == 0 && slot[y].taken == 1 ){
				printf("Would you like to move forwards and attack or move backward to the previous slot?\n");
				printf("Press 3 for forward attack player in the next slot or 0 for backward move.\n");
				scanf("%d", &b);
				while(b!=0 && b!=3)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
			/* Option for player that has opponent behind and empty slot ahead */
			else if(slot[y-2].taken == 1 && slot[y].taken == 0 ){
				printf("Would you like to move forwards to the next slot or move backward and attack?\n");
				printf("Press 1 for forward move or 4 for backward attack player in previous slot.\n");
				scanf("%d", &b);
				while(b!=1 && b!=4)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
			/* Option for player that has opponents ahead and behind */
			else if(slot[y-2].taken == 1 && slot[y].taken == 1 ){
				printf("Would you like to move forwards and attack or move backward and attack?\n");
				printf("Press 3 for forward attack in the next slot or 4 for backward attack in previous slot, both players are adjacent to your slot.\n");
				scanf("%d", &b);
				while(b!=3 && b!=4)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
		}
		/* If player is on the first slot */
		else if(y == 1) {
			/* And next slot is free*/
			if(slot[y].taken == 0 ){
				printf("Move to the next slot or attack nearest player?\n");
				printf("Press 1 for forward move or 5 for nearest player attack that is more than one slot away.\n");
				scanf("%d", &b);
				while(b!=1 && b!=5)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
			/* And next slot is free */
			else if(slot[y].taken == 1 ){
				printf("Attack player on slot 2?\n");
				printf("Press 3 to confirm\n");
				scanf("%d", &b);
				while(b!=3)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
		}
		/* If player is on the last slot */
		else if(y == s) {
			/* And previous slot is empty */
			if(slot[y-2].taken == 0 ){
				printf("This is the last slot, move to the previous slot or attack nearest player?\n");
				printf("Press 0 for backward move or 6 for nearest player attack that is more than one slot away.\n");
				scanf("%d", &b);
				while(b!=0 && b!=6)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
			/* And previous slot is taken */
			else if(slot[y-2].taken == 1 ){
				printf("This is the last slot, attack player on slot %d?\n", s-1);
				printf("Press 4 to confirm\n");
				scanf("%d", &b);
				while(b!=4)
				{
					puts("That was not a valid option. Please enter a valid option.");
					scanf("%d",&b);
				}
				playerAction(y ,b ,player ,slot ,i ,n ,s);	// Function for move or attack (see playerAction.c)
			}
		}
	}
}
