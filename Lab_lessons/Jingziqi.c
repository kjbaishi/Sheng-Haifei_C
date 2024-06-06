/*
这段C语言代码将建造一个井字棋棋盘，用户可在其上进行井字棋游戏
*/
#include<stdio.h>
char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //初始化棋盘的每个格子的内容为空格
int Round=0;

void Print() //该函数用于打印棋盘
{
    int i,j;
    for(i=0;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
	    printf("%c",board[i][j]);
	    if(2!=j)
	    {
	        printf(" | ");
	    }
	    if(2==j&&2!=i)
	    {
	        printf("\n");
	        printf("--+---+--");
		printf("\n");
	    }
	    if(2==j&&2==i)
	    {
	        printf("\n\n");
	    }
	}
    }
}

int Find(int Round) //该函数将根据回合数决定所下棋子的类型，并将其放置于用户指定的位置
{
    int i,j;
    int I,J;
    printf("row=");
    scanf("%d",&I);
    printf("column=");
    scanf("%d",&J);
    i=I-1;
    j=J-1;
    if(' '==board[i][j])
    {
        if(1==Round%2)
        {
            board[i][j]='O';
        }
        else
        {
            board[i][j]='X';
        }
    }
    else
    {
        printf("You can't lay there\n");
        Round--; //如果此处有棋子则无法下棋，并使回合数减一
    }
    return Round;
}

int Judge(int t) //本函数用于评判是否有玩家胜利
{
    int i,j;
    int number_O=0;
    int number_X=0;
    int k=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            switch(board[i][j])
            {
                case 'O':	
                    number_O++;
		    break;
                case 'X':
                    number_X++;
		    break;
            }
            if(3==number_O)
            {
                printf("Player_1 Win\n");
                k=1;
            }
            if(3==number_X)
            {
                printf("Player_2 Win\n");
                k=1;
            }
        }
        number_O=0;
        number_X=0;
        if(1==k)
        {
            t=0;
            break;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            switch(board[j][i])
            {
                case 'O':
                    number_O++;
		    break;
                case 'X':
                    number_X++;
		    break;
            }
            if(3==number_O)
            {
                printf("Player_1 Win\n");
                k=1;
            }
            if(3==number_X)
            {
                printf("Player_2 Win\n");
                k=1;
            }
        }
        number_O=0;
        number_X=0;
        if(1==k)
        {
            t=0;
            break;
        }
    }
    for(i=0,j=0;i<3,j<3;i++,j++)
    {
        switch(board[i][j])
        {
            case 'O':
                number_O++;
		break;
            case 'X':
                number_X++;
		break;
        }
        if(3==number_O)
        {
            printf("Player_1 Win\n");
            t=0;
        }
        if(3==number_X)
        {
            printf("Player_2 Win\n");
            t=0;
        }
    }
    number_O=0;
    number_X=0;
    for(i=0,j=2;i<3,j>=0;i++,j--)
    {
        switch(board[i][j])
        {
            case 'O':
                number_O++;
		break;
            case 'X':
                number_X++;
		break;
        }
        if(3==number_O)
        {
            printf("Player_1 Win\n");
            t=0;
        }
        if(3==number_X)
        {
            printf("Player_2 Win\n");
            t=0;
        }
    }
    number_O=0;
    number_X=0;
    return t;
}

int main()
{
    int number_judge=1;
    for(Round=1;Round<=9;Round++)
    {
        Round=Find(Round); //下棋并返回回合的值，若下棋失败则回合数减一
        number_judge=Judge(number_judge); //判断是否有玩家胜利，有玩家胜利则返回0，否则返回1
        if(0==number_judge)
        {
            Print();
            break; //如果有玩家胜利则打印棋盘并结束循环
        }
        Print();
    }
    return 0;
}