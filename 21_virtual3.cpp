// Upcasting 활용
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

class Cat : public Animal {}; 

// 1. 동종(같은 부모를 갖는 클래스)을 처리하는 함수를 만들 수 있다.

// bool IsOlderThan10YearsOld(Dog* p)
// {
//     return p->age >10;
// }

// bool IsOlderThan10YearsOld(Cat* p)
// {
//     return p->age >10;
// }

// 부모의 동일한 속성을 사용하기 떄문에 하나의 함수로 처리할 수 있다.
bool IsOlderThan10YearsOld(Animal* p)
{
    return p->age >10;
}
#if 0
int main()
{
    Dog d;
    Cat c;

    IsOlderThan10YearsOld(&d);
    IsOlderThan10YearsOld(&c);
}
#endif

#if 0
#include <vector>
int main()
{
    vector<Dog*> v1 // Dog타입만 보관할 수 있다.
    
    Dog d;
    Cat c;
    v1.push_back(&d);
    // v1.push_back(&c); // - error!
    
    // 2. 동종을 보관하는 컨테이너를 만들 수 있다.
    vector<Animal*> v2; // Animal의 모든 파생 클래스 타입도 보관이 가능하다.
    v2.push_back(&d);
    v2.push_back(&c);
}
#endif

// 파일과 폴더의 공통의 기반 클래스를 만든다.

// 폴더 안에는 파일도 있고 폴더도 있다.
// > 파일과 폴더의 공통의 부모가 존재하면, 하나의 컨테이너를 통해 관리하는 것이 가능하다.
class Item {};

class File : public Item {};
class Folder : public Item 
{
    vector<Item*> v;
};
