#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct players {
	char name[20];
	char type[20];
	char currentSlot[20];
	float lifepoints;
	int smartness;
	int strength;
	int magicskills;
	int luck;
	int dexterity;
	int slot;
};

struct slots {
	char type[20];
	int numb;
	int taken;
};

void human(struct players *player);
void ogre(struct players *player);
void wizard(struct players *player);
void elf(struct players *player);
void slotnum(int x, int *a);
void slotname(struct slots *slot, int x);

void city(struct players *player);
void hill(struct players *player);
void moveslot(struct players *player, struct slots *slot, int i);
void attack(struct players *attacker, struct players *attacked);
void playerAction(int y, int b,struct players player[6],struct slots slot[20],int i,int n);

int main(void){
	
	srand(time(NULL));
	
	int i, j, x, y;
	unsigned int n, s;
	
	char type1[10] = "uman";
	char type2[10] = "gre";
	char type3[10] = "izard";
	char type4[10] = "lf";
	char name1[10] = "City";
	char name2[10] = "Hill";
	
	printf("How many players are there: ");
	scanf("%u", &n);
	
	printf("\nHow many slots would you like: ");
	scanf("%u", &s);
	
	int *a, b;
	a = malloc(s*sizeof(int));
	
	struct players player[n];
	struct slots slot[s];
	
	puts("\nA players name can have a maximum of 19 characters.");
	puts("There are 4 types of players: Elf, Human, Ogre and Wizard.");	//Giving information to user on the possible types of players and name specs.
	if((n <= 6 && s <= 20) && (n <= s)){
		for(i=0; i<n; ++i){
			printf("\nEnter Player %d's name: ", i+1);
			scanf("%19s", player[i].name);	//Ensuring the maximum of characters of name is at most 19 so that there is one space for the null terminator.
			printf("\nEnter Player %d's type: ", i+1);
			scanf("%s", player[i].type);
			player[i].lifepoints = 100.0;
		}
		for(i=0; i<n; ++i){
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
		for(i=0; i<s; ++i){
			x = rand() % 3 + 1;
			slot[i].numb = x;
			slotname(&slot[i], x);
			slot[i].numb = a[i];
			slot[i].taken = 0;
		}
		for(i=0; i<n; ++i){
			player[i].slot = slot[i].numb;
			y = player[i].slot;
			moveslot(&player[i], &slot[y-1], i);	
		}
		for(i=0; i<n; ++i){
			printf("\n-PLAYER %d-\n", i+1); 
			printf("Name:\t\t%s\n", player[i].name);
			printf("Type:\t\t%s\n", player[i].type);
			printf("Life Points:\t%.1f\n", player[i].lifepoints);
			printf("Smartness:\t%d\n", player[i].smartness);
			printf("Strength:\t%d\n", player[i].strength);
			printf("Magic Skills:\t%d\n", player[i].magicskills);
			printf("Luck:\t\t%d\n", player[i].luck);
			printf("Dexterity:\t%d\n", player[i].dexterity);
			printf("Location:\tSlot %d\n", player[i].slot);
			printf("Slot Name:\t%s\n", player[i].currentSlot);
		}
		printf("\n");
		for(i=0;i<s;++i){
			printf("Slot: %d - \ttype: %-12s - \tTaken:%d\n", i+1, slot[i].type, slot[i].taken); //Replaced free with taken as it was representing the opposite of the values presented.
		}
		// Down to line 192 is statements for asking each player what move they would 
		// like and stores 1 for forward moves or 0 for backwards in array b[n]
		
		for(i=0; i<n; ++i){
			y = player[i].slot;
			printf("\nPlayer %d - %s is on a %s slot\n", i+1, player[i].name,  player[i].currentSlot);
			if((y != 1) && (y != s)) {
				if(slot[y-2].taken == 0 && slot[y].taken == 0 ){
					printf("Would you like to move to the next or the previous slot?\n");
					printf("Press 1 for forward move or 0 for backward move\n");
					while(b!=0 && b!=1)
					{
						puts("That was not a valid option. Please enter a valid option.");
						scanf("%d",&b);
					}
					playerAction(y ,b ,player ,slot ,i ,n);
				}
				else if(slot[y-2].taken == 0 && slot[y].taken == 1 ){
					printf("Would you like to move forwards and attack or backward to the previous slot?\n");
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
					printf("Would you like to move forwards to the next slot or backward and attack?\n");
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
					printf("Would you like to move forwards and attack or backward and attack?\n");
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
		/*for(i=0;i<n;++i){
			y = player[i].slot;
			if(b[i] == 0){
				moveslot(&player[i], &slot[y-2], i);
				slot[y-1].taken = 0;
				player[i].slot -= 1;
			}
			
			else if(b[i] == 1){
				moveslot(&player[i], &slot[y], i);
				slot[y-1].taken = 0;
				player[i].slot += 1;
			}
			else if(b[i] == 3){
				for(j=0;j<n;++j){
					x = player[j].slot;
					if(x == (y + 1)){
						attack(&player[i], &player[j]);
					}
					
				}
				
			}
			else if(b[i] == 4){
				for(j=0;j<n;++j){
					x = player[j].slot;
					if(x == (y - 1)){
						attack(&player[i], &player[j]);
					}
					
				}
				
			}
		}*/
		printf("MOVE\n");
		for(i=0; i<n; ++i){
			printf("\n-PLAYER %d-\n", i+1); 
			printf("Name:\t\t%s\n", player[i].name);
			printf("Type:\t\t%s\n", player[i].type);
			printf("Life Points:\t%.1f\n", player[i].lifepoints);
			printf("Smartness:\t%d\n", player[i].smartness);
			printf("Strength:\t%d\n", player[i].strength);
			printf("Magic Skills:\t%d\n", player[i].magicskills);
			printf("Luck:\t\t%d\n", player[i].luck);
			printf("Dexterity:\t%d\n", player[i].dexterity);
			printf("Location:\tSlot %d\n", player[i].slot);
			printf("Slot Name:\t%s\n", player[i].currentSlot);
		}
	}
	else if(n > 6){
		printf("Sorry maximum number of players is 6!\n");
		exit(1);
	}
	else if(s > 20){
		printf("Sorry maximum number of slots is 20!\n");
		exit(1);
	}
	else{
		printf("Sorry but there needs to at least one slot per player\n");
		exit(1);
	}
	free(a);
	return (0);
	
}
void human(struct players *player){
	int attrib[5], sum=0, i;
	
	do{
		for(i=0; i<5; ++i){
			attrib[i] = rand() % 100 + 1;
			sum += attrib[i];
		}
	}
	while(sum >= 300);
	
	player->smartness = attrib[0];
	player->strength = attrib[1];
	player->magicskills = attrib[2];
	player->luck = attrib[3];
	player->dexterity = attrib[4];
}
void ogre(struct players *player){
	int attrib[2], sum=0, i;
		
	do{
		attrib[0] = rand() % 21;
		attrib[1] = rand() % 100 + 1;
		sum = attrib[1] + attrib[0];
	}
	while(sum > 50);
	
	player->smartness = attrib[0];
	player->luck = attrib[1];
	player->strength = rand() % 21 + 80;	//Max strength possible is 100.
	player->dexterity = rand() % 21 + 80;	//Max dexterity possible is 100.
	player->magicskills = 0;
}
void wizard(struct players *player){
		
	player->smartness = rand() % 11 + 90;
	player->luck = rand() % 51 + 50;
	player->strength = rand() % 21;
	player->dexterity = rand() % 100 + 1;
	player->magicskills = rand() % 21 + 80;
}
void elf(struct players *player){
		
	player->smartness = rand() % 31 + 70;
	player->luck = rand() % 41 + 60;
	player->strength = rand() % 51;
	player->dexterity = rand() % 100 + 1;
	player->magicskills = rand() % 29 + 51;	//Incremented 50 to 51 and changed rand ()% 31 to 29. (50<magic<80)
}
void slotnum(int x, int *a){
	int i, j, swap;
	
	for(i=0; i<x; ++i){
		a[i] = i+1;
	}
	for(i=x-1; i>1; --i){
		j = rand() % i;
		swap = a[j];
		a[j] = a[i];
		a[i] = swap;
	}
}
void slotname(struct slots *slot, int x){
	if(x == 1){
		strcpy(slot->type,"Level Ground");
	}
	else if(x == 2){
		strcpy(slot->type, "Hill");
	}
	else if(x == 3){
		strcpy(slot->type, "City");	
	}
	
}	
void city(struct players *player)
{	// I just added these while loops so as players will never exceed
	// 100 or go below 0
	if(player->smartness > 60){
		if(player->magicskills >= 89)
		{
			player->magicskills = 100;
		}
		else if(player->magicskills < 89)
		{
			player->magicskills += 10;
		}
	}
	else if(player->smartness <= 50){
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
void hill(struct players *player)
{
	if(player->dexterity >= 60){
		if(player->strength >= 89)
		{
			player->strength = 100;
		}
		else if(player->strength < 89)
		{
			player->strength += 10;
		}
	}
	else if(player->dexterity < 50){
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
void moveslot(struct players *player, struct slots *slot, int i){
	int y;
	char name1[10] = "City";
	char name2[10] = "Hill";
	
	slot->taken = 1;
	strcpy(player->currentSlot, slot->type);
	if(strstr(player->currentSlot, name1)!=NULL){
		city(&player[i]);
	}
	else if(strstr(player->currentSlot, name2)!=NULL){
		hill(&player[i]);
	}
}
void attack(struct players *attacker, struct players *attacked)
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

void playerAction(int y, int b,struct players player[6],struct slots slot[20],int i,int n)
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
		for(j=0;j<n;++j){
			x = player[j].slot;
			if(x == (y + 1)){
				attack(&player[i], &player[j]);
			}
		}
	}
	else if(b == 4){
		for(j=0;j<n;++j){
			x = player[j].slot;
			if(x == (y - 1)){
				attack(&player[i], &player[j]);
			}
			
		}
		
	}
}


	
	
