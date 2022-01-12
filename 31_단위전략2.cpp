#include <iostream>
using namespace std;

// Template 기반의 정책 교체
// => Policy Based Design(단위 전략)
// 장점: 가상함수가 아니라 인라인 함수이다.
//       호출에 따른 성능저하가 없다.
// 단점: Template 인자이므로, 실행 시간에 정책 교체가 불가능하다.
//       컴파일 할때 정책이 결정된다.
// => 정책을 담은 코드를 컴파일 시간에 생성하는 기술
//  : C++ 표준 라이브러리의 핵심 설계 철학

// 스레드의 정책을 가지는 정책 클래스를 만든다.
class SingleThread
{
public:
    void Lock() {}
    void Unlock() {}
};

class MultiThread
{
public:
    void Lock() { cout << "동기화 시작" << endl; }
    void Unlock() { cout << "동기화 종료" << endl; }
};

template <typename T, typename ThreadModel = SingleThread>
class List : public ThreadModel
{
public:
    void push_front(const T& a)
    {
        ThreadModel::Lock();
        cout << "데이터 삽입" << endl;
        ThreadModel::Unlock();
    }
};

List<int, MultiThread> s1;


int main()
{
    // List<int, SingleThread> s2;
    List<int> s2;
    s1.push_front(10);
    s2.push_front(20);
}

// 동기화를 템플릿으로 제공
// lock과 unlock이 정적바인드 제공 -> 인라인으로 제공할 수 있다.
