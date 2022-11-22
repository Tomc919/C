#include <stdio.h>
#include <stdlib.h>
// 柔性数组：即结构体中的最后一个元素可以是未知大小的，（c99标准）

struct S
{
    int a;
    int arr[];          // 未定义数组具体大小
};
int main()
{
    struct S s1;
    printf("%d\n", sizeof(s1));     // 柔性数组在未被使用之前，计算结构体的大小是不包含柔性数组的大小的,所以这里应该是 4
    // 首先申请一块空间
    struct S* ps = (struct S*)malloc(5*sizeof(int)+sizeof(struct S));
    ps->a = 100;

    int i = 0;
    for(i = 0;i < 5;i++)
    {
        ps->arr[i] = i;
    }

    // 再续接一块内存，新空间的大小为44个字节
   struct S* ptr =  realloc(ps, 44);
   // 判断新空间是否开辟完成
   if(ptr != NULL)
   {
    ps = ptr;
   }

    for(i = 0;i < 10;i++)
    {
        ps->arr[i] = i;
    }
    for(i = 0; i < 10; i++)
    {
        printf("%d ",ps->arr[i]);
    }
    return 0;
}