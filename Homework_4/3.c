/*
这段C语言代码将实现非递归版本的创建链表
*/
#include<stdio.h>
#include<stdlib.h>
struct list
{
    int number;
    struct list *pNext;
};
struct list *create()//此函数是为了创建一个链表
{
    int i=0;
    struct list *pHead=NULL;
    struct list *pNew,*pEnd;
    pNew=pEnd=(struct list *)malloc(sizeof(struct list));
    printf("Input the number:");
    scanf("%d",&pNew->number);
    while(0!=pNew->number)
    {
        i++;
        if(1==i)
        {
            pNew->pNext=NULL;
            pHead=pNew;
        }
        else
        {
            pNew->pNext=NULL;
            pEnd->pNext=pNew;
            pEnd=pNew;
        }
        pNew=(struct list *)malloc(sizeof(struct list));
        printf("Input the number:");
        scanf("%d",&pNew->number);
    }
    free(pNew);
    return pHead;
}

void erase_list(struct list *p)//此函数为链表释放函数
{
    struct list *pNew;
    while(NULL!=p->pNext)
    {
        pNew=p->pNext;       //使 pNew 指向 p指向的链表元素中的指针指向的链表元素
        p->pNext=pNew->pNext;//使 链表中第一个元素中的指针 指向 pNew指向的链表元素中的指针指向的链表元素
        free(pNew);          //清除pNew指向的内存
    }
    free(p);//清楚p的内存
}

int main()
{
    struct list *p;
    p=create();
    erase_list(p);
    return 0;
}