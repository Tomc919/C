// 演示定义宏
#include <stdio.h>
// 宏定义格式：#define name(parament_list) stuff  参数列表是一个由逗号隔开的符号表，他们可能出现在 stuff中
// 注意：参数列表的左括号必须与宏名紧邻，不然会被当成 stuff 的一部分
#define SQUARE(X) X*X

int main()
{
    int ret = SQUARE(5);
    printf("%d\n",ret);         // 25
    return 0;
}