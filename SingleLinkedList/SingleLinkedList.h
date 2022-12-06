#pragma once
#include <stdio.h>
#include <stdlib.h>
// 注：本程序中单链表存在头节点且头节点保存结构体的地址
typedef int SLDataType;             // 定义数据源类型 
typedef struct LinkedList
{
    SLDataType data;                  // 数据域
    struct LinkedList* next;       // 节点域
}SLL;

// 明确：phead指针是结构体SLL的地址6666  
void ListInit(SLL** phead);                                                          // 初始化链表          
void ListPushBack(SLL** phead, SLDataType x);                                        // 尾插法：头节点和数据源
void ListPopBack(SLL** phead);                                                       // 尾删法：头节点
void ListPushFront(SLL** phead,SLDataType x);                                        // 头插法：头节点和数据源
void ListPopFront(SLL** phead);                                                      // 头删法：头节点
void ListShow(SLL** phead);                                                          // 展示链表中的所有数据
void ListSort(SLL** phead);                                                          // 排序链表中的数据(从小到大)*
void ListInvert(SLL** phead);                                                        // 翻转链表中的数据*
void ListFindValue(SLL** phead, SLDataType x);                                       // 查找链表中的某个值
void ListDeleteValue(SLL** phead, SLDataType x);                                     // 删除链表中的某个值
void ListReplaceValue(SLL** phead,SLDataType souX,SLDataType desX);                  // 替换链表中的某个值
void ListFree(SLL** phead);                                                          // 回收链表内存空间
int ListIsEmpty(SLL** phead);                                                        // 判断链表是否为空，为空返回0，非空返回1
int ListNum(SLL** phead);                                                            // 链表中的数据个数
void ListInsert(SLL** phead,SLDataType srcX,SLDataType insX);                         // 将数据insx 插入到指定的srcX节点后面*