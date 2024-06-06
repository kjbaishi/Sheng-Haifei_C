/*
这段C语言代码将通过对函数的补全，实现在不使用操作符'[]'的情况下对二维数组任意元素A[m][n]的访问(访问的结果仅
与m、n有关)，补全代码如下：
*/
#include<stdio.h>
int *p;
int two_array_access(int *x,int i,int j,int m,int n,int c)//'i'、'j'分别为所传二维数组中元素的行与列
{
    p=x+(m-i)*c+(n-j);
    //使指针p指向要访问的地址
    return *p;
}
int main()
{
    int A[2][3]={{1,2,3},{4,5,6}};

    two_array_access(&A[0][0],0,0,1,2,3);
    //将A[0][0]的地址传入
    printf("%d\n",*p);
    
    two_array_access(&A[1][2],1,2,1,2,3);
    //将A[1][2]的地址传入
    printf("%d\n",*p);    
    return 0;
}