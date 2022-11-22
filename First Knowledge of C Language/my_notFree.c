#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 申请一块空间
    int* p = (int*)malloc(40);
   
    if(p == NULL)
    {
        return 0;
    }
    else
    {
    // 初始化前20个字节
        for(int i = 0;i < 5;i++)
        {
            *p++ = i;
        }
    }
    // 这里，p指向的不再是动态开辟的内存的首地址了
    free(p);        // 这里是错误的！，内存释放只能使指针指向动态申请的内存空间首地址
    p = NULL;
    return 0;
}