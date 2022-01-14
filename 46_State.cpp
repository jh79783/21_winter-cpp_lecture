// 46_State.cpp
#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화

class Character
{
    int gold;
    int item;

public:
    void Run() { cout << "Run" << endl; }
    void Attack() { cout << "Attack" << endl; }
};

int main()
{
    Character c;
    c.Run();
    c.Attack();
}
