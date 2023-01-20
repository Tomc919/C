#pragma once
#include <stdio.h>
#include <stdlib.h>

// 首先创建一个链式结构体变量
struct Node
{
    int data;
    struct Node* next;
};

// 再创建一个栈结构体变量
struct stack
{
    struct Node* stackTop;  // 栈顶标记
    int size;   // 栈中元素个数
};

// 创建初始化栈结构的方法
struct stack* CreatStackTop();
// 创建 创建节点的方法
struct Node* CreatNode(int data);
// 节点入栈的方法
void push(struct stack* newNode,int data);
// 展示栈中元素及栈中元素个数的方法
void show (struct stack* p);
// 展示栈顶元素的方法
void showFront(struct stack* p);
// 出栈操作
void Pop(struct stack* p);