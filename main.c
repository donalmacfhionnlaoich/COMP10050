/*
 * main.c
 *
 *  Created on: 3 Mar 2017
 *      Author: danielhand
 */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Functions.h"
#include "structs.h"

#define PLAYER_MAX 6
#define SLOT_MAX 20

int main(void){
	
	setbuf(stdout,NULL);	//Fix error with eclipse on Windows.

	srand(time(NULL));		// Seed rand function with time
	
	int i, x, y;
	unsigned int n, s;
	
	char type1[10] = "uman";
	char type2[10] = "gre";
	char type3[10] = "izard";
	char type4[10] = "lf";
	
	printf("There can be 1-%d players in the game.\n", PLAYER_MAX);
	printf("How many players are there: ");
	scanf("%u", &n);		// Stores number of players in n
	while(n<1 || n>PLAYER_MAX)
	{
		puts("That number of players is invalid. Please enter a valid number of players.");
		scanf("%u", &n);
	}
	
	printf("\nThere can be %d-20 slots in the game.\n", n);
	printf("\nHow many slots would you like: ");
	scanf("%u", &s);
	while(s<1 || s>SLOT_MAX || s<n)
	{
		puts("That number of slots is invalid. Please enter a valid number of slots.");
		scanf("%u", &s);
	}
	
	struct player_type *player;
	struct slot_type *slot;
	int *a, b;
	a = calloc(s,sizeof(int));
	player = calloc(n,sizeof(struct player_type));
	slot = calloc(s,sizeof(struct slot_type));

	puts("\nA players name can have a maximum of 19 characters.");
	puts("There are 4 types of player: Elf, Human, Ogre and Wizard.");	//Giving information to user on the possible types of player_type and name specs.
	if((n <= PLAYER_MAX && s <= SLOT_MAX) && (n <= s)){
		for(i=0; i<n; i++){
			printf("\nEnter Player %d's name: ", i+1);
			scanf("%19s", player[i].name);	//Ensuring the maximum of characters of name is at most 19 so that there is one space for the null terminator.
			printf("\nEnter Player %d's type: ", i+1);
			scanf("%s", player[i].type);
			player[i].lifepoints = 100.0;
		}
		for(i=0; i<n; i++){
			if(strstr(player[i].type, type1)!=NULL){
				human(&player[i]);
			}
			else if(strstr(player[i].type, type2)!=NULL){
				ogre(&player[i]);
			}
			else if(strstr(player[i].type, type3)!=NULL){
				wizard(&player[i]);
			}
			else if(strstr(player[i].type, type4)!=NULL){
				elf(&player[i]);
			}
			else{
				printf("\nSorry one or more of the entered player types was incorrect\n");
				exit(1);
			}
		}
		slotnum(s, a);
		for(i=0; i<s; i++){
			x = rand() % 3 + 1;
			slot[i].numb = x;
			slotname(&slot[i], x);
			slot[i].numb = a[i];
			slot[i].taken = 0;
		}
		puts("temp\n");
		printPlayersStatus(player, n); // temp
		for(i=0; i<n; i++){
			player[i].slot = slot[i].numb;
			printf("*-%d - %d\n", player[i].slot, slot[i].numb);
			y = player[i].slot;
			moveslot(player, &(slot[y-1]), i);
//			printf("Attrib %d-*\n", player[i].strength);
		}
		printPlayersStatus(player, n);
		printf("\n");
		for(i=0;i<s;i++){
			printf("Slot: %d - \ttype: %-12s - \tTaken:%d\tslotnum %d\n", i+1, slot[i].type, slot[i].taken, slot[i].numb); //Replaced free with taken as it was representing the opposite of the values presented.
		}
		// Down to line 192 is statements for asking each player what move they would 
		// like and stores 1 for forward moves or 0 for backwards in array b[n]
		
		for(i=0; i<n; i++){
			y = player[i].slot;
			printf("\nPlayer %d - %s is on a %s slot\n", i+1, player[i].name,  player[i].currentSlot);
			if((y != 1) && (y != s)) {
				if(slot[y-2].taken == 0 && slot[y].taken == 0 ){
					printf("Would you like to move to the next or the previous slot?\n");
					printf("Press 1 for forward move or 0 for backward move\n");
					scanf("%d",&b);
					while(b!=0 && b!=1)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y-2].taken == 0 && slot[y].taken == 1 ){
					printf("Would you like to move forwards and attack or move backward to the previous slot?\n");
					printf("Press 3 for forward attack or 0 for backward move\n");
					scanf("%d", &b);
					while(b!=0 && b!=3)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y-2].taken == 1 && slot[y].taken == 0 ){
					printf("Would you like to move forwards to the next slot or move backward and attack?\n");
					printf("Press 1 for forward move or 4 for backward attack\n");
					scanf("%d", &b);
					while(b!=1 && b!=4)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y-2].taken == 1 && slot[y].taken == 1 ){
					printf("Would you like to move forwards and attack or move backward and attack?\n");
					printf("Press 3 for forward attack or 4 for backward attack\n");
					scanf("%d", &b);
					while(b!=3 && b!=4)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
			}
			else if(y == 1) {
				if(slot[y].taken == 0 ){
					printf("You are on the first slot, move to the next slot?\n");
					printf("Press 1 to confirm\n");
					scanf("%d", &b);
					while(b!=1)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y].taken == 1 ){
					printf("You are on the first slot, attack player on slot 2?\n");
					printf("Press 3 to confirm\n");
					scanf("%d", &b);
					while(b!=3)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
			}
			else if(y == s) {
				if(slot[y-2].taken == 0 ){
					printf("You are on the last slot, move to the previous slot?\n");
					printf("Press 0 to confirm\n");
					scanf("%d", &b);
					while(b!=0)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y-2].taken == 1 ){
					printf("You are on the last slot, attack player on slot %d?\n", s-1);
					printf("Press 4 to confirm\n");
					scanf("%d", &b);
					while(b!=4)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
			}
		}

		printf("MOVE");
		//printPlayersStatus(player, n);
		puts("Name (Type, Lifepoints)\n");
		for(i=0;i<n;i++)
		{
			printf("%-19s (%s, %0.1f)\n",player[i].name,player[i].type,player[i].lifepoints);
		}
	}
	else if(n > PLAYER_MAX){
		printf("Sorry maximum number of player_type is 6!\n");
		exit(1);
	}
	else if(s > SLOT_MAX){
		printf("Sorry maximum number of slots is 20!\n");
		exit(1);
	}
	else{
		printf("Sorry but there needs to at least one slot per player\n");
		exit(1);
	}

	free(a);
	free(player);
	free(slot);
	return (0);
	
}

