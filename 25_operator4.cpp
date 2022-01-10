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

    friend ostream& operator<<(std::ostream& os, const Point& p);
};

ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << p.x << ", " << p.y;
}

int main()
{
    Point p1(10, 20);

    cout << p1 << endl;
    // cout.operator<<(p1)
    // => cout.operator<<(const Point&)
    // => 멤버 함수는 ostream 클래스를 수정할 수 없으므로 제공할 수 없다.

    // operator<<(cout, p1)
    //  : 위의 형태로 일반 함수를 만들어야 한다.
    // => operator(std::ostream& os, const Point& p)
}