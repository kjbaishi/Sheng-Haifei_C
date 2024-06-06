/*
这段C语言代码将实现以下功能：
1.接收用户输入的英文语句
2.以LED的形式将用户输入的语句展示出来
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void Input(char A[100])
{
    printf("Please input a sentence:");
    fgets(A,100,stdin); //接收用户输入的语句
}

void Print_Content(char* p1) //p1指向 存放用户输入的语句的数组
{
    int i;
    int j;
    int judge_number=0;
    int remain_number;
    for(i=60;i>=0;i--) //整个LED屏的可容纳字数为30个字
    {
        printf("\033[34m");
        printf("\n");
        printf("   +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n"); //上边框
        printf("   |"); //左边框
        printf("\033[31m");
        if(30<=i) //前31个i(60 → 30)是为了实现语句从右端出现到第一个字抵达最左端的效果
        {
            if(0!=i-30)
            {
                printf("\033[%dC",i-30); //光标位移指定格式，使语句的开头位于特定位置
            }
            remain_number=60-i; //此为剩余可放字数
            j=0;
            while('\n'!=p1[j]) //依次输出字符
            {
                if(0==remain_number)
                {
                    break; //如果剩余可放字容量为0则停止
                }
                printf("%c",p1[j]);
                j++;
                remain_number--; //每输出一个字符则剩余字容量减一
            }
            if(0!=remain_number)
            {
                printf("\033[%dC",remain_number); //如果输出完整句话还有剩余字容量，则光标位移至最后
            }
        }
        else //后30个i(29 → 0)是为了实现语句从第一个字符消失到最后一个字符消失的过程
        {
            remain_number=30;
            j=30-i; //初始：i=29,j=1
            while('\n'!=p1[j]) //j从1即第二个字符开始，说明第一个字符已经消失在左端
            {
                judge_number=1; //后续语句中设置每次循环都会使此变量为0，因此若judge_number=1则语句未打印结束
                printf("%c",p1[j]);
                j++;
                remain_number--;
                if(0==remain_number)
                {
                    break; //如果剩余可放字容量为0则停止
                }
            }
            printf("\033[%dC",remain_number); //如果输出完整句话还有剩余字容量，则光标位移至最后
            if(0==judge_number) //如果0==judge_number，则说明语句已全部消失在左侧，则进行右、下边框的补全
            {   
                printf("\033[34m");
                printf("|\n");
                printf("   +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
                usleep(100000);
                system("clear");
                break;
            }
            judge_number=0;
        }
        printf("\033[34m");
        printf("|\n");
        printf("   +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n");
        usleep(100000);
        system("clear");
    }
}

int main()
{
    char sentence[100];
    char* p1=sentence;
    Input(sentence);
    system("clear");
    for(int i=1;i<=2;i++) //此for循环是为了实现无限循环播放
    {
        Print_Content(p1);
        i--;
    }
    return 0;
}