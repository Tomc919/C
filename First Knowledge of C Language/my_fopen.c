#include <stdio.h>
#include <errno.h>
int main()
{
    // 实现以下文件的简单读写功能
    FILE* pf = fopen("test.txt","w");
    if(pf == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    // 打开文件之后，开始写文件
    fputc('b',pf);      // 向文件中写入一个字符 'b';
    fputc('i',pf);
    fputc('t',pf);

    // 关闭文件
    fclose(pf);
    // 置指向文件缓冲区的pf指针为NULL
    pf = NULL;

    // 简单的读操作：
    FILE* ptr = fopen("test.txt","r");
    if(ptr == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    // 开始读文件
    // fgetc(); 函数用于从打开的文件中读取一个字符，并返回
    printf("%c ",fgetc(ptr));       // b
    printf("%c ",fgetc(ptr));       // i
    printf("%c ",fgetc(ptr));       // t

    // 关闭文件
    fclose(ptr);
    ptr = NULL;
    return 0;
}