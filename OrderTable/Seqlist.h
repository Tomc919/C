#pragma once
#include <stdio.h>
#include <stdlib.h>
// 动态顺序表的实现（顺序表实际上就是一个数组）
typedef int SLDataType;
// typedef 关键字的作用是：为某种数据类型定义一个新名字
// #define 关键字的作用是：为某个常量定义一个标识符
typedef struct SeqList
{
	SLDataType* a;
	int size;		// 表中数据的大小
	int capacity;	// 表中的实际存储容量
}SL;

// 接口函数
void SeqListInit(SL* ps);			// 顺序表初始化
void SeqListPushBack(SL* ps,SLDataType x);	// 尾插法
void SeqListPopBack(SL* ps);				// 尾删法
void SeqListPushFront(SL* ps, SLDataType x);	// 头插法
void SeqListPopFront(SL* ps);				// 头删法
void SeqListshow(SL* ps);						// 展示数据
void SeqListRelease(SL* ps);					// 回收内存块
void SeqListSort(SL* ps);						// 对顺序表中的数据进行排序，从小到大
