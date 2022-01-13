// 37_일반적프로그래밍.cpp

// C++ 표준 라이브러리를 이해하기 위해서는 일반화(Generic)을 이해해야한다.
// C++ = 객체 지향 + 일반화(Generic)

#include <iostream>
using namespace std;

#if 0
char* xstrchr(char* s, char c)
{
    while (*s != '\0' && *s != c)
        s++;

    return *s == c ? s : NULL;
}

int main()
{
    char s[] = "abcdefg";

    char *p = xstrchr(s, 'c');

    if (p)
        cout << *p << endl;
}
#endif

// 1. 검색 구간의 일반화
//  : 전체 구간에서 부분 구간에 대한 검색이 가능해야한다.
// > 검색할 구간의 시작과 검색할 구간의 마지막 다음 위치를 인자로 전달받도록 해야한다.

// [first, last) : 반개구간
#if 0
char* xstrchr(char* first, char* last, char value)
{
    while (first != last && *first != value)
        ++first;

    // return first == last ? nullptr : first;
    return first;
}

int main()
{
    char s[] = "abcdefg";

    char* p = xstrchr(s, s + 7, 'c');

    if (p != s + 7) // 성공!
        cout << *p << endl;
}
#endif

// 2. 검색 대상 타입의 일반화 => Template 도입
// T* xfind(T* first, T* last, T value) 의 문제점
// : - T* 라고 하면, 포인터 타입만 가능하다. -> 스마트 포인터 사용이 불가능하다.
// - 구간의 타입과 요소의 타입을 분리하는 것은 double 배열 안에서 int 타입을 찾는 것도 가능해진다.

// template <typename T>
template <typename T1, typename T2>     // 구간을 나타내는 타입을 분리해 줄 필요가 있다.
// T* xfind(T* first, T* last, T value)
T1 xfind(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;

    return first;
}

#include <vector>
int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 }; // C++11부터

    auto p2 = xfind(v.begin(), v.end(), 3);
    if (p2 != v.end())
        cout << *p2 << endl;

    char s[] = "abcdefg";

    char* p = xstrchr(s, s + 7, 'c');

    if (p != s + 7) // 성공!
        cout << *p << endl;
}