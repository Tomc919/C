#include <stdio.h>
#include <errno.h>
int main()
{
    // errno 是一个全局的错误码的变量, 注意：使用这个变量需要引用头文件 <errno.h>
    // 当c语言的库函数在执行过程中，发生了错误，就会把对应的错误码，赋值到 errno中
    
    // 下面演示函数的使用：
    // 函数参数情况：
    // 1. Operation not permitted
    // 2. No such file or directory
    //...
    char* str = strerror(2);        // 在实际情况中不是直接写入确定的参数来使用的，而是在可能出错的代码中，写入：strerror(errno);
    printf("%s\n",str);

    // 演示实际情况下，strerror() 函数的使用方法
    // 打开文件
    FILE* pf = fopen("test.txt","r");
    if (pf == NULL)
    {
        printf("%s\n",strerror(errno));     // 因为我的电脑中，没有 test.txt 这个文件，所以，会报错：No such file or directory
    }
    else
    {
        printf("open file success!");
    }
    char ch = 'D';
    char c = tolower(ch);
    printf("%c\n",c);
    
    return 0;
}