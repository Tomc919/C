// 预定义符号的简单演示
// __FILE__         字符串，打印出当前源代码文件所在的绝对路径
// __LINE__         整数， 打印出当前代码所在的行数
//__DATE__          字符串， 文件被编译的日期（注意，是编译，不是运行）
//__TIME__          字符串， 文件被编译的时间
//__FUNCTION__      字符串，打印出该句代码所在函数的函数名
//__STDC__          如果编译器遵循 ANSI C，其值为1， 否则未定义

#include <stdio.h>

int main()
{
    int i = 0;
    printf("%s\n",__FILE__);        // my_finally.c
    printf("%d\n",__LINE__);        // 15
    printf("%s\n",__TIME__);        // 17:41:27
    printf("%s\n",__FUNCTION__);    // main
    printf("%d\n",__STDC__);        // 1
    return 0;
}