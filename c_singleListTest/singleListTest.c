#include "singleList.h"
void PushBack(SLL **phead, DataType x)
{
     // 首先判断头指针是否为空
     if(*phead == NULL)
     {
        // 申请空间地址并赋值给头指针
        SLL* newnode = malloc(sizeof(SLL));
        // 判断空间是否申请成功
        if(newnode == NULL)
        {
            // 地址申请未成功，直接退出程序
            printf("sorry, you need memory to failed\n");
            exit(-1);
        }
        // 没进入判断，说明地址空间申请成功
        *phead = newnode;
        (*phead)->next = NULL;
        // printf("申请的空间地址为：%p\n",*phead);
        // printf("%p\n",(*phead)->next);
     }

    // 至此，不带任何数据的头指针制作完毕，接下来开始申请内存空间，准备制作新的节点
    // 具体思路是：首先使用循环来找到某个next域为NULL的节点，然后申请空间，赋值并且将该新空间的next节点指向空，将该节点的next指向申请的新空间
    SLL* cur = *phead;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    // 至此找到next域为NULL的节点了，开始申请空间
    SLL* newnode = malloc(sizeof(SLL));
    // 判断空间是否申请成功
    if(newnode == NULL)
    {
        printf("堆内地址未能成功申请，程序崩溃~\n");
        exit(-1);   // 直接结束程序
    }
    // 地址空间申请成功，开始赋值
    newnode->a = x;
    newnode->next = NULL;
    cur->next = newnode;
    printf("链表节点添加成功~\n");
}

//======================================================================================================================================
void show (SLL *phead)
{
    if(phead != NULL)
    {
        SLL* cur = phead;
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d\t",cur->a);
            printf("%p\n",cur);
        }
    printf("数据遍历完成...\n");
    return;
    }
    printf("链表无数据~");
    return;

}

//======================================================================================================================================

void PushFront(SLL **phead,DataType x)
{
    // 头插法的核心思想是：将头节点与第一个节点的连接断开，且需要保存第一个节点的地址
    // 首先判断头节点是否为NULL
    if((*phead) == NULL)
    {
        SLL* newnode = malloc(sizeof(SLL));
        if(newnode == NULL)
        {
            printf("堆内地址未能成功申请，程序崩溃~\n");
            exit(-1);   // 直接结束程序
        }
        *phead = newnode;
        (*phead)->next = NULL;
    }

    if((*phead)->next == NULL)
    {
        SLL* Frontnode = malloc(sizeof(SLL));
        if(Frontnode == NULL)
        {
            printf("堆内地址未能成功申请，程序崩溃~\n");
            exit(-1);   // 直接结束程序
        }
        Frontnode->a = x;
        Frontnode->next = NULL;
        (*phead)->next = Frontnode;
    }
    if((*phead)->next != NULL)
    {
        SLL* cur = (*phead)->next;
        SLL* NewNode = malloc(sizeof(SLL));
        if(NewNode == NULL)
        {
            printf("堆内地址未能成功申请，程序崩溃~\n");
            exit(-1);   // 直接结束程序
        }
        NewNode->a = x;
        NewNode->next = cur;
        (*phead)->next = NewNode;
    }
}

//======================================================================================================================================

void Delete(SLL* phead, DataType x)
{
    // 首先判断头指针是否为空
    if(phead == NULL && phead->next == NULL)
    {
        printf("SingleList is Empty!,this operation cannot be completed ");
        exit(-1);
    }
    SLL* frontNode = phead;
    int flag = 1;
    while(frontNode->next != NULL)
    {
        if((frontNode->next)->a == x)
        {
            frontNode->next = (frontNode->next)->next;
            flag = 0;
            break;
        }
        frontNode = frontNode->next;
    }
    if(!flag)
    {
        printf("the data was Deleted!\n");
    }
    else
    {
        printf("Do not find this data!\n");
    }

}

//======================================================================================================================================
void ReverSingleList(SLL* phead)
{
    // 实现该功能使用的方法是倒序法，即将所有的节点的next的指向顺序改变
    // 该功能实现至少需压迫两个存储节点（不算头节点）
    if(phead == NULL && phead->next == NULL && (phead->next)->next == NULL)
    {
        printf("SingleList is Empty!,this operation cannot be completed ");
        exit(-1);
    }
    SLL* frontNode = phead->next;
    SLL* curNode = (phead->next)->next;
    SLL* backNode = ((phead->next)->next)->next;

    int i = 0;
    while(backNode != NULL)
    {
        if(i == 0)
        {
            frontNode->next = NULL;
            curNode->next = frontNode;
            frontNode = curNode;
            curNode = backNode;
            backNode = backNode->next;
            i++;
        }
        else
        {
            curNode->next = frontNode;
            frontNode = curNode;
            curNode = backNode;
            backNode = backNode->next;
            i++;
        }

    }
    curNode->next = frontNode;
    phead->next = curNode;
    printf("reversal is successful\n");
}

//======================================================================================================================================

void recursionRever(SLL* phead)
{
    if(phead == NULL || phead->next == NULL)
    return;

   // 首先定义一个变量存储传进来的指针变量
   SLL* newnode = phead->next;
   // 然后用这个得到的新节点调用这个方法
    recursionRever(newnode);
   // 执行到这里，该方法中phead是倒数第二个节点
   newnode->next = phead;
   phead->next = NULL;
   return; 

}
void recursionD(SLL* phead)
{
    SLL* cur = phead->next;
    SLL* temp = cur;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    recursionRever(phead);
    SLL* flag = cur->next;
    cur->next = NULL;
    flag->next = temp;

}

//======================================================================================================================================
int main()
{
    SLL sl;
   SLL *psl = &sl;
   psl = NULL;
//    printf("%p",psl);
   PushBack(&psl,1);
   PushBack(&psl,2);
   PushBack(&psl,3);
   PushFront(&psl,0);
   PushBack(&psl,4);
   PushBack(&psl,5);
//    printf("%p",psl);
//    printf("%p",&sl);
   show(psl);
   ReverSingleList(psl);
   show(psl);
   recursionD(psl);
   show(psl);
    return 0;
}