#include<stdio.h>
int A[5];
int i;
int x;
int y;
int change;
int main()
{
	for(i=0;i<5;i++)
	{
		printf("A[%d]=",i);
		scanf("%d",&A[i]);
	}
////////////////////////////////////////////////////
//	for(x=0;x<5;x++)
//	{
//		for(y=x+1;y<5;y++)
//		{
//			if(A[x]>A[y])
//			{
//				change=A[x];
//				A[x]=A[y];
//				A[y]=change;
//			}
//		}
//	}
///////////////////////////////////////////////////
	for(x=0;x<5;x++)
	{
		for(y=4;y>x;y--)
		{
			if(A[y]<A[y-1])
			{
				change=A[y];
				A[y]=A[y-1];
				A[y-1]=change;
			}
		}
	}
//////////////////////////////////////////////////
	printf("A[5]={%d,%d,%d,%d,%d}\n",A[0],A[1],A[2],A[3],A[4]);
	return 0;
}