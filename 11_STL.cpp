// 11_STL.cpp
#include <iostream>
using namespace std;

// Standard Template Library
// => C++에서 제공하는 템플릿 기반의 라이브러리
// => 자료구조(컨테이너, 컬렉션)

// 연속된 메모리 형태의 선형적인 자료 구조
// => 장점: 임의 접근이 빠르다.                -O(1)
// => 단점: 중간 삽입, 삭제시 비용이 발생한다.  -O(N)

// 연결 리스트 기반의 선형적인 자료 구조
// => 장점: 중간 삽입, 삭제가 빠르다            -O(1)
// => 단점: 탐색이 상대적으로 느리다.           -O(N)

// 우선순위 큐
//  => stack - <stack>
//     queue - <queue>

#include <stack>
#include <vector>

#if 0
int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int e: v)
    {
        std::cout << e<< std::endl;
    }

    std::stack<int> s;
    s.push(10);
    s.push(20);

    // C++은 pop() 연산이 분리되어 있다.
    // - 가장 마지막 요소를 체크하는 함수 : top()
    // - 스택에서 요소를 제거하는 함수    : pop()
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}
#endif

// 탐색
// 1. Tree          => <map>
//  - 탐색: O(logN)
//  - 정렬: O(N)

// 2. Hashtable     => <unordered_map>(순서가없는)
//  - 탐색: O(1)
//  - 데이터 저장되는 순서가 다르다.
//   => 퀵소트: O(NlogN)

// map => 키-값 쌍으로 이루어진 데이터
//      C++ / Jave
//      C# / Swift - Dictionary 라고도 부른다.

#include <map>
int main()
{
    std::map<std::string, std::string> data;
    data["홍길동"] = "010-1234-5678";
    data["이순신"] = "010-2222-3333";

    cout << data["홍길동"] << endl;
}
