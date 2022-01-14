// 49_메멘토.cpp
#include <iostream>
#include <vector>
using namespace std;

// 캡슐화 정책을 깨뜨리지 않고, 객체 상태 저장과 복원의 기능을 제공한다.
// => 메멘토 패턴
// => "저장해야 하는 상태를 별도의 클래스를 통해 캡슐화"

class User
{
    int level;
    int x;
    int y;
    int exp;

    struct MementoState
    {
        int level;
        int x;
        int y;
        int exp;
    };

    std::vector<MementoState*> saved;

public:
    // 저장된 시점에 대한 토큰을 반환한다.
    int Save() 
    { 
        MementoState* state = new MementoState{level, x, y, exp};
        saved.push_back(state);

        return saved.size() - 1;
    }

    // 토큰을 통해 해당 시점으로 복원이 가능하다.
    void Load(int token) 
    { 
        MementoState* state = saved[token];

        level = state->level;
        x = state->x;
        y = state->y;
        exp = state->exp;
    }
    void SetLevel(int l){ level = l; }
    void SetXY(int a, int b)
    {
        x = a;
        y = b;
    }
    void SetExp(int e) { exp = e; }

    void Print() const
    {
        cout << level << ", " << x << ", " << y << ", " << exp << endl;
    }
};

int main()
{
    User user;
    user.SetLevel(10);
    user.SetXY(0, 50);
    user.SetExp(1000);
    user.Print();

    int token = user.Save();
    user.SetLevel(20);
    user.SetXY(0, 0);
    user.SetExp(0);
    user.Print();
    
    user.Load(token);
    user.Print();
}