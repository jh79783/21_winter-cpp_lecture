// 48_Bridge.cpp
#include <iostream>
using namespace std;

struct MP3
{
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;
    // 인터페이스의 문제점
    // : 새로운 요구사항의 확장이 어렵다.
    // => 인터페이스의 구현부(SmartPhone)와 인터페이스(MP3)를 분리해서 상호 독립적인 업데이트가 가능하게 하자.
    //      : Bridge Pattern
};


class MP3Bridge
{
    MP3* pImpl; // pointer to implementation 구현을 가르키는 부분
    // pImple Idioms
    // 1. 컴파일러 방화벽
    // 2. 컴파일 속도 최적화
    // => Exceptional C++ 책
public:
    MP3Bridge(MP3* p) : pImpl(p)
    {

    }

    void Play() { pImpl->Play(); }
    void Stop() { pImpl->Stop(); }

    void PlayOneMinute()
    {
        pImpl->Play();
        cout << "1분 후" << endl;
        pImpl->Stop();
    }
};

// 사용자가 인터페이스를 직접 사용하게 하지 말고, 중간층(Bridge)를 도입하면, 변화에 쉽게 대응할 수 있다.
class Person
{
    MP3Bridge* mp3;
public:
    Person(MP3Bridge* p)
    : mp3(p)
    {

    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
        mp3->PlayOneMinute();
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

int main()
{
    SmartPhone phone;

    MP3Bridge mp3(&phone);
    Person person(&mp3);

    person.PlayMusic();
}