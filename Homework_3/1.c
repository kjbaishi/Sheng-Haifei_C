/*
这段代码将通过C语言实现非递归版本的一维数组的选择排序算法和冒泡排序算法
*/
#include<stdio.h>
int A[5];
int change;
int main()
{
	for(int i=0;i<5;i++)
	{
		printf("A[%d]=",i);
		scanf("%d",&A[i]);
	}
//选择排序法
//============================================================
    for(int x=0;x<5;x++)//第一个for循环实现初始位置从1→5的选择
    {
		for(int y=x+1;y<5;y++)////第二个for循环实现A[x]与之后数的选择排序
		{
			if(A[x]>A[y])
			{
			    change=A[x];
			    A[x]=A[y];
			    A[y]=change;
			}
		}
	}
//============================================================

//冒泡排序法
//============================================================
	for(int x=0;x<5;x++)//第一个for循环实现初始位置从5→1的选择
	{
		for(int y=4;y>x;y--)//第二个for循环实现向前的冒泡排序
		{
			if(A[y]<A[y-1])
			{
				change=A[y];
				A[y]=A[y-1];
				A[y-1]=change;
			}
		}
	}
//============================================================
	printf("A[5]={%d,%d,%d,%d,%d}\n",A[0],A[1],A[2],A[3],A[4]);
	return 0;
}