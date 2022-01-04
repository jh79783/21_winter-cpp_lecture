// 2_iostream.cpp
// > C++ 표준 입출력
// 1. C언어에서는 표준 입출력을 위해 대표적으로 사용하는 함수
//      : printf, scanf

#if 0
#include <stdio.h>

int main()
{
    int n = 0 ;
    scanf("%d", &n);    // -> %d라는 서식을 통해 입력받고

    printf("out: %d\n", n); // -> %d라는 서식을 통해 출력한다.
}
#endif


// C++에서 제공하는 표준 입출력
#include <iostream>
using namespace std; // 강의에서는 편의성을 위해 열어논것 절대로 함부로 사용하지 말것!!!

int main()
{
    int n = 0;
    cin >> n;
    // scanf("%d", &n);
    // 1. 정수 타입(서식)을 지정할 필요가 없다. - 함수 오버로딩!
    // 2. 주소를 보내지 않아도, 값이 변경된다.  - 레퍼런스
    // 3. std::cout, std::cin들의 정체는 무엇인가?
    // 4. std::endl의 정체는 무엇인가?

    // cout << "out: " << n << endl; 아래와 동일함
    cout << "cout: " << n;
    cout << std::endl;
}



