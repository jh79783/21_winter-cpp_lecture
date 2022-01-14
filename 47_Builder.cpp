// 47_Builder.cpp
#include <iostream>
#include <string>
using namespace std;

// 디자인 패턴에서 변하는 것을 인터페이스 기반 클래스로 만들어서 교체하는 패턴은 3가지이다.
// 1. 전략 패턴 - 정책을 캡슐화 하는 것
// 2. 상태 패턴 - 상태 변경에 따른 동작을 정의한 클래스를 캡슐화 하는 것
// 3. 빌더 패턴 - 동일한 구축 공정으로 객체를 만들지만, 각 공정에 따라서 표현이 달라지는 객체를 만들 때 사용한다.

using Character = std::string;

// 축구 게임의 캐릭터를 만드는 공정은 변하지 않는다.
// 이런 역할을 하는 것을 디렉터라고 한다.
struct Builder 
{
    virtual ~Builder() { }

    virtual void CreateHead() = 0;
    virtual void CreateUniform() = 0;
    virtual void CreateShoe() = 0;

    virtual Character GetResult() = 0;
};


class Director
{
    Builder* pBuilder = nullptr;
public:
    void SetBuilder(Builder* p) { pBuilder = p; }

    // 순서만 바꿔주면 공정 순서에 대해 바꿀 수 있다.
    Character Construct()
    {
        // 1. 얼굴
        pBuilder->CreateHead();
        // 2. 몸통
        pBuilder->CreateUniform();
        // 3. 신발
        pBuilder->CreateShoe();

        return pBuilder->GetResult();
    }
};

// 다양한 나라의 빌더를 제공한다.
class Korea : public Builder
{
    Character c;
public:    
    void CreateHead() override
    {
        c += "검은머리\n";
    }

    void CreateUniform() override
    {
        c += "빨강 유니폼\n";
    }

    void CreateShoe() override
    {
        c += "아디다스\n";
    }

    Character GetResult() override
    {
        return c;
    }
};

class England : public Builder
{
    Character c;
public:
    void CreateHead() override
    {
        c += "노랑머리\n";
    }

    void CreateUniform() override
    {
        c += "흰색 유니폼\n";
    }

    void CreateShoe() override
    {
        c += "나이키\n";
    }

    Character GetResult() override
    {
        return c;
    }
};

int main()
{
    Korea k;
    England e;

    Director d;
    d.SetBuilder(&k);
    cout << d.Construct() << endl;

    d.SetBuilder(&e);
    cout << d.Construct() << endl;
}