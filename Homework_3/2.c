#include<stdio.h>
char A[5][6]={{'S','D','U','Y','E','S'},{'C','N','I','N','A','!'},{'A','F','T','E','R','X'},{'h','e','r','o','a','b'},{'C','y','y','D','S','!'}};
int i,j,k;
int a=0,b=0;
int B[5];
char change[6];
int main()
{
	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			a=(int)A[i][j];
			B[i]=B[i]+a;
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			if(B[i]>B[j])
			{
				for(k=0;k<6;k++)
				{
					change[k]=A[i][k];
					A[i][k]=A[j][k];
					A[j][k]=change[k];
				}
			}
		}
	}

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=j+1;k<6;k++)
			{
				a=(int)A[i][j];
				b=(int)A[i][k];
				if(a>b)
				{
				change[j]=A[i][j];
				A[i][j]=A[i][k];
				A[i][k]=change[j];
				}
			}
		}
	}


	for(i=0;i<5;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%c",A[i][j]);
			if(j==5)
			{
				printf("\n");
			}
		}
	}
		return 0;
}