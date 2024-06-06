/*
这段C语言代码将实现以下功能:
1.调用另一个文件module.c中的两个函数，并打印出它们的返回值，还打印出module.c中的全局整数类型变量的值
2.自行编写头文件来实现对函数和全局变量的声明，并在其中通过预处理指令避免重复包含
*/
#include<stdio.h>
#include"head.h"
int main()
{
	printf("%d\n",i);
	int a,b;
	a=first();
	b=second();
	printf("%d\n",a);
	printf("%d\n",b);
	return 0;
}

/*
module.c中的代码如下：
int i=0;
int first()
{
    return 111;
}
int second()
{
    return 222;
}

head.h中的代码如下：
#ifndef HEAD_H
#define HEAD_H
int i;
int first();
int second();
#endif
*/