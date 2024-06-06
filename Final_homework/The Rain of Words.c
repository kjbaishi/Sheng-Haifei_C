/*
本段C语言代码将实现代码雨效果，以下是本段代码的实现思路：
1.用二维数组作为画布，第二维表示列，第一维表示行
2.每隔一段时间更改数组元素并打印数组
  对数组元素的更改遵循以下逻辑
  (1).每次更改使数组每一列元素整体向后移动一个单位，第一个元素改为随机字符或空格，最后一个元素被前一个替代
  (2).代码雨的输出以四行为一个周期进行以下操作
      ①.每个周期，每列各生成不同的随机整数t∈[0,9]
      ②.一个周期的四行即变量i从3到6，而当i<t时每列元素更新时第一个元素更新为空格，否则为随机字符
  (3).逻辑(2)使得当t=0,1,2,3时更新随机字符，其余情况更新为空格，形成下列效果(如右图)   @ @ @ @ @ @ @
      ①.有40%的可能(t∈[0,3])四行全为字符                                          @ @ @ @ @ @  
      ②.有30%的可能(t∈[4,6])依次缺失1,2,3个字符                                   @ @ @ @ @    
      ③.有30%的可能(t∈[7,9])四行全为空格                                          @ @ @ @       
  (4).如何使周期之间衔接更加自然? 凭借以下两点
      ①.上一周期的最后一行有字符，且下一个周期的第一行也有字符
      ②.上一周期整列全为空格，且下一个周期的第一行也是空格
*/
#include<stdlib.h>
#include<unistd.h>
#define column 100
#define row 30

char word[column][row];
int word_random_number[column];
char store[67]={'0','1','2','3','4','5','6','7','8','9','@','%','$','&','?','a','b','c','d','e',\
'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C',\
'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
//设定字符库
void Initialize()
{
    for (int i = 0; i < column; i++)
    {
        for (int j = row - 1; j >= 0 ; j--)
        {
            word[i][j] = ' '; //初始化棋盘(整个数组)为空格
        }
    }
    for (int i = 0; i < column; i++)
    {
        word_random_number[i] = 0; //每一列的随机数设置为0
    }
}

void Change(int number) //传递进参数i
{
    for (int i = 0; i < column; i+=4)
    {
        for (int j = row - 1; j >= 0; j--)
        {
            if (0 == j)
            {
                if (number < word_random_number[i])
                {
                    word[i][j] = ' '; //若传递进的参数i小于该列的随机数，则第一个元素为空格
                }
                else
                {
                    int k = rand();
                    k = k % 67;
                    word[i][j] = store[k]; //k为0-66的随机数，作为字符库的索引，因而生成的字符也随机
                }
            }
            else
            {
                word[i][j] = word[i][j-1]; //整列元素整体向后移动一个单位
            }
        }
    }
}

void Print() //打印整个数组
{
    printf("\033[32m");
    for (int j = 0; j < row; j++)
    {
        for (int i = 0; i < column; i++)
        {
            printf("%c",word[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Initialize();
    for (int i = 9; i < 10; i++)
    {
        system("clear");
        if (i>6) //要连起来所以衔接的概率高，因此最大数不能大
        {
            for (int j = 0; j < column; j++)
            {
                word_random_number[j] = rand()%10;
            }
            i = 3;
        }
        Change(i);
        Print();
        usleep(20000);
    }
    return 0;
}