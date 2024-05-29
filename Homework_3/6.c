#include<stdio.h>
int *p;
int two_array_access(int *x,int i,int j,int m,int n,int c)
{
    p=x+(m-i)*c+(n-j);
    return *p;
}
int main()
{
    int A[2][3]={{1,2,3},{4,5,6}};
    
    two_array_access(&A[0][0],0,0,1,2,3);

    printf("%d\n",*p);
    
    two_array_access(&A[1][2],1,2,1,2,3);
    
    printf("%d\n",*p);    
    return 0;
}