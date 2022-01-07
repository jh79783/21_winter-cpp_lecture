#include <iostream>
using namespace std;

// operator(연산자)
// +,-, =, <<, >>, *, /, ...

class Point
{
private:
    int x;
    int y;

public:
    Point(int a, int b) : x(a), y(b)
    {
    }

    // friend
    // > friend로 선언된 함수나 클래스는 private 접근이 가능하다.
    friend Point operator+(const Point& lhs, const Point& rhs);
    // 값을 읽는 함수를 제공한다.
    int GetX() const {return x;}
    int GetY() const {return y;}
    
    // Point Add(const Point& rhs) const
    #if 0
    Point operator+(const Point& rhs) const
    {
        return Point(x + rhs.x, y + rhs.y);
    }
    #endif

    void Print() const
    {
        cout << x << ", " << y << endl;
    }
};

Point operator+(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y); // friend
    // return Point(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY()); // 함수 제공
}

// 연산자 오버로딩
//  : 연산자를 객체에 대해서 사용할 때,
//  약속된 함수가 호출됩니다.
int main()
{
    Point p1(1, 1);
    Point p2(1, 10);

    Point p3 = p1 + p2;
    // Point p3 = p1.operator+(p2); or Point p3 = operator+(p1, p2);
    // : 위의 형태로 번역한다.
    
    // Point p3 = p1.Add(p2);
    p3.Print();
}



#if 0
void foo()
{
    FILE* fp1 = NULL
    FILE* fp2 = NULL
    FILE* fp3 = NULL

    FILE* fp1 = fopen("a.txt", "r");
    if (fp1 == NULL)
    {
        // return ;
        goto err_fp1;
    }

    FILE* fp2 = fopen("a.txt", "r");
    if (fp2 == NULL)
    {
        // fclose(fp1);
        // return;
        goto err_fp2;
    }

    FILE* fp3 = fopen("a.txt", "r");
    if (fp3 == NULL)
    {
        // fclose(fp2);
        // fclose(fp1);
        goto err_fp3;
    }
err:
    fclose(fp3);
err_fp3:
    fclose(fp2);
err_fp2:
    fclose(fp1);
err_fp1:
    
}

#endif
