#include "chainTypeStack.h"

struct stack* CreatStackTop()
{
    // 首先申请一块 struct Node* 类型的地址空间
    struct stack* MyInit = (struct stack*)malloc(sizeof(struct stack*));
    if(MyInit == NULL)
    {
        printf("程序奔溃~\n");
        exit(-1);
    } 
    // 开始初始化
    MyInit->stackTop = NULL;
    MyInit->size = 0;

    return MyInit;
}

//=====================================================================================================================
struct Node* CreatNode(int data)
{
    // 申请空间
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//=====================================================================================================================

void push(struct stack* newStack, int data)
{
    // 调用创建节点的方法来生成节点
    struct Node* newNode = CreatNode(data);
   
    newNode->next = newStack->stackTop;
    newStack->stackTop = newNode;
    newStack->size++;
}
//=====================================================================================================================
// 展示栈中元素及元素个数
void show (struct stack* p)
{
    // 首先获取栈顶元素的地址，然后赋值给临时变量cur
    struct Node* cur = p->stackTop;
    while(cur != NULL)
    {
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("栈内元素遍历完毕\n");
    printf("栈内元素个数总数为：%d\n",p->size);
}

//=====================================================================================================================
// 展示栈顶元素
void showFront(struct stack* p)
{
    if(p->size == 0)
    {
        printf("栈内无元素~\n");
        return;
    }
    printf("栈顶元素为：%d\n",p->stackTop->data);
}


//=====================================================================================================================
// 出栈顶元素操作
void Pop(struct stack* p)
{
    if(p->size == 0)
    {
        printf("栈中无元素，操作失败~\n");
        return;
    }
    printf("当前栈顶元素是：%d\n", p->stackTop->data);
    p->stackTop = p->stackTop->next;
    if(p->stackTop == NULL)
    {
        printf("栈内无元素~\n");
        return;
    }
    printf("出栈之后的栈顶元素是：%d\n",p->stackTop->data);
}

//=====================================================================================================================
int main()
{

    struct stack* s1 = CreatStackTop();
    int i = 0;
    for(;i<10;i++)
    {
        push(s1,i);
    }
    show(s1);
    showFront(s1);
    Pop(s1);
    printf("%p",s1);
    return 0;
}