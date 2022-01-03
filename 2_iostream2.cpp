// 2_iostream2.cpp
#include <iostream>
#include <iomanip> // for setw
using namespace std;

int main()
{
    int n = 42;

    cout << n << endl;
    cout << hex << n << endl; // -> 16진수로 변환
    cout << uppercase << n << endl; // -> 소문자를 대문자로 변환

    // printf("%4d", n) -> c에서의 자리수 지정 c++에서는 아래와 같이 사용
    cout << setw(4) << n << endl;
    cout << setw(4) << setfill('0') << n << endl; // -> 자리수 0으로 채우기

    cout << oct << n << endl; // -> 8진수로 변환
    cout << dec << n << endl; // -> 10진수로 변환
    // 한번 사용하면 다시 변경하기 까지 상태가 유지된다.
}