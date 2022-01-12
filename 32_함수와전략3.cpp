#include <iostream>
using namespace std;

// 1. 함수는 자신만의 타입이 없다.
//  > 함수의 시그니처(인자 정보, 반환 타입) 동일한 모든 함수는 같은 타입이다.
class A
{};
class B
{};

void foo() {}
void goo() {}


// 함수처럼 사용가능한 객체를 '함수 객체' 라고 한다.

// 2. 함수 객체는 자신만의 타입이 있다.
//  > 시그니처가 동일해도 모든 함수 객체는 다른 타입이다.
struct Plus
{
    int operator()(int a, int b) const
    {
        return a + b;
    }
};

struct Minus
{
    int operator()(int a, int b) const
    {
        return a - b;
    }
};

int main()
{
    Plus plus;

    int result = plus(10, 20);  // -> plus.operator()(10, 20);

    cout << result << endl;
}