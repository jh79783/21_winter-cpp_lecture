#include <iostream>
#include <cstring>
using namespace std;

class User
{
    char *name;
    int age;
    // 2. 참조 계수 기반
    // 참조 계수 관리할 수 있는 변수
    int *ref;

public:
    User(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        //---
        ref = new int; // 참조 계수용 변수를 할당하고
        *ref = 1;       // 1로 초기화 한다.
    }

    // 3. 복사 금지
    User(const User &rhs) = delete;
    /*
    User(const User &rhs)
    : name(rhs.name), age(rhs.age), ref(rhs.ref)
    {
        ++(*ref);
    }

    ~User()
    {
        // 참조 계수를 감소하고, 0이 되면 메모리를 해제한다.
        if (--(*ref) == 0)
        {
            delete[] name;
            delete ref;
        }
    }
    */

/*
// 1. 깊은 복사
public:
    User(const char *n, int a) : age(a)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // 컴파일러가 제공하는 복사 생성자의 형태
    // User(const User &rhs) : name(rhs.name), age(rhs.age) {}

    // 1. 깊은 복사 버전 복사 생성자
    User(const User &rhs) : age(rhs.age)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    ~User()
    {
        delete[] name;
    }
*/
};

int main()
{
    User user("Yoon", 42);

    User user2(user);
}

// 클래스 내부에 포인터가 있고 동적 메모리 할당된 메모리가 있다면
// 컴파일러가 기본으로 제공하는 복사 생성자는 얕은 복사 현상으로 인해 문제가 발생한다.
// 사용자는 반드시 복사 생성자를 직접 제공해야 한다.
// > 제공 하는 방법 3가지

// 1. 깊은 복사 - 동일한 값 메모리에 추가적으로 할당
// user1: [name] ---> [YOON\n]
// user2: [name] ---> [YOON\n]
// 2. 참조 계수 기반 수명 관리  - 참조 갯수를 count해서 관리하는 것
// 3. 복사 금지
