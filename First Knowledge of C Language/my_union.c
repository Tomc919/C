#include <stdio.h>

union Un
{
    int age ;
    char arr[5];
};
int main()
{

    union Un s;
    printf("%d\n",sizeof(s));       // 8
    printf("%p\n",&(s.age));        //000000000061FE18
    printf("%p\n",&(s.arr));        //000000000061FE18
    printf("%p\n",&s);              //000000000061FE18
    return 0;

}