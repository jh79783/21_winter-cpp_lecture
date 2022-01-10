
// 멤버 함수 포인터
#include <iostream>
using namespace std;

void foo()
{
    printf("foo\n");
}

class Dialog
{
public:
    void Close()    // void Close(Dialog* const this)
    {
        cout << "Dialog close" << endl;
    }

    static void foo()   // void foo()
    {
        cout << "Dialog foo" << endl;
    }
};

// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을 수 없다.
// 2. 일반 함수 포인터에 정적 멤버 함수의 주소를 담을 수 있다.
// 3. 멤버 함수 포인터 타입을 별도로 제공한다.

int main()
{
    Dialog dig;
    dig.Close();
    // 멤버 함수 호출은 객체가 필요하다.

    // void(*f)() = &Dialog::Close;
    
    // 멤버 함수 포인터를 만드는 방법
    void (Dialog::*mp)() = &Dialog::Close;
    // (*mp)(); // error!
    // => 객체가 필요하다.

    // .* : 멤버 함수 포인터 참조 연산자
    (dig.*mp)();

    // ->* : 객체가 포인터인 경우 멤버 함수 포인터 참조 연산자.
    Dialog* pDialog = new Dialog;
    (pDialog->*mp)();

    void(*f)() = &Dialog::foo;
    (*f)();

    // void(*f)() = &foo;
    // (*f)();
}