// 42_싱글톤.cpp
// Singleton Pattern
#include <iostream>
using namespace std;

// 의도: 오직 한개의 객체만 만들 수 있고, 어디에서든 동일한 방법으로 객체를 얻을 수 있게 하는 패턴
// 사용하는 이유: 프로그램 내에서 하나만 사용해야 하는 제약 사항이 있을 때 사용한다.
// 전역 객체의 문제점: 어떤 시점에 호출/파괴 되는지 알 수 없다.
// 싱글톤은 내부 객체 정적 함수를 사용하기때문에 호출/파괴 시점을 알 수 있다.

class Cursor
{
private:
    Cursor() { }    // 규칙 1. 생성자 private로 두기 -> 객체 생성을 외부에서 할 수 없다.
                    // 어떻게 객체 생성을하는지?? -> 정적 멤버 함수를 통해서 생성

    // 규칙 3의 코드 구현!!
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;  

public:
    // 규칙 2. 오직 한개만 만드는 정적 멤버 함수를 제공한다.
    static Cursor& GetInstance()
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    // Cursor c; // error!
    // Cursor* p = new Cursor; // error!

    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();

    // Cursor c3 = Cursor::GetInstance();  // 복사가 일어난다.
    // c3 = Cursor::GetInstance();         // 대입이 일어나 새로운 객체가 생성될 수 있다.
                                        // 규칙 3. 복사와 대입을 금지시킨다.

    cout << &c1 << endl;
    cout << &c2 << endl;
    // c1과 c2의 주소가 같다! => 같은 객체를 공유한다.

}
