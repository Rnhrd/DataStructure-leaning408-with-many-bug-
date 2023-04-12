#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *prior,*next;   
}LNode, *DLinkList;

 //初始化双链表
void InitList(DLinkList L){               
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    L->prior=NULL;
}

//求双链表的长度
int Length(DLinkList L){
    LNode *p = L->next;
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//遍历操作
void PrintList(DLinkList L){
    LNode *p = L->next;
    while(p){
        printf("%d",p->data);
        p = p->next;
    }
}

//尾插法
DLinkList TailInsert(DLinkList L){  
    InitList(L);       
    ElemType e;
    LNode *s,*r=L;              //s为每次新创建的结点，r为指向链尾元素的指针
    scanf("%d",&e);
    while (e!=9999)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=NULL;
        r->next=s;
        s->prior=r;
        r=s;
        scanf("%d",&e);
    }
    return L;
}

//头插法
DLinkList HeadInsert(DLinkList L){
    InitList(L);
    ElemType e;
    scanf("%d",&e);
    while (e!=9999)
    { 
        LNode *s=(LNode *)malloc(sizeof(LNode));
        s->data=e;
        if(L->next==NULL){
            s->next=NULL;
            s->prior=L;
            L->next=s;
        }else{
            s->next=L->next;
            L->next->prior=s;
            s->prior=L;
            L->next=s;
        }  
        scanf("%d",&e);
    } 
    return L;    
}

//按值查找：查找e在L中的位置
LNode *LocateElem(DLinkList L,ElemType e){
    LNode *p=L->next;
    while (p&&p->data!=e)
    {
        p=p->next;
    }
    return p;
}

//按位查找：查找在双链表L中第i个位置的结点
LNode *GetElem(DLinkList L, int i){
    int j=1;
    LNode *p = L->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p && j<i){
        p = p->next;
        j++;
    }
    return p; //如果i大于表长，p=NULL,直接返回p即可
}

//将x插入到双链表L中*p结点的下一个结点
void Insert(DLinkList L, LNode *p, int e){
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}

//删除操作:将双链表中的第i个结点删除
void Delete(DLinkList L, int i){
    if(i<1 || i>Length(L)){
        printf("删除错误，结点值出错");
    }
    LNode *p = GetElem(L,i-1);
    LNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
}

//判空操作
bool Empty(DLinkList L){
    if(L->next == NULL){
        printf("L is null");
        return true;
    }else{
         printf("L is null");
        return false;
    }
}

int main(){
    //尾插法建立双链表，并遍历单链表
    DLinkList L = TailInsert(L);
    printf("L: ");
    PrintList(L);
    
    LNode *p;
    //按值查找
    p = LocateElem(L,2);
    printf("值为2的结点的下一个结点值是：",p->next->data);
    printf("值为2的结点的上一个结点值是：",p->prior->data);
  
    //按位查找
    p = GetElem(L,3);
    printf("第三个结点值是：",p->data);
    //插入操作
    Insert(L,p,7);
    printf("在第三个结点后面插入值为7的结点后L：");
    PrintList(L);
    
    //删除操作
    Delete(L, 5);
    printf("删除第五个结点后L：");
    PrintList(L);
    
    //求表长
    printf("表长为：",Length(L));
    //判空
    Empty(L);
    return 0;
}