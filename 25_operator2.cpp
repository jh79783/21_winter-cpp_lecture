#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point(int a, int b) : x(a), y(b)
    {

    }

    // 일반 함수
    // friend가 붙으면 일반함수로 취급된다.
    friend Point operator+(const Point& lhs, const Point& rhs)
    {
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};
// 연산의 결과로 내부 멤버 데이터의 변경이 발생한다.
// => 멤버 함수
// 연산의 결과로 내부 멤터 데이터의 변경이 없다.
// => 일반 함수


// 주의사항
// 1. 연산자 재정의에 한개 이상의 인자는 반드시 사용자 정의 타입이어야 한다.
// 불가능, 이미 컴파일러가 제공하고 있다.
#if 0
int operator+(int a, int b) { return a + b; }
#endif
// int operator+(int a, const Point& b) { return a + b.x; }

// 2. 인자의 개수를 변경할 수 없다.
// operator+(const Point& lhs, const Point& rhs, int x) - > x
// +, -, *, / => 2개의 인자를 받는 일반 함수
//            => 1개의 인자를 받은 멤버 함수

// 3. 연산자의 우선순위를 변경할 수 없다.
// 4. 새로운 연산자를 만들 수 없다.
// 5. ::, ., .*. ?: 연산자는 재정의가 불가능하다.
// 6. =, (), [], ->, 연산자는 멤버 함수로만 만들 수 있다.

class MyVector
{
public:
    int operator[](int index) 
    {
        return 42;
    }
};


int main()
{
    MyVector v;
    cout << v[10] << endl;

    Point p1(10, 10);
    Point p2(20, 20);

    // int result = 42 + p1;
    // cout << result << endl;

    Point p3 = p1 + p2;
    // p1.operator+(p2);
    // operator+(p1, p2);
    // 컴파일러는 둘중 하나를 찾아준다.
    p3.Print();
}
