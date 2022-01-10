#include <iostream>
using namespace std;

// 예외(exception) - 오류 처리
// 1. C 언어의 오류 처리 방법
//  > 반환값을 통해 처리
// 문제점
// 1) 반환된 값이 실패를 나타내는 것인지, 연산의 결과인지 구분하기 어려울 수 있다.
// 2) 함수가 오류를 반환할 때, 오류를 반드시 처리하라고 강제화할 방법이 없다.

int foo(int a)
{
    if (a < 0)
    {
        return -1;  // 실패할 경우, 약속된 값을 반환한다.
    }
    return 0;
}

int goo(int a)
{
    if (a < 0)
    {
        throw 1; // 실패할 경우, 예외를 던진다.
                // 반환값(return)과 실패(throw)의 전달이 분리된다.
    }
    return 0;
}

#if 0
int main()
{
    int ret1 = goo(-100);
    // 함수가 예외를 던지면 호출자는 반드시 예외를 처리해야 한다.
    // 예외를 처리하지 않는 경우, 프로그램은 비정상 종료처리 된다.

    int ret2 = foo(-100);
    if (ret2 == -1)
    {
        printf("foo 함수가 실패하였습니다.\n");
    }
}
#endif

// 예외 처리 방법
//  => try-catch 블록을 이용한다.,
int main()
{
    try
    {
        int ret1 = goo(-100);
        cout << "result: " << ret1 << endl;
    }
    catch (int n) // int형 예외를 catch한다.
    {
        cout << "int 오류 발생" << endl;
    }
    catch (double d) {} // double형 예외를 catch한다.
    catch (...) {}// ...은 모든 종류의 예외를 catch할 수 있다.

    //예외가 catch되면 이후의 코드는 정상적으로 동작한다.
    cout << "main end.." << endl;
}
