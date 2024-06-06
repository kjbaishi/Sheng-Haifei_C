/*
这段C语言代码将建造一个五子棋棋盘，用户可在其上进行五子棋游戏
*/
#include<stdio.h>
char board[15][15]; //建造15×15的棋盘
char win_chess;     //赢得比赛的棋子种类
int Round;          //回合数

void Print_board() //打印出棋盘
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            printf(" %c",board[i][j]);
            if(14==j)
            {
                printf("\n");
            }
        }
    }
}

int Lay_chess(int Round) //根据回合数决定所下棋子的类型
{
    char chess;
    int i,j;
    int k=0;
    printf("Lay your chess:m n=");
    if(1==Round%2)
    {
        chess='#';
    }
    else
    {
        chess='O';
    }
    scanf("%d %d",&i,&j);
    if('#'==board[i-1][j-1]||'O'==board[i-1][j-1]||i>15||j>15)
    {
        printf("You can't lay there!\n");
        //如果该地有棋或不是棋盘，则不能下棋同时令返回值k=1,以便后续使回合数减一
        k=1;
    }
    else
    {
        board[i-1][j-1]=chess; //令棋盘对应区域变为该回合棋子种类
    }
    return k;
}

int Judge() //本函数用于评判是否胜利
{
    int i,j;
    int k=0;
    int t=0;
    for(i=0;i<15;i++) //i为行
    {
        for(j=0;j<15;j++) //j为列
        {
            if('#'!=board[i][j]&&'O'!=board[i][j])
            {
                continue;
            }
            
            if(j<11)
            {
                if(board[i][j]==board[i][j+1]&&board[i][j]==board[i][j+2]&&board[i][j]==board[i][j+3]&&board[i][j]==board[i][j+4])
                {
                    win_chess=board[i][j];
                    printf("'%c'win!\n",win_chess);
                    k=1;
                    t=1;
                    break;
                }
                //如果该点位向后数五格为相同棋子，则对应棋子胜利
            }
          
            if(i<11)
            {
                if(board[i][j]==board[i+1][j]&&board[i][j]==board[i+2][j]&&board[i][j]==board[i+3][j]&&board[i][j]==board[i+4][j])
                {
                    win_chess=board[i][j];
                    printf("'%c'win!\n",win_chess);
                    k=1;
                    t=1;
                    break;
                }
                //如果该点位向下数五格为相同棋子，则对应棋子胜利
            }
        
            if(i<11&&j<11)
            {
                if(board[i][j]==board[i+1][j+1]&&board[i][j]==board[i+2][j+2]&&board[i][j]==board[i+3][j+3]&&board[i][j]==board[i+4][j+4])
                {
                    win_chess=board[i][j];
                    printf("'%c'win!\n",win_chess);
                    k=1;
                    t=1;
                    break;
                }
                //如果该点位向右下数五格为相同棋子，则对应棋子胜利
            }
            
            if(i<11&&j>3)
            {
                if(board[i][j]==board[i+1][j-1]&&board[i][j]==board[i+2][j-2]&&board[i][j]==board[i+3][j-3]&&board[i][j]==board[i+4][j-4])
                {
                    win_chess=board[i][j];
                    printf("'%c'win!\n",win_chess);
                    k=1;
                    t=1;
                    break;
                }
                //如果该点位向左下数五格为相同棋子，则对应棋子胜利
            }
        }
        if(1==k)
        {
            break; //如果k=1,则停止评判
        }
    }
    return t;
}

void Initialize_the_board() //本代码用于初始化整个棋盘，每个点位用'+'表示
{
    int i,j;
    for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            board[i][j]='+';
        }
    }
}

int main()
{
    int win_number=0;
    int continue_number=0;
    Initialize_the_board(); //初始化棋盘
    Print_board(); //打印棋盘
    for(Round=1;Round<226;Round++) //回合数从1开始，最多225回合
    {
        continue_number=Lay_chess(Round); //Lay_chess如果下棋失败则返回1，否则为0
        if(1==continue_number)
        {
            continue_number=0;
            Round--;
            continue; //若下棋失败则回合数减一并直接进行下一个循环
        }
        Judge(); //评判是否有输赢
        win_number=Judge(); //如果有人胜利则Judge函数返回1，否则返回0
        if(1==win_number)
        {
            Print_board();
            break;
        }
        Print_board(); //打印目前棋盘状况
    }
    return 0;
}