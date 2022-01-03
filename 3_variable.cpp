// 3_variable.cpp
// > C++ 변수의 특징

#include <iostream>
using namespace std;

#if 0
int main()
{
    int n1 = 0xfa;
    //       1111 1010
    // > C++11 부터는 2진수 표기가 가능하다.
    //   C++11 부터는 자릿수 표기도 가능하다.
    //int n2 = 0b -> 8진수
    int n2 = 0b11111010;
    // int n2 = 0b1111'1010; // -> '를 통해 자릿수 표기

    cout << n1 << ", " << n2 << endl;

    int n3 = 100;
    // C언어에서는 허용되지 않는 경우가 많다.
    // C++에서는 어떤 위치에서든 변수를 정의할 수 있다.
}
#endif


// 구조체(struct)
// -> 사용자 정의 타입을 만들때 사용

struct Point
{
    // C++11 부터는 구조체를 만들 때, 초기값 지정이 가능하다.
    int x = 10;
    int y = 20;
};

int main()
{
    // 구조체 변수를 만들때
    struct Point p1; // C언어에서 
    Point p2; 
    // C++에서는 struct를 붙이지 않아도 된다.
    cout << p1.x << ", " << p1.y << endl;
}

// g++ 1.cpp -std=c++11로 지정해준다면 warning을 띄우지 않을 수 있다. 
// or clang++ 1.cpp -std=c++11 / -std=c++14

