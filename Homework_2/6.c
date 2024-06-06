/*
本段C语言代码将接收用户输入的字符，并输出该字符所占字节中每一位是0还是1
*/
#include<stdio.h>
int main(){
    char ch;
    printf("Input a word:");
    scanf("%c", &ch); //接收用户输入的字符
    pritnf("The eighth bit is %d\n", (ch>>7&1));
    pritnf("The seventh bit is %d\n", (ch>>6&1));
    pritnf("The sixth bit is %d\n", (ch>>5&1));
    pritnf("The fifth bit is %d\n", (ch>>4&1));
    pritnf("The forth bit is %d\n", (ch>>3&1));
    pritnf("The third bit is %d\n", (ch>>2&1));
    pritnf("The second bit is %d\n", (ch>>1&1));
    pritnf("The first bit is %d\n", ch&1);
    //如果该位是1，则与1进行逻辑与运算后结果是1；若该位是0，则与1进行逻辑与运算后结果是0
    return 0;
}