// 3_variable3.cpp
#include <iostream>
using namespace std;

// int a; -> a type: int
// int x[10] -> x type: int[10] -> int가 10개짜리 배열인 type
// int y[3] - > y type: int[3] -> int가 3개짜리 배열인 type
// -> 이름을 뺀 나머지가 type이다.
// x와 y는 다른 타입이다.

// 함수에서는 포인터로 받는 이유는?
// C / C++ 함수는 배열을 인자로 전달받을 때 decay(부식)를 수행한다.
// : 배열의 첫번째 원소의 시작 주소가 전달됩니다. 라는 규칙때문에 그렇다.
// > 배열을 전달받는 함수는 반드시 길이에 대한 추가정보를 인자를 통해 전달해주어야 한다.
void foo(int *x, int n)
{
    for (int i = 0; i < n; ++i)
        cout << x[i] << endl;
}

// int z[3][5];
// 이름기준 오른쪽으로 해석되어야 하기 떄문에 3개짜리 배열이다
// > [  int[5]  ] [  int[5]  ] [  int[5]  ]

// int *p[5]; > 오른쪽의 우선순위가 높기때문에 포인터 배열(40바이트) - [int*][int*][int*][int*][int*]
// int (*p)[5]; > 배열 포인터(8바이트)


//해석 3개에 대한 해석 오류 3이 5로 바꾸어야함 위에꺼가 다시 해석한 것
// int 3개짜리 배열의 point
// : int(*p)[3]
// int*p[3] vs int(*p)[3]
// int*p[3] -> 3개짜리 포인터 배열 : 이름을 기준으로 뒤에서 부터 해석됨(배열)
// int(*p)[3] -> int 3개짜리를 가르키는 포인터: 배열 포인터(포인터)

void goo(int (*p)[5])
{

}
#if 0
int main()
{
    int z[3][5];
    // z의 type: int[3][5]
    goo(z)


    int y[3] = {1, 2, 3};
    // main내에서 y의 크기는 12인데 함수 안에서는 8로 변함 -> 주소로 전달되기 때문에 : decay
    // > 배열이 함수로 전달될때 인자가 변수의 시작 주소가 전달되는 것
    foo(y, 3);
    // int a = y[0];
    auto a = y[0];
    auto p = &y[0]; // integer point type으로 결정된다. c++11부터 적용
    // auto를 사용하면, 우항의 타입과 동일한 타입으로 컴파일 타임에 결정된다.

    // auto xx; > 사용 불가. 반드시 우항이 필요하다.

    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(x, 10);
}
#endif


// typedef
// : 기존 타입의 별칭을 만들어서 사용할 수 있다.
// > 복잡한 타입을 간결하게 사용할 수 있다.
// x: [int[3]][int[3]]

void hoo(int (*p)[3])
{
}
// typedef를 통해 복잡한 배열 포인터를 간단히 사용할 수 있다.
typedef int (*POINTER)[3];
void goo(POINTER p)
{
}

// C++11에서는 typedef 말고, using을 통해 타입의 별칭을 만들 수 있다.
// C에서는 typedef를 사용해야하지만 C++11에서는 using을 통해 좀더 명확하게 확인할 수 있다.
// 장점
// 1) 가독성이 좋다
// 2) typedef는 템플릿의 문법에서는 사용할 수 없다.
using POINTER2 = int (*)[3];
void xoo(POINTER2 p)
{
}

int main()
{
    int x[2][3];
    hoo(x);
    goo(x);
    xoo(x);
}