#include "chainTypeQueue.h"

// 实现创建节点的方法,并返回创建的节点的地址
struct Node* CreateNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//============================================================================================================

// 实现创建队列结构体的函数
struct Queue* CreateQueue()
{
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue*));
    newQueue->QueueFront = NULL;
    newQueue->Queuetail = NULL;
    newQueue->size = 0;
    return newQueue;
}

//============================================================================================================
// 创建节点入队列的方法
void NodePush(struct Queue* p, int data)
{
    // 首先调用创建节点的方法进行节点的创建
    struct Node* newNode = CreateNode(data);
    // 节点创建完毕。开始将该节点入队列
    if(p->size == 0)
    {
        // 说明队列中无元素
        p->QueueFront = newNode;
        p->Queuetail = newNode;
        p->size++;
        return;
    }
    p->Queuetail->next = newNode;
    p->Queuetail = newNode;
    p->size++;
}

//============================================================================================================
// 创建一个展示队列数据的方法
void showQueue(struct Queue* p)
{
    // 首先判断队列头指针是否为NULL
    if(p->QueueFront == NULL)
    {
        printf("队列中无数据~\n");
        return;
    }
    struct Node* cur = p->QueueFront;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("队列元素数：%d\n",p->size);
    printf("\n");
}
//============================================================================================================

// 创建队头元素出队列方法
void PopQueueFront(struct Queue* p)
{
    if(p->QueueFront == NULL)
    {
        printf("队列中无数据~\n");
        return;
    }
    printf("当前队列头元素是：%d\n",p->QueueFront->data);
    p->QueueFront = p->QueueFront->next;
    p->size--;
    if(p->QueueFront == NULL)
    {
        printf("出队列操作后,队列为NULL\n");
    }
    else
    {
        printf("出队列操作后,当前队列元素为%d\n",p->QueueFront->data);
        printf("队列元素数为：%d\n",p->size);
    }
}

//============================================================================================================

int main()
{
    // 首先得到一个队列地址
    struct Queue* p = CreateQueue();
    int i = 0;
    for(;i<10;i++)
    {
        NodePush(p,i);
    }
    showQueue(p);
    PopQueueFront(p);
    return 0;
}
