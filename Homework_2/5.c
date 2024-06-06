/*
本段C语言代码将接收用户输入的数字，输出小于等于这个数的所有质数
*/
#include<stdio.h>
int mian(){
    int number,factor;
    printf("Input a number:");
    scanf("%d", &number); //接收用户输入的数字
    for (int i = 2; i <= number; i++) //i代指小于number的数
    {
        for (int j = 1,factor = 0; j < i; j++)
        {
            if (0 == i % j)
            factor++; //计算i的因数个数
        }
        if (1 == factor)
        printf("%d", i); //因数个数是1则是质数，打印
    }
    return 0;
}