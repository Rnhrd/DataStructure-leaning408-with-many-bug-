#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *prior,*next;   
}LNode, *DLinkList;

void InitList(DLinkList L){
    
}
