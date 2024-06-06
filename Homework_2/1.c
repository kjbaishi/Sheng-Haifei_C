/*
本段C语言代码将计算int、char、float、double四种形式的变量所占的字节数，并进行输出
*/
#include<stdio.h>
int main(){
    int a = sizeof(int);
    int b = sizeof(char);
    int c = sizeof(float);
    int d = sizeof(double); //计算字节数
    printf("The size of int is %d bytes\n", a);
    printf("The size of char is %d bytes\n", b);
    printf("The size of float is %d bytes\n", c);
    printf("The size of double is %d bytes\n", d); //输出
    return 0;
}