#if 0
#include <iostream>
using namespace std;

// cout은 객체이다.
// std::ostream cout; 전역 객체로 만들어져 있다.

int main()
{
    int n = 10;
    double d = 3.14;

    cout << n;
    // cout.operator<<(n) 
    //  => cout.operator<<(int)
    cout << endl;

    cout << d;
    // cout.operator<<(d)
    //  => cout.operator<<(double)
    cout << endl;
}
#endif

#include <stdio.h>

namespace std
{
    class ostream
    {
    public:
        ostream& operator<<(int n)
        {
            printf("%d", n);
            return *this;
        }
        ostream& operator<<(const char* s)
        {
            printf("%s", s);
            return *this;
        }
        ostream& operator<<(double d)
        {
            printf("%lf", d);
            return *this;
        }
    };
ostream cout;
}

int main()
{
    // std::cout << 42;
    // std::cout << ", ";
    // std::cout << 3.14;

    std::cout << 42 << ", " << 3.14; // -> 처럼 만들고 싶은데 어떻게?
    // 자기 자신을 반환해야 한다.
    // cout.operator<<(42).operator(",").operator(3.14)
}

