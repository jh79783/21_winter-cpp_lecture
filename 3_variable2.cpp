// 3_variable2.cpp
#include <iostream>
using namespace std;

struct Point 
{ 
    int x, y;
};

#if 0
int main()
{
    int n1 = 42;
    int n2(42); // C++ 초기화 문법, 허용되고 있긴 하지만 첫번째를 많이 쓴다.
    // 일반 변수는 '=' / '()'를 이용하여 초기화 한다.
    cout << n1 << ", " << n2 << endl;

    // () 초기화: 직접 초기화(direct initialization)
    // = 초기화: 복사 초기화(copy initialization)

    // 2. 배열과 구조체 초기화 방법
    Point p = {10, 20};
    int x[3] = {10, 20, 30};

}
#endif

// C++11 - Uniform initialization
// > 일관된 방법을 통해 변수를 초기화할 수 있다.
// > 데이터의 손실이 발생하는 잘못된 초기화에 대해서 오류를 발생시킨다.
// > 일반적인 초기화 방법은 경고를 나타내지 오류를 발생시키지는 않는다.
// > 데이터 초기화를 하는데에 있어 기본적인 실수를 방지해 컴파일 오류를 통해 방지할 수 있다.
int main()
{
    int n = 3.14; // warning
    int n4{3.14}; // error

    char c1 = 300; // overflow가 발생하지만 단순히 warning만을 발생시킨다.
    char c2{300}; // 컴파일에서 error가 발생한다.


    // =(등호): Copy initialization
    int n1 = {0};
    int x[3] = {1, 2, 3};
    Point p1 = {10, 20};

    // Direct initialization
    int n2{0};
    int x2[3]{1, 2, 3};
    Point p2{10, 20};
    // Direct와 Copy가 여기에서는 성능적인 차이가 없다.
    // 하지만 class같은 곳을 가게된다면 Direct가 성능적으로 좋으며 정답일 확률이 높다.
    // Copy가 무조건 나쁜것은 아니다. 필요에 의해 언제든지 사용할 수 있다.
}




