// 30_LineEdit3.cpp
#include <iostream>
#include <string>
using namespace std;

#include <unistd.h>
#include <termios.h>
#include <stdio.h>

int getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
//-----------

// 공통성 가변성 분리 방법 2번째
// - 변하는 것을 다른 클래스로 뽑아낸다.
// => 교체 가능한 인터페이스 기반 클래스로 뽑아내는 걸로 변경한다.
//  : Sterategy Pattern(전략 패턴)
//  1) 실행 시간에 정책으 변경하는 것이 가능하다.
//   - lineEdit.SetValidator(...)
//  2) Validator의 정책을 다른 클래스에서도 재사용 가능하다.

// Validation 정책에 관한 인터페이스를 설계한다.
struct Validator
{
    virtual ~Validator() { }

    virtual bool Validate(const std::string& s, char c) = 0;

    virtual bool IsComplete(const std::string& s) = 0;
};

class LineEdit
{
    std::string data;
    //-------
    Validator* pValidator;
    // Validator* pValidator = nullptr; // -> c++11부터 허용되지만, 전통적인 방법을 사용하기 위해 위 코드를 사용
public:
    LineEdit() : pValidator(nullptr)
    {}

    void SetValidator(Validator* p) { pValidator = p; }

    //-----

    std::string GetData()
    {
        data.clear();

        while(1)
        {
            // char c = getchar();
            char c = getch();

            if (c == '\n' && (pValidator == nullptr || pValidator->IsComplete(data)))
                break;
            
            if (pValidator == nullptr || pValidator->Validate(data, c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout <<endl;
        return data;
    }
};

// 새로운 정책의 LineEdit이 필요하면, 정책 클래스를 Validator의 인터페이스를 기반으로 만들어주면 된다.

class LimitDigitValidator : public Validator
{
    int limit;

public:
    LimitDigitValidator(int n) : limit(n) {}

    bool Validate(const std::string& s, char c) override
    {
        return s.size() < limit && isdigit(c);
    }

    bool IsComplete(const std::string& s) override
    {
        return s.size() == limit;
    }
};

int main()
{
    LineEdit edit;

    LimitDigitValidator v(5);
    edit.SetValidator(&v);
    while(1)
    {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}