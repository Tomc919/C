#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    // 演示文本行输入输出函数的使用
    // 首先创建一个用于接受内容的字符串数组
    char buf[1024] = {0};
    // 然后打开文件进行读写
    FILE* ps = fopen("test.txt","r");
    if(ps == NULL)
    {
        printf("%s\n",strerror(errno));
        return 0;
    }
    // 读文件
    fgets(buf,1024,ps);
    /*参数解析：第一个参数：是将读取的内容保存下来的数组指针
    第二个参数：读取的字节数目
    第三个参数：从哪个流中读取（指针）
    该函数执行后，会将指定字节数的内容从执行的流中读取出来，并存放在指定的数组中
    */
   // 开始打印（两种打印方式：1. printf() 方式，2. puts(char*)）
   puts(buf);       // 该函数自带一个换行，也就是说打印完指定数组中的内容会自动加一个换行

   fclose(ps);
   ps = NULL;


   // 演示写文件
   // 打开文件
   FILE* pf = fopen("test.txt","w");
   if(pf == NULL)
   {
    return 0;
   }

    // 开始写
    fputs("hello\n",pf);        // 注意，该函数不带换行，直接就是挨着写，如果需要换行，需要自己加换行符号
    fputs("world\n",pf);        // 并且，该函数会覆盖掉之前文件中的内容

    fclose(pf);
    pf = NULL;
    return 0;
}