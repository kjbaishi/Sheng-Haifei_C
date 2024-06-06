/*
这段C语言代码将实现如下功能：
1.从用户处接收多行英文字符串
2.统计用户所输入的单词，打印该单词在每一行出现的次数以及出现的总次数
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *A[100];
char *B[100];

int Input()
{
    int i=0;
    int j,k;
    while(1)
    {
        A[i]=(char *)malloc(sizeof(char)*25); //为A开辟内存空间
        fgets(A[i],25,stdin);                 //接收用户输入
        if(0==strcmp(A[i],"End\n"))
        {
            for (int j = i; j < 100; j++)
            {
                free(A[j]);
            }
            break;                            //如果用户输入End，则释放多余内存空间并结束循环
        }
        i++;
    }
    return i;
}

int main()
{
    int i,j,k;
    int a=0;
    int line_number;
    int word_number;
    line_number=Input();
    for(i=0;i<line_number;i++)
    {
        for(j=a;j<100;j++)
        {
            if(0==j)
            {
                B[j]=strtok(A[i],"' '',''.''?'';''!'':'\n");
            }
            else
            {
                B[j]=strtok(NULL,"' '',''.''?'';''!'':'\n"); //将每一个单词依次存入B中
            }
            if(NULL==B[j])
            {
                a=j;
                break;
            }
        }
    }
    for(i=0;i<100;i++)
    {
        word_number=0;         
        char* word=B[i]; //令指针word指向B的第i-1个单词
        if(NULL==word||' '==*word)
        {
            break;
        }
        for(j=0;j<100;j++)
        {
            if(strcmp(word,B[j])==0)
            {
                word_number++; //如果word指向的单词和B[j]中的单词相等，单词数+1
            }
        }
        printf("The number of %s is %d\n",word,word_number);
    }
    return 0;
}