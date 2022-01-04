#include <iostream>
using namespace std;

// 클래스도 템플릿으로 만들 수 있다.
// => 타입에 독립적인 스택을 만들 수 있다.
template<typename T>
class Stack
{
private:
    T *buff;
    T idx;    

public:
    Stack(int sz = 10)
    {
        idx = 0;
        buff = new T[sz]; 
    }

    ~Stack()
    {
        delete[] buff;
    }

    void push(const T &v)   // const reference로 써주는 것이 관례 및 성능적으로 이슈가 없어진다.
    {
        buff[idx++] = v;
    }

    T pop()
    {
        return buff[--idx];
    }
};

// 클래스 템플릿은 타입 추론이 불가능하다.
// => 명시적으로 타입을 지정해주어야 한다.
Stack<int> s1;  // T -> int
int main()
{
    Stack<long> s2(100);    // T -> long
    Stack<double> s3(100);  // T -> double

    s1.push(10);
    s2.push(20);

    cout << s1.pop() << endl;
    cout << s2.pop() << endl;
}
