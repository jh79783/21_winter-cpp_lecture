// 46_State2.cpp
#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화
// 방법 1. 아이템 종류에 따른 조건 분기 방식
//  문제점: OCP를 만족하지 않는다.
//      - 신규 아이템이 추가되면, 조건 분기문이 계속 추가되거나 수정되어야 한다.

class Character
{
    int gold;
    int item;

public:
    void SetItem(int i) { item = i;}

    void Run()
    {
        if (item == 1)
            cout << "Run" << endl;
        else if (item == 2)
            cout << "Fast Run" << endl;
        else if (item == 3)
            cout << "Slow Run" << endl;
    }
    void Attack() { cout << "Attack" << endl; }
};

int main()
{
    Character c;
    c.SetItem(2);
    c.Run();
    c.Attack();
}
