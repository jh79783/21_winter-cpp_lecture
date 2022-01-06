#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void Cry() { cout << "Animal cry" << endl; }    // 1
};

class Dog : public Animal 
{
public:
    //기반 클래스의 멤버 함수를 자식 클래스에서 다시 재정의할 수 있다.
    // => 함수 오버라이딩
    virtual void Cry() { cout << "Dog cry" << endl; }       // 2
    // 자식이 재정의하는 부모의 멤버 함수는 반드시 가상 함수여야 한다.
};

// C++ 함수 바인딩
// - 어떤 함수를 호출할지 결정하는 것
//  p -> Cry()의 후보
//      * Animal::Cry()
//      * Dog::Cry()
// 정적 바인딩: Animal::Cry()
//  - 컴파일러가 p의 타입(Animal*)을 보고 Animal의 함수를 호출하도록 기계어를 생성한다.
// 동적 바인딩: Dog::Cry()
//  - 컴파일러가 실행 시간에 p가 어떤 타입인지를 조사해서, 해당 타입의 호출하도록 하는 기계어를 생성한다.
//  - 실행 시간에 결정되는 p의 타입에 따라 호출되는 함수가 달라진다.
// 동적 바인딩을 만들어주기 위해 멤버 함수에 virtual을 입력한다.
int main()
{
    Animal a;
    Dog d;

    //Upcasting
    Animal* p = &d;
    p->Cry(); // 1? 2?

    a.Cry();
    d.Cry();
}

// 함수 오버로딩: 동일한 함수를 인자를 다르게 하여 정의하는 것
// 함수 오버라이딩: 부모의 함수를 자식에서 재정의하는 것