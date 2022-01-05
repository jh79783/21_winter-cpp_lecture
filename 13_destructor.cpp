// 13_destructor.cpp
#include <iostream>
using namespace std;

// 모든 객체를 생성될 때 생성자가 호출되고, 메모리에서 소멸될 때 소멸자가 호출된다.
// 1. 함수 이름은 ~클래스이름() 이다.
// 2. 반환 타입 없고, 파라미터도 존재하지 않는다.
// 3. 오버로딩이 불가능하고, 오직 한개만 제공한다.
// 4. 사용자가 소멸자를 제공하지 않으면, 컴파일러가 자동으로 제공해준다.
// 5. 생성자에서 자원을 획득한 경우, 소멸자를 통해 자원을 반납해야 한다.

//#inclulde <string.h>
#include <cstring>

// 자원
// => 메모리, 파일, 프로세스, 스레드, 락, ...
class User
{
    char *name;
public:
    User(const char* s)
    {
        cout << "메모리 할당" << endl;
        name = new char[std::strlen(s) + 1];
        strcpy(name, s);
    }

    ~User()
    {
        cout << "메모리 해지" << endl;
        delete[] name;
    }
};

int main()
{
    User user("홍길동");
}

