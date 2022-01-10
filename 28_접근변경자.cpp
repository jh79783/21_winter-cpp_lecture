// 28_접근변경자.cpp
#include <iostream>
using namespace std;

class Base
{
// 접근 지정자
public:
    void foo() { cout << "foo" << endl; }
private:
    void goo() { cout << "goo" << endl; }
protected:
    void hoo() { cout << "hoo" << endl; }
};

//              public: 접근 변경자
class Derived : public Base
{
    Base b;
    b.foo() // ok

    Derived d;
    d.foo() // ok
};

// 부모의 접근 지정자를 자식 클래스를 통해 접근할 때 변경하는 방법
// : public Base
//  class Derived
// {
//  public:
//      void  foo() {}
//  protected:
//      void goo() {}
//}

// : protected Base
//  class Derived
// {
//  protected: // public -> protected
//      void  foo() {}
//  protected:
//      void goo() {}
//}

// : private Base
//  class Derived
// {
//  public: // public -> private
//      void  foo() {}
//  protected:  // protected -. private
//      void goo() {}
//}

int main()
{

}