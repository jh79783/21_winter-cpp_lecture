// 46_State3.cpp
#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화
// 방법 2. 변하는 것을 가상함수로 만드는 방식
//  => 아이템에 따라 동작이 변한다.
//  => Template Method Pattern

class Character
{
    int gold;
    int item;

public:
    virtual void Run() { cout << "Run" << endl; }
    virtual void Attack() { cout << "Attack" << endl; }
};

// 아이템의 획득에 따라 동작을 변경하기 위해 상속을 이용한다.
class FastRunCharacter : public Character
{
public:
    void Run() override { cout << "Fast Run" << endl; }
};

class SlowRunCharacter : public Character
{
public:
    void Run() override { cout << "Slow Run" << endl; }
};

int main()
{
    Character* current;
    
    Character c;
    current = &c;
    current->gold = 100;
    current->Run();

    FastRunCharacter fc;
    current = &fc;
    cout << current->gold << endl;  // 상태에 대한 부분이 공유되지 않는다.
    // 동작 뿐만 아니라 상태도 변경되어야한다. Gold는 공유되어야하는 부분이다.
    current->Run();

    SlowRunCharacter sc;
    current = &sc;
    current->Run();
}
