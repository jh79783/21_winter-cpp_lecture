// 1_namespace2.cpp
#include <iostream>
#if 0 
// 1. 전체 이름을 사용하는 방법
//      : 이름공간과 함수의 이름을 사용한 방법
//      ex) std::cout,, std::endl, std::printf

int main()
{
    std::cout << "Hello, cpp1" << std::endl 
              << "Hello, cpp2" << std::endl;
}
#endif

#if 0
// 2. using 선언(decclaration)을 사용하는 방법
using std::cout;
using std::endl;

int main()
{
    cout << "Hello, cpp1" << endl 
         << "Hello, cpp2" << endl;
}
#endif

// 3. using 지시어(directive)를 사용하는 방법
#include <algorithm> // -> count와 충돌할 가능성이 있다.
using namespace std; // -> 이름충돌을 유발할 수 있기 때문에 사용하면 안된다.

int count;
int main()
{
    count = 10; // -> 전역변수의 count인지, algorith에 있는 count인지 컴파일러가 헷갈려한다.
    cout << "Hello, cpp1" << endl 
         << "Hello, cpp2" << endl;
}

// 2, 3번을 사용하는 것보다 1번의 방법을 권장한다.
