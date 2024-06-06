/*
这段C语言代码经过补全而成，实现输出字符串C!YYDS!
*/
#include<stdio.h>
int main()
{
	long x=1;
	x=0x0021534459592143;
	//用16进制表示，从末位开始每两个数占一个字节，且对应C!YYDS!中每一个字符的ASCLL码
	printf("%s\n",&x);
	return 0;
}