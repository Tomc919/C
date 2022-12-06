#include "SingleLinkedList.h"
//=======================================================================================================================
 // 初始化链表 
void ListInit(SLL** phead)
{
    *phead = NULL;
}                                                                                                            
//========================================================================================================================
// 尾插法：头节点和数据源
void ListPushBack(SLL** phead, SLDataType x)
{
    // 链表为空，第一次插入数据 phead == NULL
    if((*phead) == NULL)
    {
        SLL* newnode = malloc(sizeof(SLL));
        if(newnode != NULL)
        {
            (*phead) = newnode;
            (*phead)->data = x;
            (*phead)->next = NULL;
            printf("satictis insert success....\n");
            return;
        }
        printf("memory block failed to be applied successfully...\n");
       return;
    }
    //链表已有数据
    SLL* cur = *phead;
    while(cur->next != NULL)
    {
      cur = cur->next;  
    }
    // 申请空间，构造SLL结构体
    SLL* newnode = malloc(sizeof(SLL));
    if(newnode != NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
    }
    // 构成完毕，且数据已加入
    cur->next = newnode;
}   

//========================================================================================================================
 // 展示链表中的所有数据
void ListShow(SLL** phead)
{
    // 首先检查是否是空链表：空链表标志：phead == NULL;
    if((*phead) == NULL)
    {
        printf("SingleLinkedList is empty\n");
        return;
    }
    SLL* cur = *phead;
    while(cur->next != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("%d ",cur->data);
}

//========================================================================================================================
 // 尾删法：头节点
void ListPopBack(SLL** phead)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("SingleLinkedList is Empty!\n");
        return;
    }
    // 只有一个数据的情况
    if((*phead)->next == NULL)
    {
        (*phead) = NULL;
        return;
    }
    // 有多个数据
    SLL* cur = *phead;
    SLL* tmp = NULL;
    while(cur->next != NULL)
    {
        tmp = cur;
        cur = cur->next;
    }
    tmp->next = NULL;
    
}  

//========================================================================================================================
// 判断链表是否为空，为空返回0，非空返回1
int ListIsEmpty(SLL** phead)
{
    return (*phead) == NULL ? 0 : 1;
}  

//========================================================================================================================
 // 头插法：头节点和数据源
void ListPushFront(SLL** phead,SLDataType x)
{
    // 首先判断链表是否为空
    int flag = ListIsEmpty(phead);
    // 链表为空
    if(!flag)
    {
       SLL* tmp = malloc(sizeof(SLL));
       (*phead)->data = x;
       (*phead)->next = NULL;
    }else
    {
        // 首先使用一个临时变量记录下原先第一个值
        SLL* tmp1 = (*phead);
        SLL* tmp2 = malloc(sizeof(SLL));
        tmp2->data = x;
        tmp2->next = tmp1;
        *phead = tmp2;
    }
}                                       

//========================================================================================================================
// 头删法：头节点
void ListPopFront(SLL** phead)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("List is Empty!\n");
        return;
    }
    // 只有一个节点(即头节点)
    if((*phead)->next == NULL)
    {
        *phead = NULL;
        return;
    }
    // 有多个节点
    SLL* tmp = (*phead)->next;
    *phead = tmp;
}                                                      

//========================================================================================================================
// 排序链表中的数据（从小到大）
void ListSort(SLL** phead)
{
    // 首先得到链表中得数据个数
    int count = ListNum(phead);
    if(!count)
    {
        printf("LinkedList is empty!\n");
        return;
    }
    if(count == 1)
    {
        printf("我即我，无需比较，世间第一等，此间最上乘！\n");
        return;
    }
    
    // 链表中有多个数据，这里我们采用只移动节点中的数据，并不整个移动节点的方式来进行排序（算是一种比较偷懒的做法）
    // 即：每个节点相互比较，前一个节点的数据域如果大于后一个节点的数据，那么就交换节点数据域，而不移动整个节点
    // 首先调用 ListNum();函数得到链表中节点的个数
    int num = ListNum(phead);
    SLL* curFront = NULL;
    SLL* curBack = NULL;
    for(int i = 0; i < num -1; i++)
    {
        curFront = *phead;
        curBack = (*phead)->next;
        for(int j = 0;j < num -i -1;j++)
        {
            if(curFront->data > curBack->data)
            {
                // 执行交换逻辑
                SLDataType tmp = 0;
                tmp = curFront->data;
                curFront->data = curBack->data;
                curBack->data = tmp;
            }
            curFront = curFront->next;
            curBack = curBack->next;
        }
    }
    
    
} 

