#include <iostream>
using namespace std;

// 주의사항
class Test
{
    int x;

public:
    Test () {}
    // 1. 모든 멤버 데이터를 상수 취급 한다.
    const int *getAddress() const
    {
        // x의 타입은 const int 타입으로 취급된다.

        return &x;
    }

    // 2. const 함수는 오버로딩이 가능하다.
    void foo()
    {
        cout << "foo" << endl;
    }
    
    void foo() const
    {
        cout << "const foo" << endl;
    }

    void goo() const;
};

// 선언과 정의를 분리할 때, 모두 const가 명시되어야 한다.
void Test::goo() const {}

int main()
{
    Test t1;
    const Test t2;

    t1.foo();   // foo
    t2.foo();   // const foo

}