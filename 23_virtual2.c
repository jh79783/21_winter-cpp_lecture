#include <stdio.h>

struct AAA
{
    int a;
    char b;
    double c;
};

struct BBB
{
    char a;
    double b;
    int c;    
};

// 메모리는 1바이트 단위로 사용되지 않는다.
int main()
{
    printf("%ld\n", sizeof(struct AAA));
    printf("%ld\n", sizeof(struct BBB));
}

