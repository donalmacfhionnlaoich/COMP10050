#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct players {
	char name[20];
	char type[20];
	int lifepoints;
	int smartness;
	int strength;
	int magicskills;
	int luck;
	int dexterity;
};

struct slots {
	char type[20];
	int numb;
};

void human(struct players *player);
void ogre(struct players *player);
void wizard(struct players *player);
void elf(struct players *player);
void slotnum(int x, int a[]);

int main(void){
	
	srand(time(NULL));
	
	int i, x;
	unsigned int n, s;
	
	char type1[10] = "uman";
	char type2[10] = "gre";
	char type3[10] = "izard";
	char type4[10] = "lf";
	
	printf("How many players are there: ");
	scanf("%u", &n);
	
	printf("\nHow many slots would you like: ");
	scanf("%u", &s);
	
	int *a[s];
	
	struct players player[n];
	struct slots slot[s];
	
	if((n <= 6 && s <= 20) && (n <= s)){
		for(i=0; i<n; ++i){
			printf("\nEnter Player %d's name: ", i+1);
			scanf("%s", player[i].name);
			printf("\nEnter Player %d's type: ", i+1);
			scanf("%s", player[i].type);
			player[i].lifepoints = 100;
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
		printf("\n-SLOTS-\n");
		for(i=0; i<s; ++i){
			x = rand() % 3 + 1;
			slot[i].numb = x;
			if(x == 1){
				strcpy(slot[i].type,"Level Ground");
			}
			else if(x == 2){
				strcpy(slot[i].type, "Hill");
			}
			else if(x == 3){
				strcpy(slot[i].type, "City");
			}
			slotnum(s, *a);
			printf("Slot %d - type: %s\n", i+1, slot[i].type);
			printf("%d", *a[i]);
		}
		for(i=0; i<n; ++i){
			printf("\n-PLAYER %d-\n", i+1); 
			printf("Name:\t\t%s\n", player[i].name);
			printf("Type:\t\t%s\n", player[i].type);
			printf("Life Points:\t%d\n", player[i].lifepoints);
			printf("Smartness:\t%d\n", player[i].smartness);
			printf("Strength:\t%d\n", player[i].strength);
			printf("Magic Skills:\t%d\n", player[i].magicskills);
			printf("Luck:\t\t%d\n", player[i].luck);
			printf("Dexterity:\t%d\n", player[i].dexterity);
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
	player->strength = rand() % 20 + 80;
	player->dexterity = rand() % 20 + 80;
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
	player->magicskills = rand() % 31 + 50;
}
void slotnum(int x, int *a){
	int i, j;
	for(i=x; i>x-1; --i){
		j = rand() % (i+1);
		a[i] = j;
	}
	
}
	
	
	
	
	