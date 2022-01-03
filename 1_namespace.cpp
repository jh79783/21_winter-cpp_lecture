// 1_namespace.cpp

// 이름중복을 피하기 위해 C에서는 접두사를 붙임
// ex) a_foo, b_foo

// C++에서는 namespace를 사용

// 목적
// 1) 이름 충돌을 해결할 수 있다.
// 2) 프로그램의 각 요소를 관련된 요소끼리 그룹화 할 수 있다.

# include <iostream>

namespace Audio
{
    void init() {std::cout<< "Audio::init" << std::endl;}
}

namespace Video
{
    void init() {std::cout<< "Video::init" << std::endl;}
}

void init()
{
    std::cout << "Global init" << std::endl;
}

int main()
{
    // Audio안에 있는 init함수 실행
    Audio::init();
    // Video안에 있는 init함수 실행
    Video::init();

    init();
}


