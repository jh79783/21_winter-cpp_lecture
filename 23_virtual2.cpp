#include <stdio.h>

struct AAA
{

};

struct BBB
{
    
};

int main()
{
    printf("%ld\n", sizeof(AAA));
    printf("%ld\n", sizeof(BBB));
}

// 메모리가 조각나는 문제(단편화)를 관리하기 위해 가상 메모리 시스템이 등장
// 1. segment -> 윈도우
// 2. pageing -> 리눅스

// virtual == dynamic : runtime
