#include <stdio.h>
#include <stdlib.h>
// malloc 内存块申请函数的使用
int main()
{
    // 向内存申请开辟空间
    int* p = (int*)malloc(sizeof(int)*10);
    char* pa = (char*)malloc(10);
    /*      使用内存申请函数时需要引头文件 <stdlib.h>
    解析：1. （int*） 强制类型转换，可以有也可以没有，GCC编译器下可以没有
          2. malloc(); 参数是需要开辟的内存空间大小（字节位单位）
          3. 返回值是 void* 类型的指针，该指针指向开辟的内存空间的首地址
          4. 该函数也有失败的时候，失败后返回 NULL
          5. 可以用错误码函数打印出来，头文件<errno.h> 函数：strerror(errno);
        
    */
   // 当我们的程序还没有结束，但是刚才申请的空间已经不用的情况下，就需要释放刚才申请的内存空间 ，具体如下：
   free(p);     // 参数是需要释放空间的指向首地址的指针,   通常来说，malloc() 和 free() 是一起使用的
   // 当我们这个程序走完的时候，即使申请的空间没有释放，也会被操作系统回收，但是，当程序足够大时，就必须用完释放，不能过多占用内存
   // 释放完内存空间后，p仍然有能力找到之前的那块地址，为了防止野指针的出现，故此 置 p = NULL
   p = NULL;
    return 0;
}
