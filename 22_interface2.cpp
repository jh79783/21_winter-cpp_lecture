// 22_interface2.cpp
#include <iostream>
using namespace std;

// 1. OCP사용하기 힘듬
class Camera
{
public:
    void StartRecord()
    {
        cout << "StartRecord" << endl;
    }

    void StopRecord()
    {
        cout << "StopRecord" << endl;
    }
};

class HDCamera
{
public:
    void StartRecord()
    {
        cout << "[HD]StartRecord" << endl;
    }

    void StopRecord()
    {
        cout << "[HD]StopRecord" << endl;
    }
};
// Car 클래스는 Camera 타입에 강하게 결합되어 있다.
// => "강한 결합": 어떤 클래스를 사용할 때, 구체적인 타입에 의존하는 것을 의미한다.
// => 해결 방법: 약한 결합을 만든다.
class Car
{
private:
    Camera* pCamera;

public:
    Car(Camera* p)
    : pCamera(p)
    {}

    void Start()
    {
        pCamera->StartRecord();
    }

    void Stop()
    {
        pCamera->StopRecord();
    }
};

// OCP: 개방 폐쇄 원칙(Open Close Principle)
// - 코드 수정에는 닫혀 있고, 확장에는 열려 있어야 한다.
// : 새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.

int main()
{
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();
}