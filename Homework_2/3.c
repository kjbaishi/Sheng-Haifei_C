/*
本段C语言代码将接收用户输入的字符'I''L'或'F'，并将其以*构成的图像输出
*/
#include<stdio.h>
void printI(){
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
    printf("**\n");
}

void printL(){
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("******\n");
}

void printF(){
    printf("******\n");
    printf("*\n");
    printf("*\n");
    printf("******\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
}

int main(){
    char ch;
    printf("Input a word:");
    scanf("%c", &ch); //接收用户输入
    switch(ch){
        case'I':
        printI();
        break;
        case'L':
        printL();
        break;
        case'F':
        printF();
        break;
        default:
        printf("You must input 'I' 'L' or 'F'\n"); //告知用户只能输入'I''L'或'F'
    }
    return 0;
}