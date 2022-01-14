// 46_State4.cpp
#include <iostream>
using namespace std;

// 아이템 상태에 따른 동작의 변화
// 방법 3. 인터페이스 기반 클래스로 뽑아낸다.

struct ItemState
{
    virtual ~ItemState() { }

    virtual void Run() = 0;
    virtual void Attack() = 0;
};

class Character
{
    // int gold;
    // int item;
    ItemState* state = nullptr;

public:
int gold;
    void SetState(ItemState* p) { state = p; }

    void Run() 
    { 
        if (state) 
            state->Run();
    }
    void Attack() 
    { 
        if (state)
            state->Attack();
    }
};

// 다양한 아이템의 상태에 따른 동작을 정의한다.
class FastRunState : public ItemState
{
public:
    void Run() override { cout << "Fast Run" << endl;}
    void Attack() override { }
};

class SlowRunState : public ItemState
{
public:
    void Run() override { cout << "Slow Run" << endl;}
    void Attack() override { }
};

int main()
{
    FastRunState fs;
    SlowRunState ss;

    Character c;
    c.gold = 100;

    c.SetState(&fs);
    cout << c.gold << endl;
    c.Run();
    
    c.SetState(&ss);
    c.Run();
}
