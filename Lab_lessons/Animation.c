#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int A[8][2];
int Down=0,Right=0;
//和豆子相关的坐标变量是大写的Down和Right，而和吃豆人相关的则是小写的down和right

void Print_man(int Down,int Right,int down,int right) //打印出吃豆人
{
    printf("\033[33m");
    printf("\033[%dA",Down+10);
    printf("\033[%dB",down);
    //使吃豆人变色且初始位置移动到屏幕左上角
    printf("\033[%dC",right*2);
    printf("            ######          \n"); printf("\033[%dC",right*2);
    printf("        ####      ####      \n"); printf("\033[%dC",right*2);
    printf("      ##              ##    \n"); printf("\033[%dC",right*2);
    printf("    ##        $$        ##  \n"); printf("\033[%dC",right*2);
    printf("  ##                      ##\n"); printf("\033[%dC",right*2);
    printf("  ##                  ####  \n"); printf("\033[%dC",right*2);
    printf("##              ######      \n"); printf("\033[%dC",right*2);
    printf("##          ####            \n"); printf("\033[%dC",right*2);
    printf("##              ######      \n"); printf("\033[%dC",right*2);
    printf("  ##                  ####  \n"); printf("\033[%dC",right*2);
    printf("  ##                      ##\n"); printf("\033[%dC",right*2);
    printf("    ##                  ##  \n"); printf("\033[%dC",right*2);
    printf("      ##              ##    \n"); printf("\033[%dC",right*2);
    printf("        ####======####      \n");
} 

void Print_been(int Down,int Right) //打印出绿色的豆子
{
    printf("\033[32m");
    printf("\033[%dB",Down+6);
    printf("\033[%dC",Right*2+12);
    printf("$$$$$$\n");
    printf("\033[%dC",Right*2+12);
    printf("$$$$$$\n");
    printf("\033[%dC",Right*2+12);
    printf("$$$$$$\n");
}

void Flash()
{
    int right=0,down=0;
    for(int i=0;i<=7;i++)
    {
        system("clear");
        Print_been(Down,Right); //根据用户指定的坐标打印出绿色的豆子
        down+=A[i][0];
        right+=A[i][1];
        Print_man(Down,Right,down,right); //根据用户输入的指令打印和移动出吃豆人
        sleep(1);
    }
}

void Input_command() //接收用户的指令，豆子的坐标以及吃豆人每次移动的坐标
{
    while(0==Down && 0==Right)
    {
        printf("The been's Down Right=");
        scanf("%d %d",&Down,&Right);
        if(0>=Down||0>=Right)
        {
            printf("The number of 'Down' and 'Right' must larger than zero\n");
            Down=0;  Right=0;
        }
    }
    for(int i=0;i<=7;i++)
    {
        printf("The man's Down Right=");
        scanf("%d %d",&A[i][0],&A[i][1]);
        if(0>A[i][0]||0>A[i][1])
        {
            printf("The number of 'Down' and 'Right' can't small than zero\n");
            i--;
            continue;
        }
    }
}

int main()
{
    Input_command();
    Flash();
    return 0;
}