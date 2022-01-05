// 14_initilize_list.cpp
//  : 초기화 리스트

#include <iostream>
using namespace std;

class Point
{
    int x, y;
    const int c;
    int &ra;

public:
    // 아래 처럼 사용하는 것은 대입이다.
    /*
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    */

    // 초기화 리스트: 멤버 데이터의 값을 초기화하는 문법
    // 변수 선언 순서대로 초기화 되기 때문에 혼란을 방지하기 위해 선언 순서대로 적어주는 것이 좋다.
    Point(int a, int b) : x(a), y(b), c(42), ra(a)
    {
        // ra = a;
        // c = 10; 
        // - 반드시 초기화 되어야하기 때문에 초기화 리스트를 사용한다.
    }
};

class Rect
{
    Point p1;

public:
    // 기본 생성자가 제공되지 않는 멤버 데이터에 대한 초기화가 필요하다.
    Rect() : p1(10, 20) {}
};

int main()
{
    // 상수, 레퍼런스 타입은 반드시 초기화가 되어야 한다.
    const int c = 10;
    int &r = 10; 

    int a = 10; //초기화



    int b;
    b = 10  //대입
}