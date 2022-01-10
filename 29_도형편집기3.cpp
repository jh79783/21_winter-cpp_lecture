#include <iostream>
#include <vector>
using namespace std;

// #include <mutex>
class Mutex
{
public:
    void lock() { cout << "동기화 시작" << endl; }
    void unlock() { cout << "동기화 종료" << endl; }
};

Mutex m;

// 도형 편집기로 배우는 객체지향 설계 개념
// 7. Draw에 동기화의 기능이 추가되어야 한다.

// 8. 공통성과 가변성의 분리
//  "변하지 않는 것과 변하는 것은 분리되어야 한다."
//  - 변하지 않는 전체 알고리즘은 부모가 비가상함수로 제공하고
//    변해야 하는 부분만 가상함수화해서 자식이 변경할 수 있도록 하는 설계 방법
//    => Template Method Pattern
//    => NVI(Non Virtual Interface)

class Shape
{
public:
    void Draw()
    {
        m.lock();
        DrawImple();
        m.unlock();
    }

    virtual void DrawImple()
    {
        cout << "Shape Draw" << endl;
    }

    virtual Shape* Clone()
    {
        return new Shape(*this);
    }
};

class Rect : public Shape
{
    void DrawImple() override
    {
        cout << "Rect Draw" << endl;
    }
    Shape* Clone() override
    {
        return new Rect(*this);
    }
};

class Circle : public Shape
{
public:
    void DrawImple() override
    {
        cout << "Circle Draw" << endl;
    }
    Shape* Clone() override
    {
        return new Circle(*this);
    }
};

int main()
{
    // vector<Rect*> rects;
    // vector<Circle*> circles;
    vector<Shape*> v;
    
    while(1)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 1)
        {
            v.push_back(new Rect);
        }
        else if (cmd == 2)
        {
            v.push_back(new Circle);
        }
        else if (cmd == 8)
        {
            cout << "몇 번째 도형을 복사 할까요 >>";
            int k;
            cin >> k;

            v.push_back(v[k]->Clone());

            // k번째 도형의 복사본을 만들어서, v에 추가
            // k번째 도형은? Rect? Circle?
            //  - v[k] 타입을 체크해야 합니다.
            //  - RTTI
            #if 0
            if (typeid(Rect) == typeid(*v[k]))
            {
                Rect* p = static_cast<Rect*>(v[k]);
                v.push_back(new Rect(*p));
            }
            else if (typeid(Circle) == typeid(*v[k]))
            {
                Circle* p = static_cast<Circle*>(v[k]);
                v.push_back(new Circle(*p));
            }
            #endif
        }
        else if (cmd == 9)
        {
            for (Shape* p : v)
            {
                p->Draw();
            }
            // 다형성
        }
    }
}