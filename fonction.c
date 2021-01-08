#include <stdio.h>
#include <stdlib.h>
//#include "variables.h"
extern char M[8][8];
void initfill()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0; j<8; j++)
		{
			M[i][j]='*';
		}
	}
	M[3][4]='W';
	M[4][3]='W';
	M[3][3]='B';
	M[4][4]='B';
	
}
void draw()
{
	printf("\t\t\t      _________________________________\n");
    for(int i = 0;i<8;i++)
    {
        printf("\t\t\t[%d]   | %c | %c | %c | %c | %c | %c | %c | %c |\n",i,M[i][0],M[i][1],M[i][2],M[i][3],M[i][4],M[i][5],M[i][6],M[i][7]);
		printf("\t\t\t      ---------------------------------\n");
    }
    	printf("\n\t\t\t       [0] [1] [2] [3] [4] [5] [6] [7]\n");
}
