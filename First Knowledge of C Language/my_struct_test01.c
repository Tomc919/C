#include <stdio.h>
struct                  // 匿名结构体类型
{
    int age;
    char arr[];
}sa;

struct                  // 匿名结构体指针类型
{
    int age;
    char arr[];
}* pa;

int main()
{
    // 虽然上面两个结构体中的数据类型是一样的，但是下面的代码还是不能执行
    pa = &sa;
    return 0;
}