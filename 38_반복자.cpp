// 38_반복자
// : Iterator Pattern
// 중요!!!!!!!!!!!!!!!!!!!!
// 컨테이너 객체를 순회하는 요소

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& a, Node* n)
        : data(a)
        , next(n)
    {
    }
};

template <typename T>
class SlistIterator
{
    Node<T>* current;
public:
    SlistIterator(Node<T>* p = nullptr)
    : current(p)
    {}

    // ++++i가 가능해야 한다.
    inline SlistIterator& operator++()
    {
        current = current->next;
        return *this;
    }
    inline T& operator*() { return current->data; }

    inline bool operator==(const SlistIterator& t)
    {
        return current == t.current;
    }

    inline bool operator!=(const SlistIterator& t)
    {
        return current != t.current;
    }

};

// 모든 컨테이너의 설계자는 자신의 처음과 끝 다음을 가르키는 반복자를 꺼내는 연산을 제공해야한다.
// => begin() / end()
// => 자신이 이터레이터 타입을 컨테이너 내부 타입의 이름을 통해 알려야 한다.

template <typename T>
class Slist {
    Node<T>* head;

public:
    Slist()
        : head(nullptr)
    {
    }

    SlistIterator<T> begin() { return SlistIterator<T>(head); }
    SlistIterator<T> end() { return SlistIterator<T>(); }

    void push_front(const T& a) { head = new Node<T>(a, head); }

    const T& front() { return head->data; }
};


#include <list>

int main()
{
    Slist<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    Slist<int>::iterator p = xfind(s.begin(), s.end(), 20);
    if (p != s.end())
    {
        cout << *p << endl;
    }
}


#if 0
int main()
{
    list<int> s;
    s.push_front(10);
    s.push_front(20);
    s.push_front(30);

    // SlistIterator<int> sp = s.begin();
    list<int>::iterator sp = s.begin();
    cout << *sp << endl;

    ++sp; // 다음위치 이동
    cout << *sp << endl;


    int x[5] = { 1, 2, 3, 4, 5};
    int* p = x;
    int* p2 = x + 1;

    ++p;
    if (p == p2) {
        cout << "같은 위치" << endl;
    }
    cout << *p << endl;
}
#endif