#include<stdio.h>
void matrix_multi(double A[3][4],double B[4][5],double C[3][5])
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<4;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
}
int main()
{
	int i,j;
	double A[3][4]={{1,2,3,4},{2,3,1,4},{2,4,1,3}};
	double B[4][5]={{5,4,1,3,2},{2,3,1,4,5},{1,2,3,5,4},{3,1,4,2,5}};
	double C[3][5];
	
	matrix_multi(A,B,C);
	
	printf("C[3][5]=\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%f",C[i][j]);
			if(j==4)
			{
				printf("\n");
			}
		}
	}
	return 0;
}