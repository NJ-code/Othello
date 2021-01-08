#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "variables.h"
extern _position *listePosition;
extern _position position;
extern int turn;
extern int NbCase;
char M[8][8];
void Parcours()
{
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			//printf("%c\n",M[i][j]);
			char Case=M[i][j];
			if(M[i][j]=='*')
				continue;
			else
			{
				if(turn%2==0)
				{
					switch(Case)
					{	
						case 'B':
						{
							//printf("%d %d\n",i,j);
							entourage(i,j);
							break;
						}
						case 'W':
							break;
					}
				}
				else if(turn%2!=0)
				{
					switch(Case)
					{
						case 'B':
						{
							break;
						}
						case 'W':
							entourage(i,j);
							break;
					}
				}
			}
		}

	}
}
void entourage(int i, int j)
{
	for(int I=i-1;I<i+2;I++)
	{
		for(int J=j-1;J<j+2;J++)
		{
			if(turn%2==0)
			{
				if((I!=i || J!=j) && M[I][J]=='W' && 0<=I && I<=7 && 0<=J && J<=7)
				{
					possiblecases(i,j,I,J,M[I][J]);
				}
			}
			else if(turn%2!=0)
			{
				if((I!=i || J!=j) && M[I][J]=='B' && 0<=I && I<=7 && 0<=J && J<=7)
				{
					possiblecases(i,j,I,J,M[I][J]);
				}
			}
		}
	}
}
void possiblecases(int i, int j, int I, int J, char Case)
{
	if(i==I){
		if(j>J){
			while(M[I][J]==Case && J>=0){
				J--;		
			}
			//printf("%d %d\n",I,J );
			position.Line=I;
			position.Culum=J;
	        listePosition[NbCase] = position;
			printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);

			NbCase++;
		}
		else if(j<J){
			
			while(M[I][J]==Case && J>=0 && J <8){
				J++;		
			}
			//printf("%d %d\n",I,J);
			position.Line=I;
			position.Culum=J;
			//printf("%d %d possiblecases\n",position.Line,position.Culum);
			listePosition[NbCase] = position;
			printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
			NbCase++;
		}
	}
	else if(i>I)
	{
		if(j>J)
		{
			while(M[I][J]==Case && J>=0 && J <8 && I>=0 && I<8)
			{
				I--;		
				J--;
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);

				NbCase++;
			}
		}
		else if(j==J)
		{
			while(M[I][J]==Case && J>=0 && J <8 && I>=0 && I<8)
			{
				I--;		
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
				NbCase++;
			}
		}
		else if(j<J)
		{
			while(M[I][J]==Case && J>=0 && J <8 && I>=0 && I<8)
			{
				I--;		
				J++;
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
				NbCase++;
			}
		}
	}
	else if(i<I)
	{
		if(j>J)
		{
			while(M[I][J]==Case && J>=0 && J <8 && I>=0 && I<8)
			{
				I++;		
				J--;
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
				NbCase++;
			}
		}
		else if(j==J)
		{
			while(M[I][J]==Case && J>=0 && J<8 && I>=0 && I<8)
			{
				I++;		
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
				NbCase++;
			}
		}
		else if(j<J){
			while(M[I][J]==Case && J>=0 && J <8 && I>=0 && I<8)
			{
				I++;		
				J++;
			}
			if(M[I][J]=='*')
			{
				position.Line=I;
				position.Culum=J;
				listePosition[NbCase] = position;
				printf("%d %d possiblecases \n",listePosition[NbCase].Line,listePosition[NbCase].Culum);
				NbCase++;
			}
		}
	}
}
void modifietableau(int i, int j)
{
	int imp=1;
	//printf("entrer modifie\n");
	for (int k=0;k<NbCase;k++)
	{
		//printf("%d %d\n",listePosition[k].Line, listePosition[k].Culum);
		if(i==listePosition[k].Line && j==listePosition[k].Culum)
		{
			if(turn % 2==0)
			{
				M[i][j]='B';
				turn++;
				imp=0;
				//turn();
			}
			else
			{
				M[i][j]='W';
				turn++;
				imp=0;
				//turn();
			}

		}
	}
	if(imp)
	{
		printf("vous avez choisi une case impossile!!!\n Reentrez une deuxieme fois\n");
	}
}
