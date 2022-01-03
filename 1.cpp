
/*
# include <stdio.h>

int main()
{
    printf("Hello, C\n");
}
*/

// 1. C++ 확장자
//      .cpp -> 가장많이 사용(일반적으로), .cc -> 두번째로 사용(구글에서 많이), .cxx, .cp, .c++

// 2. C++ 컴파일러
//      1) clang++
//      2) g++
//      3) Microsoft C++ Compiler
//      1, 2번 사용할 것

// 3. 표준(Standard)
//      C++ 1.0 - 98/03
//      C++ 2.0(현업) - 11/14: Modern C++
//      C++ 3.0 - 17/20

// C++ vs C

// C
/*
# include <stdio.h>

int main()
{
    printf("Hello, C\n");
}
*/

# if 0
// C++
# include <iostream>
// C++ 표준 헤더: 헤더 파일의 확장자가 없는 경우가 많다.

int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif



// C++
# include <iostream>
// C++ 표준 헤더: 헤더 파일의 확장자가 없는 경우가 많다.

// 만약 printf를 사용하고 싶다면 #include <stdio.h> -> C style헤더, C++에서도 사용 가능하다.
#include <cstdio>   // C++ 에서는 앞에 c를 붙이고 .h를 제거한 형태를 권장한다.

int main()
{
    printf("Hello, C\n");
    std::cout << "Hello, C++" << std::endl;
}




