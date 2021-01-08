#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "variables.h"
_position position;
int turn=1;
int NbCase=0;
_position *listePosition=NULL;
main()
{
	int ligne, colone;
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
			printf("Entrez la colone de la case choisie: ");
			scanf("%d",&colone);
			Parcours();
			printf("finish parcours\n");
			modifietableau(ligne,colone);
			listePosition=NULL;
			NbCase=0;
			//round=0;
		}
	}
	game=0;
	
}