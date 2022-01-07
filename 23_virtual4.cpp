#include <iostream>
using namespace std;

// 가상함수 : 실행 시간에 동작
// 디폴트 인자: 컴파일 시간에 동작

// > 가상 함수에 되도록이면 기본 인자를 사용하지 말자.
// 사용했다면, 오버라이딩 할 때 변경하지 말자.
class A
{
public:
    virtual void foo(int a = 10)
    {
        cout << "A: " << a << endl;
    }
};

class B : public A
{
public:
    void foo(int a = 20) override
    {
        cout << "B: " << a << endl;
    }
};

int main()
{
    // A a;
    // a.foo();

    // B b;
    // b.foo();

    A* p = new B;
    p->foo();   // 실행 결과 - B: 10 (????)
    // 컴파일러는 타입으로 추론하게 된다. p의 타입은 A이여서 a에는 기본값 10이 된다.
    // 하지만 foo는 가상함수로 런타임때 동작하므로 B의 출력이 나온다. 
    // 매우 안좋은 코드. 버그 유발코드. 찾기도힘듬.
}