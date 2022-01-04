// 5_function5.cpp
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}
// gcd 함수를 double에 대해서 사용할 수 없도록 하고싶다.
// 1) 의도적으로 함수의 선언부만 제공한다.
//  => 링킹 오류를 통해 실행 파일 생성이 금지된다.
//  => 링킹 오류는 분석이 어렵다.
// double gcd(double a, double b); // 핵심: 선언만 한다.
// 2) C++11 - delete function
//  => 함수를  삭제하는 문법
//  => 컴파일 오류가 발생한다.

double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(2, 10) << endl;
    cout << gcd(2.2, 4.3) << endl; // warning을 발생 오류는 뜨지않음
    // double이 int로 암묵적인 형변환되서 동작한다.
    // => 동작하면 안되는 코드이다.
}
