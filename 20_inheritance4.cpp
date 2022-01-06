#include <iostream>
using namespace std;

class Animal
{
    public:
protected:
    Animal() {}
};

class Dog : public Animal
{
    public:
    // Dog() {}
    Dog() : Animal() {}
};

// protected 생성자의 의도
// "자신 타입의 객체는 생성할 수 없지만, 파생 클래스 타입의 객체는 생성할 수 있다."

int main()
{
    Animal a;   // 생성자를 protected로 만드는 순간 error 발생
    Dog d;      // ok!
                // Dog의 생성자를 먼저 호출하고, Dog의 생성자 안에서 Animal 생성자를 호출한다.
                // 파생 클래스에서는 기반 클래스의 protected 멤버에 접근이 가능하다.
}