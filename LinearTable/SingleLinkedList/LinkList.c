#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

typedef struct LNode{        //定义单链表结点类型
    ElemType data;               //数据域
    struct LNode *next;     //指针域
}LNode, *LinkList;

LinkList InitList(){              //初始化链表
    LinkList L=(LNode *)malloc(sizeof(LNode));       //分配一个头结点
    if (L==NULL)                            //内存不足，分配失败
        return 0;
    L->next=NULL;
    return L;
}

int Length(LinkList L){                //求表长
    int length=0;
    LNode *s=L->next;
    while (s!=NULL)
    {
        length++;
        s=s->next;
    }
    return length;
    
}

LinkList TailInsert(LinkList L){      //尾插法
    int x;
    L=(LinkList)malloc(sizeof(LNode));      //建立头结点
    LNode *s,*r=L;                            //r为表尾指针
    scanf("%d",&x);
    while (x != 9999)
    {
        s=(LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r=s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
    

}

void PrintList(LinkList L){             //输出链表
    LNode *s=L->next;
    if (s==NULL){
        printf("空表");
        return;
    }
    while (s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
    
}

LNode *GetElem(LinkList L, int i){      //按序号找结点
    if(i<1){
        printf("该序号不规范！！！");
        return NULL;
    }      
    int j = 1;
    LNode *p = L->next;
    while (p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }if (p==NULL)
    {   
        printf("该序号超出链表序号数！！！");
        return NULL;
    }else{
       return p;   
    }             
}

int LocateElem(LinkList L,int e){       //按值找结点 
    LNode *p=L->next;
    int j=1;
    while (p!=NULL && p->data!=e){
          p=p->next;
          j++;
    }
    if (p!=NULL)
    {   
        return j;
    }else{
        printf("链表中没有%d元素\n",e);
        return -1;
    }
    
}

void ListInsert(LinkList L,int i, int e){   //插入结点操作
    LNode *p=GetElem(L,i);
    LNode *s=(LNode *)malloc(sizeof(LNode));   
    s->data=e;
    s->next=p->next;
    p->next=s; 
}

void ListDelete(LinkList L,int i){          //删除结点操作
    LNode *p=GetElem(L,i-1);
    LNode *q=p->next;
    p->next=q->next;
    free(q);
}

void main(){
    int e,a,i;
    int go=1;
    printf("请输入数：");
    LinkList l = TailInsert(InitList());

    while(go){
        printf("——————————————————————————————————————————————\n");
        printf("请输入需要的进行的操作:\n1:输出链表 2：输出链表长度 3：按序号找结点 4：按值找结点 5:插入结点操作 6:删除结点 9:退出\n");
        scanf("%d",&a);
        switch (a)
        {
            case 1:                         //输出链表
                printf("链表为：");
                PrintList(l);
                break;
            case 2:                         //输出链表长度
                printf("链表长度为：%d\n",Length(l));
                break;
            case 3:                         //按序号找结点
                printf("输入序号：");
                scanf("%d",&i);
                printf("第%d个结点的值为%d\n",i,GetElem(l,i)->data);    
                break;
            case 4:                         //按值找结点
                printf("输入值：");
                scanf("%d",&e);
                printf("%d在第%d个结点上\n",e,LocateElem(l,e));
                break;
            case 5:
                printf("请输入需要在哪个结点后插入：");
                scanf("%d",&i);
                printf("请输入要插入的数：");
                scanf("%d",&e);
                ListInsert(l,i,e);
                break;
            case 6:
                printf("请输入需要删除的结点：");
                scanf("%d",&i);
                ListDelete(l,i);
                break;
            case 9:
                go=0;
                break;
            default:
                break;
        }

    }
    free(l);
}
