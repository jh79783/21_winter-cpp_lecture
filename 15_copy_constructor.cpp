// 15_copy_constructor.cpp
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point() : x(0), y(0) { cout << "Point()" << endl; }
    Point(int a, int b) : x(a), y(b) { cout << "Point(int, int)" << endl; }

    Point(const Point& rhs) : x(rhs.x), y(rhs.y)
    {
        cout << "Point(const Point& rhs)" << endl;
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

// 컴파일러가 사용자가 제공하지 않으면, 아래 모양의 복사 생성자를 제공한다.
// Point(const Point&)
// => 모든 멤버 데이터를 복사하는 형태로 동작한다.

int main()
{
    Point p1;           // Point()
    Point p2(10, 20);   // Point(int, int)
    Point p3(p2);       // Point(Point)
    
    p2.Print();
    p3.Print();
}