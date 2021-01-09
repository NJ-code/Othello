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
			
			while(M[I][J]==Case && J>=0 && J <8){
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
int modifietableau(int i, int j)
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
		printf("vous avez choisi une case impossile!!!\n Rentrez une deuxieme fois\n");
	}
	return imp;
}
void entourage_turn(int i, int j)
{
	for(int I=i-1;I<i+2;I++)
	{
		for(int J=j-1;J<j+2;J++)
		{
			if(turn%2!=0)
			{
				if((I!=i || J!=j) && M[I][J]=='W' && 0<=I && I<=7 && 0<=J && J<=7)
				{
					printf("entre dans condition entourage\n");
					turn_token(i,I,j,J,M[I][J]);
				}
			}
			else if(turn%2==0)
			{
				if((I!=i || J!=j) && M[I][J]=='B' && 0<=I && I<=7 && 0<=J && J<=7)
				{
					turn_token(i,I,j,J,M[I][J]);
				}
			}
		}
	}
}
void turn_token(int i,int I,int j,int J, char Case)
{
	if(i==I)
	{
		if(J<j)
		{
			printf("entre J<j\n");
			while(Case==M[I][J] && J>=0)
			{
				J--;
			}
			if(M[I][J]==M[i][j])
			{
				for(int k=J; k<j;k++)
				{
					M[I][k]=M[i][j];
				}
			}
		}
		else if(J>j)
		{ printf("entre J>j\n");
			while(Case==M[I][J] && J<8)
			{
				J++;
			}
			if(M[I][J]==M[i][j])
			{
				for(int k=j; k<J;k++)
				{
					M[I][k]=M[i][j];
				}
			}
		}
	}
	else if(I>i)
	{
		if(J==j)
		{printf("entre I>i j==J\n");
			while(Case==M[I][J] && I<8)
			{
				I++;
			}
			if(M[I][J]==M[i][j])
			{
				printf("%c\n",M[I][J]);
				for(int k=i; k<I;k++)
				{
					M[k][J]=M[i][j];
				}
			}
		}
		else if(J>j)
		{printf("I>i J>j\n");
			while(Case==M[I][J] && I<8 && J<8)
			{
				I++;
				J++;
			}
			if(M[I][J]==M[i][j])
			{
				for(int l=i;l<I;l++)
				{
					for(int c=j; c<J; c++)
					{
						M[l][c]=M[i][j];
					}
				}
			}
		}
		else if(J<j)
		{printf("entre J<j I>i\n");
			while(Case==M[I][J] && I>=0 && J>=0)
			{
				I++;
				J--;
			}
			if(M[I][J]==M[i][j])
			{
				for(int l=i;l<I;l++)
				{
					for(int c=J; c<j; c++)
					{
						M[l][c]=M[i][j];
					}
				}
			}
		}
	}
	else if(I<i)
	{
		if(J==j)
		{printf("entre J==j I<i\n");
			while(Case==M[I][J] && I>=0)
			{
				I--;
			}
			if(M[I][J]==M[i][j])
			{
				for(int k=I; k<i;k++)
				{
					M[k][J]=M[i][j];
				}
			}
		}
		else if(J<j)
		{printf("entre J<j I<i\n");
			while(Case==M[I][J] && I>=0 && J>=0)
			{
				I--;
				J--;
			}
			if(M[I][J]==M[i][j])
			{
				for(int l=I;l<i;l++)
				{
					for(int c=J; c<j; c++)
					{
						M[l][c]=M[i][j];
					}
				}
			}
		}
		else if(J>j)
		{printf("entre J>j I<i\n");
			while(Case==M[I][J] && I>=0 && J>=0)
			{
				I--;
				J++;
			}
			if(M[I][J]==M[i][j])
			{
				for(int l=I;l<i;l++)
				{
					for(int c=j; c<J; c++)
					{
						M[l][c]=M[i][j];
					}
				}
			}
		}

	}
}
