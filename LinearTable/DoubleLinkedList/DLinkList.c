#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *prior,*next;   
}LNode, *DLinkList;

DLinkList InitList(){                //初始化双链表
    DLinkList L=(DLinkList)malloc(sizeof(LNode));
    if (L==NULL)
        return NULL;
    L->next=L;
    L->prior=L;
    return L;
}
