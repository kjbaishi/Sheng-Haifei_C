/*
本段C语言代码将接收用户输入的数字，并判断是否是质数，是则输出"Yes"，否则输出"No"
*/
#include<stdio.h>
int main(){
    int number,factor;
    printf("Input a number:");
    scanf("%d", &number); //接收用户输入的数字
    for (int i = 1,factor = 0; i < number; i++) //遍历1-(number-1)的所有数组
    {
        if (0 == number % i)
        factor++; //若i是number的因数，则因数数量factor加一
    }
    if (1 == factor)
    printf("Yes\n"); //如果只有1一个因数，说明是质数
    else
    printf("No\n"); //如果存在除了1以外的因数，则不是质数
    return 0;
}