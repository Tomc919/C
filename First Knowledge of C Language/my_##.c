// 主要演示 ## 的作用
#define ADD_TO_SUM(X,Y) X##Y
#include <stdio.h>

int main()
{
    int class48 = 2022;
    printf("%d\n",ADD_TO_SUM(class,48));        // 2022
    // 这句代码预处理之后就是：printf("%d\n",class48);
    // 也就是说 ## 的作用就是将两个字符串和平成为一个字符串（浅显理解）
    return 0;
}