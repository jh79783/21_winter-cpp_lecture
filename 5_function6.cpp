// Trailing return type
#include <iostream>
using namespace std;

// 함수 포인터
//  => 함수의 주소를 참조하는 포인터이다.
//  => 함수 포인터를 통해 함수를 호출할 수 있다.

// 함수의 타입은 함수의 파라미터와 반환타입에 의해 결정된다.
//  => 함수의 파라미터와 반환타입이 동일하면 동일한 타입이다.

int sub(int a, int b) { return a - b; } // int(int, int)
int add(int a, int b) { return a + b; } // int(int, int)

// C++11 - Trailing return type
// => 함수를 만드는 새로운 문법을 제공한다.
auto sub1(int a, int b) -> int
{
    return a - b;
}

auto foo2() -> int (*)(int a, int b)
{
    return &add;
}

using FP = int (*)(int a, int b);

// int (*foo())(int a, int b)
FP foo()
{
    return &add;
}
#if 0
int main()
{
    int a;

    add(10, 20);    // 일반적인 호출은 함수를 call하지만 함수 포인터를 사용하면 사용자가 점프하는 지점을 지정할 수 있다.

    int* p = &a;
    // add => int(int a, int b)
    int (*p2)(int a, int b) = &add;
    cout << (*p2)(10, 20) << endl;

    p2 = &sub; // 같은 타입이기 때문에 sub도 가능하다.
    cout << (*p2)(10, 20) << endl;
}
#endif

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; ++i)
        cout << x[i] << endl;

    // C++11 - ranged for
    for (int n : x)
        cout << n << endl;
}
