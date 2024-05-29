#include<stdio.h>
int A[2][2]={{11,12},{21,22}};
int main()
{
	printf("A[1][1]=%d\n",A[1][1]);
	printf("A[1][0]=%d\n",A[1][0]);
	A[0][2]=0;
	printf("A[1][1]=%d\n",A[1][1]);
	printf("A[1][0]=%d\n",A[1][0]);
	return 0;
}