#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "variables.h"
_position position;
int turn=0;
int NbCase=0;
_position *listePosition=NULL;
int cas_possible;
main()
{
	int ligne, colonne;
	char nom1[20], nom2[20];
	int game=1, round=1;
	printf("Bienvenue\n");
	printf("Entrez le nom du premier joueur:\n");
	scanf("%s",nom1);
	printf("entrez le nom de deuxieme joueur:\n");
	scanf("%s",nom2);
	while(game==1)
	{
		initfill();
		while(round==1)
		{

			listePosition=(_position*)malloc(64*sizeof(_position));
			draw();		
			if(turn %2==0)
			{
				printf("c'est le tour de: %s\n",nom1);
			}
			else
			{
				printf("c'est le tour de: %s\n",nom2);
			}
			printf("Entrez la ligne de la case choisie: ");
			scanf("%d",&ligne);
			printf("Entrez la colonne de la case choisie: ");
			scanf("%d",&colonne);
			Parcours();
			cas_possible=modifietableau(ligne,colonne);
			if(cas_possible==0)
			{
				entourage_turn(ligne,colonne);
			}
			listePosition=NULL;
			NbCase=0;
			//round=0;
		}
	}
	game=0;
	
}