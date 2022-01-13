#include <iostream>
using namespace std;

// 2. Template 기반 컨테이너
// 장점: 타입 안정성이 뛰어나고, 객체 뿐 아니라 표준 타입도 저장이 가능하고 꺼낼때 캐스팅이 필요하지 않다.
// 단점: 템플릿 이므로 여러 가지 타입을 동시에 사용하며느 list의 기계어 코드가 많아진다.
//       -> 코드 메모리 사용량 오버헤드가 있다.

template <typename T>
struct Node
{
    T data;
    // Node* next;  // 허용 해주긴 한다. 하지만, 아래가 맞는 코드
    Node<T>* next;

    Node(const T& a, Node* n) 
    : data(a)
    , next(n)
    {}
};

template <typename T> 
class Slist
{
    Node<T>* head;

public:
    Slist() 
    : head(nullptr) 
    {}

    void push_front(const T& a) { head = new Node<T>(a, head); }

    const T& front() { return head->data; }
};

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    int n = s.front();
    cout << n << endl;
}