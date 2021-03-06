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

/* File inclusion headers */
#include "Functions.h"
#include "structs.h"

/* Preprocessor directives for max. allowed players and slots */
#define PLAYER_MAX 6
#define SLOT_MAX 20

int main(void){
	
	setbuf(stdout,NULL);	//Fix error with eclipse on Windows.

	srand(time(NULL));		// Seed rand function with time
	
	int i, x, y, typeNum;
	unsigned int n, s;
	
	/* Below code gets prompt from user displaying relevant error messages if incorrect numbers are entered */
	printf("There can be 1-%d players in the game.\n", PLAYER_MAX);
	printf("How many players are there: ");
	scanf("%u", &n);		// Stores number of players in n
	/* Loop which ensures players number between 1 and defined player max (6) */
	while(n<1 || n>PLAYER_MAX)
	{
		puts("That number of players is invalid. Please enter a valid number of players.");
		scanf("%u", &n);	// Re-loops if incorrect number is entered
	}
	printf("\nThere can be %d-20 slots in the game.\n", n);
	printf("\nHow many slots would you like: ");
	scanf("%u", &s);
	/* Loops if s is outside range of slots (1-20) or not enough for players */
	while(s<1 || s>SLOT_MAX || s<n)
	{
		puts("That number of slots is invalid. Please enter a valid number of slots.");
		scanf("%u", &s);
	}
	
	/* Pointers to slot and player structs */
	struct player_type *player;
	struct slot_type *slot;
	int *a;				// pointer a is used for randomizing slots, b is used for player moves
	/* calloc was needed to dynamically allocate memory and initialize it to 0 (or 0.0 if floating point) */
	a = calloc(s,sizeof(int));
	player = calloc(n,sizeof(struct player_type));
	slot = calloc(s,sizeof(struct slot_type));

	/* ---User input of player name and type--- */
	puts("\nA players name can have a maximum length of 19 characters.");
	puts("There are 4 types of player: Elf, Human, Ogre and Wizard.");	//Giving information to user on the possible types of player_type and name specs.
	for(i=0; i<n; i++){
		printf("\nEnter Player %d's name: ", i+1);
		scanf("%19s", player[i].name);	//Ensuring the maximum of characters of name is at most 19 so that there is one space for the null terminator.
		printf("\n----------Enter Player %d's type---------\n", i+1);
		printf("1 - Elf, 2 - Human, 3 - Ogre, 4 - Wizard:\n");
		scanf("%d", &typeNum);		// User input for player type
		while(typeNum < 1 || typeNum > 4){	// Loops while entered digit is not 1-4
			puts("Sorry but you must enter a number between 1 & 4:\n");
			scanf("%d", &typeNum);
		}
		player[i].lifepoints = 100.0;		// Sets everybody's LP's too 100.0 as stated
											// Must be floating point for attack calculations
		/* Switch that copies player's type and respective capabilities to each struct member */
		switch(typeNum){
			case 1:
				strcpy(player[i].type, "Elf");
				elf(&player[i]);		// Elf function (see playerTypes.c)
				break;

			case 2:
				strcpy(player[i].type, "Human");
				human(&player[i]);		// Human function (see playerTypes.c)
				break;
			case 3:
				strcpy(player[i].type, "Ogre");
				ogre(&player[i]);		// Ogre function (see playerTypes.c)
				break;
			case 4:
				strcpy(player[i].type, "Wizard");
				wizard(&player[i]);		// Wizard function (see playerTypes.c)
				break;
		}
	}
	slotnum(s, a);		// Function that shuffles array a to place players on random slots (see slotFunctions.c)
	/* Randomly assigns slot type to each slot */
	for(i=0; i<s; i++){
		x = rand() % 3 + 1;
		slot[i].numb = x;
		slotname(&slot[i], x);	// Function that names slots (see slotFunctions.c)
		slot[i].numb = a[i];	// Assigns random value stored in a[] for allocation of player to slot
		slot[i].taken = 0;
	}
	for(i=0; i<n; i++){
		player[i].slot = slot[i].numb;
		y = player[i].slot;
		strcpy(slot[y-1].occupant, player[i].name);
		moveslot(player, &(slot[y-1]), i);	// Function that assigns player to slot (see slotFunctions.c)
	}

	printPlayersStatus(player, n);			// Function to print each players details and location (see printPLayerStatus.c)
	printf("\n");
	/* Prints slots */
	for(i=0;i<s;i++){
		printf("Slot: %-2d - type: %-12s - Taken: %d - Occupant: %s\n", i+1, slot[i].type, slot[i].taken, slot[i].occupant);
	}

	/* Code to ask user what move they would like to make i.e. move slot or attack */
	playerTurn(player, slot, n, s);

	// Prints players name, type and lifepoints after all turns have been taken
	printf("\nName                (Type, Lifepoints)\n");
	puts("--------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%-19s (%s, %0.1f)\n",player[i].name,player[i].type,player[i].lifepoints);
	}


	/* free memory previously allocated with calloc */
	free(a);
	free(player);
	free(slot);
	return (0);	
	}

