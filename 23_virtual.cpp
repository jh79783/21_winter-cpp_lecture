// 23_virtual.cpp
#include <iostream>
using namespace std;

class Animal
{
    int age;
public:
    virtual ~Animal() { }
    virtual void Cry() { cout << "Animal Cry" << endl; }
};

class Dog : public Animal
{
    int color;
public:
    void Cry() override { cout << "Dog Cry" << endl; }
};

// 1. 클래스가 가상 함수를 1개라도 소유하고 있다면, 객체의 크기가 8바이트(포인터 크기)가 증가한다.
//  > 객체 내부에 가상 함수 테이블을 가르키는 포인터가 추가되기 때문이다.
int main()
{
    Animal a;
    cout << sizeof(a) << endl;  // 4 -> virtual 쓰면 16

    Dog d;
    cout << sizeof(d) << endl; // 8 -> virtual 쓰면 16
}