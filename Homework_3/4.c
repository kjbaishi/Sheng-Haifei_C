#include<stdio.h>
char A[4];
int i;
int j;
int k;
void printE()
{
	printf("*******\n");
	printf("*\n");
	printf("*\n");
	printf("*******\n");
	printf("*\n");
	printf("*\n");
	printf("*******\n");
	printf("\n");
}
void printT()
{
	printf("*********\n");
	printf("    *    \n");
	printf("    *    \n");
	printf("    *    \n");
	printf("    *    \n");
	printf("    *    \n");
	printf("    *    \n");
	printf("\n");
}
void printH()
{
	printf("*     *\n");
	printf("*     *\n");
	printf("*     *\n");
	printf("*******\n");
	printf("*     *\n");
	printf("*     *\n");
	printf("*     *\n");
	printf("\n");
}

int main()
{
	for(j=0;j<4;j++)
	{
		printf("Letter%d=",j+1);
		scanf("%c",&A[j]);
		while(A[j]=='\n')
		{
			scanf("%c",&A[j]);
		}
	}
	for(k=0;k<4;k++)
	{
		switch(A[k])
		{
		case 'E':
			printE();
			break;
		case 'T':
			printT();
			break;
		case 'H':
			printH();
			break;
		}		
	}
	return 0;
}