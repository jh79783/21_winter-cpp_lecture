// 15_copy_constructor.cpp
#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point() { cout << "Point()" << endl; }
    ~Point() { cout << "~Point()" << endl; }

    Point(const Point& rhs) : x(rhs.x), y(rhs.y)
    {
        cout << "Point(const Point& rhs)" << endl;
    }
};

#if 0
int main()
{
    // 복사 생성자는 언제 호출되는가?
    // 1. 객체를 만들 때 자신과 동일한 타입으로 초기화되는 경우 호출된다.
    Point p1;       // Point()
    Point p2(p1);   //  Point(const Point&)

    Point p3 = p1;  // Point(const Point&)
    Point p4{p1};   // Point(const Point&)
    Point p5 = {p1};    // Point(const Point&)
}
#endif

#if 0
// 1. 함수 호출시 인자를 call by value로 전달할 때
void foo(Point p)   // Point(const Point&)
{
    // ~Point() - foo함수가 끝날 때, p객체가 파괴되면서 호출된다.
}

int main()
{
    Point p1; //Point()
    foo(p1);

    // ~Point() - p1 객체가 파괴되면서 호출된다.
}
#endif

// void foo(Point p)
// 1) 복사본을 위한 추가적인 메모리 사용
// 2) 복사 생성자, 소멸자 함수 호출에 따른 오버헤드가 있다.

// 새로 만드는 것이 아니다.(메모리 할당 x)
void foo(const Point &p)   
{
}
#if 0
int main()
{
    Point p1; 
    foo(p1);
}
#endif

// 3. 함수가 객체를 값으로 반환할 때
Point p;
// Point foo()
Point &foo() // -> 임시객체에 의한 복사가 없어짐
{
    return p;
    // 이 순간 반환용 임시 객체가 생성된다.
    // p를 복사해서 만들기 때문에, 복사 생성자가 호출된다.
}

int main()
{
    foo();
    // 리턴 값으로 돌아온 객체는 p가 아니라 반환용 임시 객체가 전달된다.
    // 반환용 임시객체는 함수 호출문장 끝에서 파괴된다.
    printf("end main\n");
}
