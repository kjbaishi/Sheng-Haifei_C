#include<stdio.h>
int row[8]={1,1,1,1,1,1,1,1};
int column[8]={1,1,1,1,1,1,1,1};
int slant_left[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int slant_right[15]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int number1=0;
int number2=0;
int number3=0;

int find(int i,int j)
{
    if(1==row[i]&&1==column[j]&&1==slant_left[i-j+7]&&1==slant_right[i+j])
    {
        row[i]=0;
        column[j]=0;
        slant_left[i-j+7]=0;
        slant_right[i+j]=0;
    }
    else
    {
        number1=1;
    }
}

int final_find()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(1==row[i]&&1==column[j]&&1==slant_left[i-j+7]&&1==slant_right[i+j])
            {
                number2++;
            }
        }
    }
    return number2;
}    


int main()
{
	int a;
	int i1,i2,i3,i4,i5,i6,i7,i8;
	int j1,j2,j3,j4,j5,j6,j7,j8;
	for(i1=0;i1<8;i1++)
	{
	    for(j1=0;j1<8;j1++)
	    {
	        find(i1,j1);
	        if(1==number1)
	        {
	            number1=0;
	            continue;
	        }
	        for(i2=0;i2<8;i2++)
	        {
	            for(j2=0;j2<8;j2++)
	            {
	                find(i2,j2);
	                if(1==number1)
	                {
	                    number1=0;
	                    continue;
	                }
	                for(i3=0;i3<8;i3++)
	                {
	                    for(j3=0;j3<8;j3++)
	                    {
	                        find(i3,j3);
	                        if(1==number1)
	                        {
	                            number1=0;
	                            continue;
	                        }
	                        for(i4=0;i4<8;i4++)
	                        {
	                            for(j4=0;j4<8;j4++)
	                            {
	                                find(i4,j4);
	                                if(1==number1)
	                                {
	                                    number1=0;
	                                    continue;
	                                }
	                                for(i5=0;i5<8;i5++)
	                                {
	                                    for(j5=0;j5<8;j5++)
	                                    {
	                                        find(i5,j5);
	                                        if(1==number1)
	                                        {
	                                            number1=0;
	                                            continue;
	                                        }
	                                        for(i6=0;i6<8;i6++)
	                                        {
	                                            for(j6=0;j6<8;j6++)
	                                            {
	                                                find(i6,j6);
	                                                if(1==number1)
	                                                {
	                                                    number1=0;
	                                                    continue;
	                                                }
	                                                for(i7=0;i7<8;i7++)
	                                                {
	                                                    for(j7=0;j7<8;j7++)
	                                                    {
	                                                        find(i7,j7);
	                                                        if(1==number1)
	                                                        {
	                                                            number1=0;
	                                                            continue;
	                                                        }
	                                                        final_find();
								number3=number3+number2;
								number2=0;
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
	printf("%d\n",number3);
	return 0;
}