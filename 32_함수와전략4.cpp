// 32_함수와전략4.cpp
#include <iostream>
using namespace std;

// 함수 객체 버전
struct Less
{
    inline bool operator()(int a, int b) const { return a > b; }
};

struct Greater
{
    inline bool operator()(int a, int b) const { return a < b; }
};


// 함수 버전
bool cmp1(int a, int b) { return a > b; } // 오름차순
bool cmp2(int a, int b) { return a < b; } // 내림차순

// void Sort(int* x, int n, bool (*cmp)(int a, int b)) -> 함수 포인터
//void Sort(int* x, int n, Greater cmp)
//void Sort(int* x, int n, Less cmp)

// 템플릿으로 만들면 정책을 함수 포인터로 전달가능하고, 자신만의 타입을 가지는 함수 객체도 사용할 수 있다.
// => 정책을 템플릿 인자로 전달하는 이유
template <typename T>
void Sort(int* x, int n, T cmp)
{
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // if (x[i] < x[j])
            if (cmp(x[i], x[j]))
                swap(x[i], x[j]);
        }
    }
}

int main()
{
    int x[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    Less less;
    Greater greater;
    // 1) 함수 객체로 전달
    // 장점: 정책이 호출되는 것이 아니라 인라인이 치환되어 빠르다.
    // 단점: 코드가 생성된다.
    Sort(x, 10, less);
    Sort(x, 10, greater);

    // 2) 함수 포인터 전달
    // 잠점: 한 개의 생성된 함수를 공유해서 사용 가능하다.
    //       코드 메모리 사용량이 증가하지 않는다.
    // 단점: 호출 오버헤드가 있다.
    //       인라인 치환이 불가능하다.
    Sort(x, 10, &cmp1);
    Sort(x, 10, &cmp2);

    for (int e : x)
    {
        cout << e << endl;
    }
}