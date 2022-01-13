#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 방문자 패턴(Visitor Pattern)
// : 컨테이너(복합 객체)의 내부 구조에 상관없이 요소에 연산을 수행하는 객체
// => 기존 메뉴 코드를 수정하지 않고 새로운 기능의 추가를 달성할 수 있다.
// 문제점
// : 값 변경이 불가능한 변수에 대해 수정할 수 있도록 함수 제공

// 방문자
class PopupMenu;
class MenuItem;

struct MenuVisitor
{
    virtual ~MenuVisitor() {}

    virtual void Visit(PopupMenu* p) = 0;
    virtual void Visit(MenuItem* p) = 0;
};

// 각 요소가 구현해야 하는 곳
// 방문자를 통해서 연산을 수행하도록 만들어주기 위해서는 아래 인터페이스를 구현해야 합니다.
struct MenuAcceptor
{
    virtual ~MenuAcceptor() {}

    virtual void Accepct(MenuVisitor* visitor) = 0;

};

class BaseMenu : public MenuAcceptor
{
    std::string title;
public:
    BaseMenu(const std::string& s) : title(s) {}

    std::string GetTitle() const { return title; }

    //---------
    // 캡슐화 정책에 위배가 발생할 수 있다.
    void SetTitle(const std::string& s) { title = s; }
    //---------

    virtual void Command () = 0;
    virtual ~BaseMenu() {};
};

class MenuItem : public BaseMenu
{
public:
    MenuItem(const std::string& s) : BaseMenu(s) {}

    void Accepct(MenuVisitor* visitor) override
    {
        visitor->Visit(this);
    }

    void Command() override
    {
        cout << "메뉴 선택되었음 : " << GetTitle() << endl;
        getchar();
        getchar();
    }
};

class PopupMenu : public BaseMenu
{
    std::vector<BaseMenu*> v; 
public:
    PopupMenu(const std::string& s) : BaseMenu(s) {}

    ~PopupMenu()
    {
        for (auto e : v)
            delete e;
    }

    void Accepct(MenuVisitor* visitor) override
    {
        visitor->Visit(this);

        // 내가 소유하고 있는 모든 메뉴들에 대해서도 방문자를 전달한다.
        for (auto e : v)
        {
            e->Accepct(visitor);
        }
    }

    void AddMenu(BaseMenu* p)
    {
        v.push_back(p);
    }

    void Command() override
    {
        system("clear");
        while (1) 
        {
            int size = v.size();

            for (int i = 0; i < size; ++i)
            {
                cout << i + 1 << ". " << v[i]->GetTitle() << endl;
            }
            cout << size + 1 << ". 상위 메뉴로" << endl;

            cout << "메뉴를 선택하세요 >>" << endl;
            int cmd;
            cin >> cmd;

            if (cmd == size + 1)
                break;
            
            if (cmd < 1 || cmd > size +1)
                continue;

            v[cmd - 1]->Command(); 
        }
    }
};

class TitleDecoratorVisitor : public MenuVisitor
{
public:
    void Visit(PopupMenu* p) override
    {
        string s = p->GetTitle();
        string s2 = s + " > ";

        p->SetTitle(s2);
    }

    void Visit(MenuItem* p) override
    {
        p->SetTitle("[" + p->GetTitle() + "]");
    }
};

int main()
{
    PopupMenu* menubar = new PopupMenu("Menubar");
    PopupMenu* file = new PopupMenu("파일");
    PopupMenu* edit = new PopupMenu("편집");

    menubar->AddMenu(file);
    menubar->AddMenu(edit);

    file->AddMenu(new MenuItem("새 파일"));
    file->AddMenu(new MenuItem("저장"));
    file->AddMenu(new MenuItem("불러오기"));

    edit->AddMenu(new MenuItem("잘라내기"));
    edit->AddMenu(new MenuItem("복사"));
    edit->AddMenu(new MenuItem("붙여넣기"));

    TitleDecoratorVisitor v;
    menubar->Accepct(&v); // 전체 메뉴에서 팝업 메뉴 표현 방식이 변경됩니다.

    menubar->Command();
}