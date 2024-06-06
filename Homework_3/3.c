/*
这段代码将通过C语言解决八皇后问题
*/
#include<stdio.h>
int row[8]={1,1,1,1,1,1,1,1};
//初始化棋盘的行，共8行('1'代表此处不处于其它皇后的攻击范围内)
int column[8]={1,1,1,1,1,1,1,1};
//初始化棋盘的列，共7行('1'代表此处不处于其它皇后的攻击范围内)
int slant_left[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//初始化棋盘自左上至右下每一个斜行，共15行('1'代表此处不处于其它皇后的攻击范围内)
int slant_right[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
//初始化棋盘自右上至左下每一个斜行，共15行('1'代表此处不处于其它皇后的攻击范围内)
int number=0;
int Final_number=0;

int find(int row[8],int column[8],int slant_left[15],int slant_right[15],int i,int j)
{
    if( 1==row[i] && 1==column[j] && 1==slant_left[i-j+7] && 1==slant_right[i+j] )
	//“i-j+7”与“i+j”是根据行列坐标推断斜行的公式,分别减一以对应数组中的元素
    {
        row[i]=0;
        column[j]=0;
        slant_left[i-j+7]=0;
        slant_right[i+j]=0;
		//如果可以放皇后，那就使此格以及其可以攻击到的位置的'1'均变为'0'
		return 1;
    }
    else
    {
        return 0;
    }
}

int final_find(int row[8],int column[8],int slant_left[15],int slant_right[15])
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(1==row[i]&&1==column[j]&&1==slant_left[i-j+7]&&1==slant_right[i+j])
            {
                number++;
            }
        }
    }
    return number;
}    


int main()
{
	int a;
	int i1,i2,i3,i4,i5,i6,i7,i8;
	int j1,j2,j3,j4,j5,j6,j7,j8;
//接下来将通过14个for循环(两两一组)来实现前7个皇后的放置，最后统计剩余可放第八个皇后的位置的个数
	for(i1=0;i1<8;i1++)
	{
	    for(j1=0;j1<8;j1++)
	    {
	        if(0==find(row,column,slant_left,slant_right,i1,j1))
	        {
	            continue;
	        }
			//返回值是0，说明该位置不可放置，继续遍历棋盘寻找位置
	        for(i2=0;i2<8;i2++)
	        {
	            for(j2=0;j2<8;j2++)
	            {
	                if(0==find(row,column,slant_left,slant_right,i1,j1))
					{
						continue;
					}
	                for(i3=0;i3<8;i3++)
	                {
	                    for(j3=0;j3<8;j3++)
	                    {
	                        if(0==find(row,column,slant_left,slant_right,i1,j1))
							{
								continue;
							}
	                        for(i4=0;i4<8;i4++)
	                        {
	                            for(j4=0;j4<8;j4++)
	                            {
	                                if(0==find(row,column,slant_left,slant_right,i1,j1))
									{
										continue;
									}
	                                for(i5=0;i5<8;i5++)
	                                {
	                                    for(j5=0;j5<8;j5++)
	                                    {
	                                        if(0==find(row,column,slant_left,slant_right,i1,j1))
											{
												continue;
											}
	                                        for(i6=0;i6<8;i6++)
	                                        {
	                                            for(j6=0;j6<8;j6++)
	                                            {
	                                                if(0==find(row,column,slant_left,slant_right,i1,j1))
													{
														continue;
													}
	                                                for(i7=0;i7<8;i7++)
	                                                {
	                                                    for(j7=0;j7<8;j7++)
	                                                    {
	                                                        if(0==find(row,column,slant_left,slant_right,i1,j1))
															{
																continue;
															}
	                                                        Final_number+=final_find(row,column,slant_left,slant_right);
															//通过14个for循环放置7个皇后后统计其他能够放置第八个皇后的位置，并求和
															number=0;
	                                                    }
	                                                }
	                                            }
	                                        }
	                                    }
	                                }
	                            }
	                        }
	                    }
	                }    
	            }
	        }
	    }
	}
	printf("%d\n",Final_number);
	return 0;
}