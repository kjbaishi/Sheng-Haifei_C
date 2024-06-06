/*
这段C语言代码将实现如下功能：接收用户指定的年份，并打印出此年的日历
*/
#include<stdio.h>
int year;
int month;
int day;
int days;
int first_day;
int number1;
int number2;
int main()
{
	scanf("%d",&year);
	if(year>=2024)
		first_day=(year-2024+1+(year-2021)/4)%7;
		//此行公式根据“2024年一月一日是星期一”计算：所给年份大于2024的情况下一月一日是星期几
	else
		first_day=(980000+1-(2024-year)-(2024-year)/4)%7;
		//此行公式根据“2024年一月一日是星期一”计算：所给年份小于2024的情况下一月一日是星期几
	for(month=1;month<=12;month++)
	{
		print_month(month);
		print_week(month);
		switch(month) //根据月份决定“days”的数字
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				days=31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				days=30;
				break;
			case 2:
				if(year%4!=0||(year%100==0&&year%400!=0))
					days=28;
				else
					days=29;
				break;
		}
		for(day=1,number1=first_day,number2=first_day-1;day<=days;day++)
		{
		    if(0==number1) //第一天为星期天时first_day=0,因此重新对其进行初始化
		    {
		        number1=7; //变量number1决定了每个月的一号从星期几开始
		        number2=6; //变量number2决定了日历到星期天是否换行
		    }
			for(number1;number1>1;number1--)
			{
				printf("   "); //打印相应数量的空格使该月一日与对应星期对齐
			}
			number1=1; //将1赋给number1，使得下一个days不会参与上方for循环
			if(day<10)
			{
				printf(" %d ",day);
			}
			else
			{
				printf(" %d",day);
			}
			number2=number2+1;
			if(number2==7)
			{
				printf("\n"); //如果number2为7天，则进行换行操作
				number2=0;
			}
		}
		first_day=(first_day+days)%7; //根据该月一日是星期几与该月的days来计算下个月的一日是星期几
		printf("\n\n");
	}
	return 0;
}



int print_week()
{
	printf("(1)(2)(3)(4)(5)(6)(7)\n");
	return 0;
}



int print_month(int m)
{
	switch(m){
		case 1:
			printf("Jan\n");
			break;
		case 2:
			printf("Feb\n");
			break;
		case 3:
			printf("Mar\n");
			break;
		case 4:
			printf("Apr\n");
			break;
		case 5:
			printf("May\n");
			break;
		case 6:
			printf("Jun\n");
			break;
		case 7:
			printf("Jul\n");
			break;
		case 8:
			printf("Aug\n");
			break;
		case 9:
			printf("Sep\n");
			break;
		case 10:
			printf("Oct\n");
			break;
		case 11:
			printf("Nov\n");
			break;
		case 12:
			printf("Dec\n");
			break;
	}
	return 0;
}