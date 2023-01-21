#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* QueueFront;
    struct Node* Queuetail;
    int size;
};

// 实现创建节点的方法,并返回创建的节点的地址
struct Node* CreateNode(int data);
// 实现创建队列结构体的函数
struct Queue* CreateQueue();
// 创建节点入队列的方法
void NodePush(struct Queue* p, int data);
// 创建一个展示队列数据的方法
void showQueue(struct Queue* p);
// 创建队头元素出队列方法
void PopQueueFront(struct Queue* p);

