#include <iostream>
using namespace std;

class A
{
    int a;

public:
    // void foo() { cout << "foo" << endl;}
    virtual void foo() { cout << "foo" << endl;}
};

// 상속 관계가 아니다.
class B
{
    int b;

public:
    // void goo() { cout << "goo" << endl;}
    virtual void goo() { cout << "goo" << endl;}
};

int main()
{
    A aaa;
    // B* p = &aaa; // -> 오류
    // 해결하기 위해 cast 사용
    B* p = reinterpret_cast<B*>(&aaa); // 메모리 재해석하기 위한 cast

    p->goo();
}