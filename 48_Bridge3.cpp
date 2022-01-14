// 48_Bridge.cpp
#include <iostream>
using namespace std;

struct MP3
{
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // 인터페이스에 기본 구현을 제공하는 것으로 많은 문제가 해결된다.
    virtual void PlayOneMinute()
    {
        Play();
        cout << "1분 후" << endl;
        Stop();
    }
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
    Person person(&phone);

    person.PlayMusic();
}