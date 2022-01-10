#include <iostream>
using namespace std;

class Sample
{
    int data;

public:
    void f1() { cout << "f1" << endl; }
    int f2()
    {
        cout << "f2" << endl;
        return 0;
    }

    // C++ idioms
    // - C++에서 자주 사용되는 코드 기법
    int call_f3()   // int call_fn3(Sample* const this)
    {
        // this에서 null체크를 하는것은 표준에서 권장하지 않음
        // => 정적 멤버 함수를 통해 동일한 코드를 작성해준다.
        if (this)
        {
            return f3();
        }
        return 0;
    }

    static int call_f3(Sample* const self)
    {
        if (self)
        {
            return self->f3();
        }
        return 0;
    }

protected:
    int f3()
    {
        cout << "f3" << endl;
        return data;    // retrun this->data f3에서만 this에 접근한다.
                        // f1, f2는 this에 접근하지 않는다.
    }
};

int main()
{
    Sample* p = nullptr; // 메모리 할당 실패로 인해 nullptr이다.

    // 통과
    p->f1();    // Sample::f1(nullptr)
    p->f2();    //

    // 실패
    // p->f3();

    p->call_f3();
    Sample::call_f3(p);
    
}