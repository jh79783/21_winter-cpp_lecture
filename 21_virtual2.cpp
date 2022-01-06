// 21_virtual2.cppp
#include <iostream>
using namespace std;;
class Animal
{
public:
    int age;

};

class Dog : public Animal
{
public:
    int color;
};

class Cat : public Animal {};   // -> 상송받는게 여러개일 경우 명확하지 않기 때문에 다운캐스팅시에는 명시적인 캐스팅이 필요하다.

int main()
{
    // 업캐스팅
    Animal *p1 = new Dog;

    Dog d;
    Animal *p2 = &d;

    //다운캐스팅
    // 부모의 포이인터 타입을 자식의  포인터 타입으로의 암묵적 변환은 허용되지 않는다.
    // => 명시적인 캐스팅이 필요하다.
    Dog *pDog = static_cast<Dog*>(p1);
}
