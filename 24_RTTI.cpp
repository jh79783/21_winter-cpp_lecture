// 24_RTTI.cpp

#include <iostream>
using namespace std;

// RTTI(Run-Time Type Information)
// 개념: 실행 시간에 타입을 조사하는 기술
class Car
{
public:
    virtual ~Car() {} // RTTI에서 필요하다...!
    
    int color = 200;
};

// 부모 소멸자가 가상이면 자식 클래스의 소멸자도 가상이다.
class Sedan : public Car
{
public:
    int speed = 100;
};

void Go(Car* p)
{
    // p가 Sedan이면 speed를 출력하고 싶다.
    // 체크 없이 사용할 경우
    Sedan* s = static_cast<Sedan*>(p);  // static은 정확한 타입인지 체크할 수 없다.
    // cout << "Speed: " << s->speed << endl;

    // RTTI 사용법
    // - 모든 타입은 자신의 타입의 정보를 가지고 있는 type_info 구조체를 갖고있다.
    // : typeid 연산자를 통해 얻어올 수 있다.
    // 1) 객체를 통해서 얻을 수 있다.
    const type_info& t1 = typeid(*p);
    // cout << t1.name() << endl;

    // 2) 클래스 타입을 통해서 얻을 수 있다.
    const type_info& t2 = typeid(Sedan);
    // => 만약 동일한 타입이면, t1과 t2가 동일하다.
    if (t1==t2)
    {
        cout << "p는 Sedan 타입입니다." << endl;
        Sedan* s = static_cast<Sedan*>(p);
        cout << s->speed << endl;
    }
    else
        cout << "p는 Sedan 타입이 아닙니다." << endl;

    // 문제점: 
    // 1. type_info를 통해 얻을 수 있는 문자열 이름이 표준화에 포함되지 않았다.
    //  > 컴파일러마다 다른 결과가 나온다.

    // 2. type_info는 가상함수 테이블 안에 존재한다.
}

void Go2(Car* p)
{
    // 실행 시간에 하위 캐스팅을 타입 체크를 수행하면서 하고 싶다.
    // => dynamic_cast를 사용
    //  : 가상함수 테이블을 이용한다.

    Sedan* s1 = static_cast<Sedan*>(p);
    Sedan* s2 = dynamic_cast<Sedan*>(p);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << endl;

    if (s2 != nullptr)
    {
        cout << "speed: " << s2->speed << endl;
    }
}

int main()
{
    Car c;
    Sedan s;

    // Go(&c);
    // Go(&s);

    Go2(&c);
    Go2(&s);
}

