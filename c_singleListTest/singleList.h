#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct SingleList
{
    DataType a;
   struct SingleList* next;
}SLL;

// 实现尾插法
void PushBack(SLL **phead, DataType x);
//展示链表中的数据以及各自的next值
void show (SLL *phead);
// 单链表头插法实现
void PushFront(SLL **phead,DataType x);
// 实现一个指定数据的删除的方法
void Delete(SLL* phead, DataType x);
// 实现一个反转链表的方法
void ReverSingleList(SLL* phead);
// 实现一个递归反转链表的行为
void recursionRever(SLL* phead);
// 递归方法的最终实现
void recursionD(SLL* phead);