#include <stdio.h>
#include <stdlib.h>
// 演示动态内存分配函数 calloc(); 的使用
int main()
{
    // 该函数会将开辟出来的内存空间全部初始化为零，然后再返回
    int* pa = calloc(10,sizeof(int));
    // 第一个参数是个数； 第二个参数是字节数，整体的意思就是开辟10个4字节的空间，返回开辟好的内存的首地址
    // 同样的这个函数申请的内存空间使用后，需要 free();函数来释放内存空间
    free(pa);
    pa = NULL;
    return 0;
}