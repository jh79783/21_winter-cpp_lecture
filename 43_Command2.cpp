#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Command Pattern
// : 명령을 객체로 추상화한다.

// 1. Undo의 동작은 가장 최근에 실행된 명령에 대한 반대 동작이 수행된다.
// 2. 명령을 객체로 추상화해서, 스택에 저장할 수 있어야 한다.

class Shape
{
public:
    virtual void Draw()
    {
        cout << "Shape Draw" << endl;
    }
};


class Rect : public Shape
{
public:
    void Draw() override
    {
        cout << "Rect Draw" << endl;
    }
};

class Circle : public Shape
{
public:
    void Draw() override
    {
        cout << "Circle Draw" << endl;
    }
};

// 인터페이스의 문제점: 새로운 기능을 추가하는 것이 어렵다.
// 해결하기 위해 순수 가상함수를 return false로 변경
struct Command
{
public:
    virtual ~Command() { }

    virtual void Execute() = 0;

    // 인터페이스에 기본 구현을 제공하는 것이 좋다.
    virtual void Undo() { }
    virtual bool CanUndo() { return false; }
};

class AddCommand : public Command
{
    vector<Shape*>& v;
public:
    AddCommand(vector<Shape*>& p)
    : v(p)
    {}

    // Factory Method Pattern
    // : Template Method Pattern의 모양인데, 자식이 재정의하는 가상 함수가 정책이나 알고리즘의 변경이 아닌 객체 생성일 때
    virtual Shape*CreateShape() = 0;

    void Execute() override
    {
        v.push_back(CreateShape());
    }

    bool CanUndo() override { return true; }
    void Undo() override
    {
        Shape* p = v.back();
        v.pop_back();
        delete p;
    }
};

class AddRectCommand : public AddCommand
{
public:
    AddRectCommand(vector<Shape*>& p)
    : AddCommand(p)
    {}

    Shape*CreateShape() override
    {
        return new Rect;
    }
};

class AddCircleCommand : public AddCommand
{
public:
    AddCircleCommand(vector<Shape*>& p)
    : AddCommand(p)
    {}

    Shape* CreateShape()
    {
        return new Circle;
    }
};

class DrawCommand : public Command
{
    vector<Shape*>& v;
public:
    DrawCommand(vector<Shape*>& p)
    : v(p)
    {}

    void Execute() override
    {
        for (auto e : v)
            e->Draw();
    }
};

class MacroCommand : public Command
{
    vector<Command*> v; // 여러개의 명령을 저장한다.

public:
    void AddCommand(Command* p) { v.push_back(p); }

    void Execute() override
    {
        for (auto e : v)
            e->Execute();
    }
};


int main()
{
    vector<Shape*> v;

    MacroCommand mc;
    mc.AddCommand(new AddRectCommand(v));
    mc.AddCommand(new AddCircleCommand(v));
    mc.Execute();



    
    Command* pCommand = nullptr;

    stack<Command* > undo;

    while(1)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            // v.push_back(new Rect);
            pCommand = new AddRectCommand(v);
        }
        else if (cmd == 2)
        {
            // v.push_back(new Circle);
            pCommand = new AddCircleCommand(v);
        }
        else if (cmd == 9)
        {
            // for (Shape* p : v)
            // {
            //     p->Draw();
            // }
            pCommand = new DrawCommand(v);
        }
        else if (cmd == 0)
        {
            Command* p = undo.top();
            p->Undo();
            undo.pop();
            delete p;
            continue;
        }

        if (pCommand)
        {
            pCommand->Execute();
            if (pCommand->CanUndo())
                undo.push(pCommand);
            else
                delete pCommand;
        }
    }
}