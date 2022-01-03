// 4_string.cpp
#include <iostream>
using namespace std;

#include <string.h> // 문자열 같은지 비교하기 위한 헤더

// 1. C언어에서는 문자열을 다룰 때,
//      char 배열 또는 const char* 를 사용한다.

#if 0
int main()
{
    char s1[] = "hello";
    const char *s2 = "hello";
    
    if (s1 == s2) // 주소를 비교하는 것
    {
    }

    if (strcmp(s1, s2) == 0)
    {
        printf("동일한 문자열 입니다...\n");
    }
}
#endif

// C언어의 헤더를 이용하는것이 아닌 C++의 헤더를 사용해 단순히 비교 연산자를 통해 일반적인 변수를 다루는 것처럼 사용이 가능해진다.
// > 좀더 직관적으로 문자열을 다룰 수 있다.
#include <string>

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2)
    {
        printf("동일한 문자열 입니다...\n");
    }
    std::string s3 = s2; // strcpy
    cout << s1 << ", " << s2 << ", " << s3 <<endl;
}

