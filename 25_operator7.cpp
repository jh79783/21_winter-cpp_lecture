#include <iostream>
using namespace std;

// C/C++에서 가장 많이 사용하는 연산자 중에 하나인
// 증감(++/--)연산자를 재정의 하는 것을 이해하자.

class Integer
{
private:
    int value;

public:
    Integer(int n = 0) : value(n)
    {

    }

    // ++에 대해서 멤버 함수로 연산자 재정의 함수를 제공한다.
    Integer& operator++()
    {
        // value += 1;
        ++value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Integer& i);
};

std::ostream& operator<<(std::ostream& os, const Integer& i)
{
    return os << i.value << endl;
}

int main()
{
    int n1;
    cout << n1 << endl;

    Integer n2;
    cout << ++n2 << endl;
    // => cout.operator<<(n2)
    // => operator<<(cout, n2)
}
