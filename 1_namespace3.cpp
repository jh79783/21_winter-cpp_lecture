// 1_namespace3.cpp

#if 0
#include <stdio.h>

int main()
{
    printf("Hello, C\n");
}
#endif

#include <cstdio>
/*
cstdio안에 다음과 같이 되어있음
namespace std{
    #include <stdio.h>
}
*/

int main()
{
    std::printf("Hello, C\n");
}
