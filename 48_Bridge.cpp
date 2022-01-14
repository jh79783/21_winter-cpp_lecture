// 48_Bridge.cpp
#include <iostream>
using namespace std;

struct MP3
{
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;
};


class Person
{
    MP3* mp3;
public:
    Person(MP3* p)
    : mp3(p)
    {

    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
    }
};

class SmartPhone : public MP3
{
public:
    void Play() override
    {
        cout << "SmartPhone Play Music" << endl;
    }
    void Stop() override
    {
        cout << "SmartPhone Stop Music" << endl;
    }
};

// SOLID(객체 지향 5대 원칙)
// 1. SRP(단일 책임 원칙): 단 하나의 책임을 가져야한다.
// 2. OCP(개방 폐쇄 원칙): 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.
// 3. LSP(리스코프 치환 원칙): 자식의 공통된 기능은 부모로부터 비롯되어야 한다.
//                          => 상속의 목적은 "다형성"이다.
// 4. ISP(인터페이스 분리 원칙): 범용 인터페이스 보다는 세분화된 인터페이스가 좋다.
// 5. DIP(의존관계 역전 원칙): "약한 결합"
//                          - 다른 클래스를 이용할 때, 구체적인 타입이 아니라 인터페이스나 추상 클래스를 이용해야한다.
//                          => 새로운 기능으로 쉽게 교체 가능하다.

int main()
{
    SmartPhone phone;
    Person person(&phone);

    person.PlayMusic();
}