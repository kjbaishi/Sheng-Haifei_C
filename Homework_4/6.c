/*
这段C语言代码将探究函数'char f(char *pp[5])'的返回值
*/
#include<stdio.h>
char f(char *pp[5])
{
    return pp[1][2];
}

int main()
{
    char *B[20];
    char a;
    B[1]="ABCDE";//为指针数组B的第二个指针所指的字符(串)进行赋值，方便后续通过printf探究函数'f'的返回值
    a=f(B);      //将函数'f'的返回值赋值给a
    printf("%c\n",a);
    return 0;
}