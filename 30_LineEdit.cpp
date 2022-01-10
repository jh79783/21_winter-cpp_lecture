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

class LineEdit
{
    std::string data;
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
            
            if (isdigit(c))
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout <<endl;
        return data;
    }
};

int main()
{
    LineEdit edit;
    while(1)
    {
        string s = edit.GetData();
        cout << "out: " << s << endl;
    }
}