//========================================================================================================================
// 查找链表中的某个值
void ListFindValue(SLL** phead, SLDataType x)
{
    int count = 0;
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("list is empty!\n");
        return;
    }

    SLL* cur = *phead;
    while(cur != NULL)
    {
        count++;
        if(cur->data == x)
        {
            printf("数据已找到，在第%d个节点上",count);
            return;
        }
        cur = cur->next;
    }
    printf("链表中未找到您想要得数据~\n");
} 

//========================================================================================================================
// 删除链表中的某个值
void ListDeleteValue(SLL** phead, SLDataType x)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("list is empty!\n");
        return;
    }
    // 只有一个数据的情况
    if((*phead)->next == NULL)
    {
        if((*phead)->data == x)
        {
            *phead = NULL;
            return;
        }else
        {
            printf("链表中没有你想要删除的数据\n");
            return;
        }
    }

    // 数据个数大于一，但是需要删除的是头节点
    if((*phead)->data == x)
    {
        *phead = (*phead)->next;
        return;
    }
    // 数据个数大于一
    SLL* cur = *phead;
    SLL* curFront = NULL;
    SLL* curBack = NULL;
    while(cur->next != NULL)
    {
        curFront = cur;
        curBack = (cur->next)->next;
        if(cur->next->data == x)
        {
            cur->next = (cur->next)->next;
        }
        cur = cur->next;
    }
} 

//========================================================================================================================
// 替换链表中的某个值
void ListReplaceValue(SLL** phead,SLDataType souX,SLDataType desX)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("list is empty!\n");
        return;
    }
    // 开始查找 源数据对应的节点
    SLL* cur = *phead;
    while(cur->next == NULL)
    {
        if(cur->data == souX)
        {
            cur->data = desX;
            printf("数据替换成功~\n");
            return;
        }
        cur = cur->next;
    }
    printf("没有找到对应的源数据~\n");
} 

 // 将数据insx 插入到指定的srcX节点后面*
void ListInsert(SLL** phead,SLDataType srcX,SLDataType insX)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("list is empty!\n");
        return;
    }
    SLL* cur = *phead;
    while(cur->next != NULL)
    {
        if(cur->data == srcX)
        {
            SLL* tmp = malloc(sizeof(SLL));
            if(tmp != NULL)
            {
                tmp->data = insX;
                tmp->next = cur->next;
                cur->next = tmp;
                printf("inserting satictis is success!\n");
                return;
            }
            
        }
        cur = cur->next;
    }

    printf("数据未插入成功~！\n");

}                        
//========================================================================================================================
// 回收链表内存空间
void ListFree(SLL** phead)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("LinkedList is empty!\n");
        return;
    }
    // 回收空间逻辑代码
    SLL* cur = *phead;
    // 该变量用来记录 next
    SLL* curTemp = NULL;
    while(cur != NULL)
    {
        curTemp = cur->next;
        free(cur);
        cur = NULL;
        cur = curTemp;
    }

    printf("memory is been empty!\n ");
}                                                         
//========================================================================================================================
// 链表中的数据个数
int ListNum(SLL** phead)
{
    int count = 0;
    if(*phead == NULL)
    {
        printf("list is empty!\n");
        return 0;
    }
    SLL* cur = *phead;
    while(cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;
}  

//========================================================================================================================
// 翻转链表中的数据
void ListInvert(SLL** phead)
{
    int flag = ListIsEmpty(phead);
    if(!flag)
    {
        printf("list is empty!\n");
        return;
    }
    if((*phead)->next == NULL)
    {
        printf("current list only have one node\n");
        return;
    }
    // 链表中有多个节点，符合翻转情况
    SLL* cur = *phead;
    SLL* curBack = NULL;
    SLL* curFront = *phead;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    curBack = cur;
    
}                                                        

//========================================================================================================================
// 测试程序
void Test()
{
    SLL sl;
    SLL* ps = &sl;
    ListInit(&ps);
    ListPushBack(&ps,2);
    ListPushBack(&ps,66);
    ListPushBack(&ps,4);
    ListPushBack(&ps,1);
    ListPushBack(&ps,1);
    ListShow(&ps);
    printf("\n");
    ListPopBack(&ps);
    ListShow(&ps);
    printf("\n");
    ListPushFront(&ps,1);
    ListShow(&ps);
    printf("\n");
    ListPopFront(&ps);
    ListShow(&ps);
    printf("\n");
    ListSort(&ps);
    ListShow(&ps);
    printf("\n");




    

}
int main()
{
    Test();
    return 0;
}