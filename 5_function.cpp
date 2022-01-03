// 5_function.cpp
#include <iostream>
using namespace std;

// 1) Default parameter
//      : 함수에서 전달되는 인자가 없는 경우 기본값을 사용한다.
//      > 기본값을 지정할 때 뒤에서부터 지정해야 한다.
//      ex) void foo(int a = 10, int b, int c, int d) : X
//      ex) void foo(int a, int b, int c = 5, int d = 20) : O

// 함수를 선언과 구현으로 분리할 때는 선언부에만 기본값을 표기해야 한다.
// 기본값은 선언부를 기준으로 됨.
// 구현부에 기본값을 표기하는 것은 혼란을 발생시키는 매우 안좋은 코드
// 선언부와 구현부에 모두 기본값을 표기하면 컴파일 오류가 발생된다.
// 그럼 선언부에 기본값을 안적고 구현부에 적으면 어떻게 될까?
// 그래도 컴파일 오류가 발생된다.
// : 컴파일이 판단을 내리는 것은 선언부를 기준으로 판단을 내린다.
// 보통 선언부는 헤더파일에 작성되며 구현부는 소스파일에 작성됨.

void foo(int a, int b, int c = 5, int d = 20)

int main()
{
    foo(10, 20, 30, 40);
    foo(20, 30);
}

void foo(int a, int b, int c /* = 10 */, int d /* = 30 */)      // 사용자에게 알려주기 위한 주석, 가독성을위한 것
{
    cout << a << ", " << b << ", " << c <<", " << d << endl;
}

