#include "Seqlist.h"
// 实现 Seqlist.h 头文件中的函数声明
// c语言顺序表
//================================================================================
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
	printf("初始化完成...\n");
}
//================================================================================
	// 尾插法实现
void SeqListPushBack(SL* ps,SLDataType x)
{
	// 三种情况：1. 程序第一次运行到这，还未开辟空间
	// 2. 已开辟的空间不够
	// 3. 开辟的空间足够
	
	// 1 2.
	if(ps->size == ps->capacity)		// 说明：内存空间不足或者内存空间未开辟
	{
		// 这里判断一下是内存空间不足还是内存未分配(三目运算符)
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity*2;
		// 然后申请内存空间
		SLDataType* tmp = realloc(ps->a,newcapacity*sizeof(SLDataType));
		/*
		realloc();函数第一个参数是之前申请的动态内存的首地址，第二个参数是：变更后的内存总大小
		如果第一个参数为NULL，那么realloc();函数就相当于 malloc(); 函数
		*/
		// 验证申请空间是否成功，申请成功返回申请的地址（首地址），失败则返回NULL
		if(tmp == NULL)
		{
			printf("realloc fail...\n");
			exit(-1);		// 退出函数
		}
		
		// 申请成功，将申请成功的函数地址赋值给 SLDataType,并且更新 capacity的内容
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	// 3.
	ps->a[ps->size] = x;
	// c语言中 数组名[i] == *（数组名+i）； 
	// 当然上述语句也可以写成：*(a+ (*(ps)).size);
	ps->size++;
}
//================================================================================
// 尾删法实现
void SeqListPopBack(SL* ps)
{
	// 本着严谨的态度，首先应该判断一下这里面是不是有数据（即判断pa-> ?= NULL）
	if(ps->a == NULL)
	{
		printf("there are not satictis!\n");
		exit(-1);
	}
	// 再严谨一下，只有一个数据的情况
	if(ps->size == 1)
	{
		ps->a = NULL;
	}
	// 然后就是普遍情况
	ps->size--;
	printf("satictis is deleted!\n");
}
//================================================================================
// 头插法实现
void SeqListPushFront(SL* ps, SLDataType x)
{
	// 这里还是需要判断顺序表是否为空或者顺序表满了的情况
	if(ps->capacity == ps->size || ps->a == NULL)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = realloc(ps->a,newcapacity*sizeof(SLDataType));
		if(tmp == NULL)
		{
		printf("realloc() fail...\n");
		exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	
	// 第一种情况：顺序表为空,即：
	if((ps->size) == 0)
	{
		ps->a[ps->size] = x;
		ps->size++;
		printf("insert success...\n");
		return;
	}else
	{
// 值得注意的是：这里的ps->size 指的是表中的数据个数，并非从零开始计算的表的大小
	int i = ps->size;						// 表原有的size
	int flag = ps->size - 1;	
	for(;i>0;i--)
	{
		ps->a[i] = ps->a[flag];
		if(!flag)
		{
			break;
		}
		flag--;		
	}
	
	ps->a[flag] = x;
	ps->size++;
	printf("satictis inserted...\n");
	}
	
}

//================================================================================			
// 头删法
void SeqListPopFront(SL* ps)
{
	if(ps->a == NULL)
	{
		printf("satictis is not exist!\n");
		exit(-1);
	}
	// ps->size 保存的是顺序表中的元素个数
	ps->size--;
	for(int i = 0; i<(ps->size);i++)
	{
		ps->a[i] = ps->a[i+1];
	}
	printf("delete is success!\n");
}
//================================================================================
// 展示数据
void SeqListshow(SL* ps)
{
	
	for(int i = 0;i < (ps->size);i++)
	{
		printf("%d ",ps->a[i]);
	}
	printf("\n");
}
//================================================================================
// 回收内存块
void SeqListRelease(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//================================================================================
// 对顺序表中的数据进行排序，从小到大
void SeqListSort(SL* ps)
{
	for(int i = 0;i < ps->size -1;i++)
	{
		for(int j = 0;j < ps->size - i - 1;j++)
		{
			if(ps->a[j] < ps->a[j + 1])
			{
				SLDataType temp = ps->a[j];
				ps->a[j] = ps->a[j + 1];
				ps->a[j+1] = temp;
			}
		}
	}
}	

//================================================================================
int main()
{
	SL sl;
	SeqListInit(&sl);
	//SeqListPushBack(&sl,2);
	//SeqListPushBack(&sl,3);
	//SeqListPushBack(&sl,4);
	SeqListPushFront(&sl,1);
	SeqListPushFront(&sl,2);
	SeqListPushFront(&sl,3);
	SeqListPushFront(&sl,4);
	//SeqListPopFront(&sl);
	SeqListPopBack(&sl);  
	SeqListPushFront(&sl,1);
	SeqListshow(&sl);
	SeqListSort(&sl);
	SeqListshow(&sl);
	
	return 0;
}