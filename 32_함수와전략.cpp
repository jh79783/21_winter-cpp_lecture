// 32_함수와전략.cpp
#include <iostream>
using namespace std;

// 버블소트 - 성능이 매우 좋지 않아 실제로 사용하진 않지만, 쉽게 구현할 수 있다.
// 핵심: 변하지 않는 전체 알고리즘에서 변해야 하는 정책 코드는 분리되어야한다.
// > 일반 함수에서는 변하는 것을 함수 인자(함수 포인터)로 뽑아내면 된다.

// 배열이 굉장히 많을 경우 함수 호출에 따른 오버헤드가 발생한다.
// 해결: inline?
// -> 함수포인터를 담아서 함수에 넘기면 인라인을 할 수 없다.

inline bool cmp1(int a, int b) { return a > b; } // 오름차순
inline bool cmp2(int a, int b) { return a < b; } // 내림차순

// void Sort(int* x, int n)
void Sort(int* x, int n, bool (*cmp)(int a, int b))
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
    // Sort(x, 10);
    Sort(x, 10, &cmp1);
    // Sort(x, 10, &cmp2);

    for (int e : x)
    {
        cout << e << endl;
    }
}