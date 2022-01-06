#include <iostream>
using namespace std;

// 상속과 생성자 / 소멸자
class Base
{
public:
    Base() { cout << "Base()" << endl; }
    Base(int a) { cout << "Base(int)" << endl; }

    ~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
public:
    // 원리: 컴파일러는 자식 클래스의 생성자에서 초기화 리스트를 통해 부모의 기본 생성자를 호출하는 코드를 삽입한다.
    Derived() { cout << "Derived()" << endl; }

    // 컴파일러에서 자동으로 다음과 같은 코드를 호출한다.
    // Derived() : Base() { cout << "Derived()" << endl; }

    // int 인자를 갖는 Base생성자를 호출하고 싶으면 다음과 같이 작성한다.
    // Derived() : Base(42) { cout << "Derived()" << endl; }
    
    ~Derived() { cout << "~Derived()" << endl; }
    // ~Base();
    // 컴파일러가 자동으로 삽입해서 호출해준다.
};

int main()
{
    Derived d;
}