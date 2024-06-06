/*
本段代码将通过C语言实现将一段不确定个数的字符通过图形横排写出
*/
#include<stdio.h>
char A[4];
void printE(int k)
{
	printf("\033[%dC",k*11);
	printf("*******\n"); printf("\033[%dC",k*11);
	printf("*      \n"); printf("\033[%dC",k*11);
	printf("*      \n"); printf("\033[%dC",k*11);
	printf("*******\n"); printf("\033[%dC",k*11);
	printf("*      \n"); printf("\033[%dC",k*11);
	printf("*      \n"); printf("\033[%dC",k*11);
	printf("*******\n"); printf("\033[%dC",k*11);
	printf("\n");
}
void printT(int k)
{
	printf("\033[%dC",k*11);
	printf("*********\n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("    *    \n"); printf("\033[%dC",k*11);
	printf("\n");
}
void printH(int k)
{
	printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("*******\n"); printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("*     *\n"); printf("\033[%dC",k*11);
	printf("\n");
}

int main()
{
	for(int j=0;j<4;j++)
	{
		printf("Letter%d=",j+1);
		scanf("%c",&A[j]);
		while(A[j]=='\n')
		{
			scanf("%c",&A[j]);
		}
	}
	//接收用户输入的字符
	for(int k=0;k<4;k++)
	{
		if(0!=k)
		{
			printf("\033[8A");
		}
		//如果不是第一个字符，则将光标移动，使前后字母齐平
		switch(A[k])
		{
		case 'E':
			printE(k);
			break;
		case 'T':
			printT(k);
			break;
		case 'H':
			printH(k);
			break;
		}
		//根据用户输入的字符选择性打印
	}
	return 0;
}