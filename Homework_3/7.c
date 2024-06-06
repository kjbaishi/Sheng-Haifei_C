/*
这段C语言代码将通过补全函数，实现矩阵之间的乘法，补全代码如下：
*/
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
				//矩阵c的第i行第j列的值 = 矩阵A的第i行的每个元素 × 矩阵B的第j列的每个元素(一一对应相乘)
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
	
	matrix_multi(A,B,C);//调用函数
	
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
	//通过两个for循环将矩阵C的每一个元素打印出来
	return 0;
}