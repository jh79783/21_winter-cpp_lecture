// 30_LineEdit.cpp
#include <iostream>
#include <string>
using namespace std;

// Windows - getch(비표준 함수)
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

// 1. Validation 정책은 변경이 가능해야한다.
// 방법 1) 변하는 것을 가상 함수로 뽑아낸다.
//  => Template Method Pattern

class LineEdit
{
    std::string data;

    // 변하지 않는 코드(공통성)에서 변해야 하는 것(가변성)이 있다면
    // 변해야 하는 것을 '가상함수'로 뽑아낸다.
    virtual bool validate(char c) { return isdigit(c); }

public:
    std::string GetData()
    {
        data.clear();

        while(1)
        {
            // char c = getchar();
            char c = getch();

            if (c == '\n')
                break;
            
            // if (isdigit(c))
            if (validate(c))
            {
                data.push_back(c);
                cout << c;
            }

        }
        cout <<endl;
        return data;
    }
};

// 이제 정책을 변경하고 싶다면, 파생 클래스에서 가상 함수를 재정의하면 된다.
class AddressLineEdit : public LineEdit
{
public:
    bool validate(char c) override
    {
        return true;
    }
};

int main()
{
    // LineEdit edit;   // -> 기존 LineEdit의 정책을 변경하는게 아니라, 새로운 정책을 새롭게 만드는 것
    AddressLineEdit edit;
    while(1)
    {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}