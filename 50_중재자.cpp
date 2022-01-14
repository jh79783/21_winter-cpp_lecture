#include <iostream>
#include <vector>
using namespace std;

class CheckBox;

// 중재자 패턴
// : 복잡한 객체간의 관계(M:N)를 중재자와 객체의 1:1 관계로 처리한다.
// - 객체간의 관계가 복잡할 때 중재하는 객체를 만들어서 상호 관계를 캡슐화한다.

class MediatorCheckBox
{
    std::vector<CheckBox*> v;
public:
    void AddCheckBox(CheckBox* p) { v.push_back(p); }
    void OnChanged(CheckBox* p);
    void Print();
    
    // void OnChanged(CheckBox* p)
    // {
    //     for (auto e : v)
    //     {
    //         if (e != p)
    //         {
    //             e->SetChecked(false);
    //         }
    //     }
    // }
    // void Print()
    // {
    //     for (auto e : v)
    //     {
    //         cout << e << ": " << e->IsChecked() << endl;
    //     }
    // }
};

class CheckBox
{
    bool isChecked = false;
    MediatorCheckBox* mediator = nullptr;

public:
    void SetMediator(MediatorCheckBox* p)
    {
        mediator = p;
        mediator->AddCheckBox(this);
    }

    void SetChecked(bool b) 
    { 
        isChecked = b; 
        // 자신의 상태 변화를 중재자에게 알려주어야 한다.
        if (isChecked)
            mediator->OnChanged(this);
    }

    bool IsChecked() const { return isChecked; }
};

void MediatorCheckBox::OnChanged(CheckBox* p)
    {
        for (auto e : v)
        {
            if (e != p)
            {
                e->SetChecked(false);
            }
        }
    }
void MediatorCheckBox::Print()
    {
        for (auto e : v)
        {
            cout << e << ": " << e->IsChecked() << endl;
        }
    }


int main()
{
    CheckBox c1, c2, c3, c4;
    MediatorCheckBox m;

    c1.SetMediator(&m);
    c2.SetMediator(&m);
    c3.SetMediator(&m);
    c4.SetMediator(&m);

    getchar();
    c1.SetChecked(true);
    m.Print();

    getchar();
    c2.SetChecked(true);
    m.Print();

    getchar();
    c3.SetChecked(true);
    m.Print();
}