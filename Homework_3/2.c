/*
这段代码将通过C语言实现char型二维数组的排序，使得数组的每一行根据ASCLL码的值由小到大依次排列，每一行的字符根据
ASCLL码值的大小由左向右依次排列
*/
#include<stdio.h>
char A[5][6]={{'S','D','U','Y','E','S'},{'C','N','I','N','A','!'},{'A','F','T','E','R','X'},{'h','e','r','o','a','b'},{'C','y','y','D','S','!'}};
int a=0,b=0;
int B[5];
char change[6];
int main()
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			a=(int)A[i][j];
			B[i]=B[i]+a; 
			//用一维数组B[i]存放数组A的每一行的ASCLL码的值
		}
	}

	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(B[i]>B[j])
			{
				for(int k=0;k<6;k++)
				{
					change[k]=A[i][k];
					A[i][k]=A[j][k];
					A[j][k]=change[k];
					//通过交换二维数组每一行的每一个字符来实现行与行之间的交换
				}
			}
		}
	}

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=j+1;k<6;k++)
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
		//通过选择排序法实现每一行中字符之间的交换
	}


	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			printf("%c",A[i][j]);
			if(j==5)
			{
				printf("\n");
			}
		}
	}
	//打印出整个数组
		return 0;
}