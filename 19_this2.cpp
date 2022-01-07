#include <iostream>
#include <string>
using namespace std;

#if 0
// this 활용
// - 멤버 변수 이름과 함수 인자 이름이 동일할 때, 멤버 변수를 명시적으로 접근할 때 사용한다.

// 초기화 리스트에서 this->xxx 형식으로 초기화가 불가능하다.(생성자에서 불가능)
// 멤버 변수 이름과 동일한 인자를 받을 경우, this를 명시적으로 작성해주어야 한다.
//  > 멤버 데이터는 이름의 뒤에 언더스코어 형식을 권장한다.
class User
{
    std::string name;
    int age;

public:
    User(const std::string& name, int age) : name_(name), age_(age){} 

    void set(const std::string& name, int age)
    {
        // 1. this를 명시한다.
        // this->name = name;
        // this->age = age;
        // this 안쓰고 언더스코어로도 사용할 수 있다.

        // 2. 멤버 데이터의 이름을 다른 형식으로 사용한다.
        // ex) name_ / age_
        //     _name / _age - 권장하지 않는다.
        //     m_name / m_age - 구식 형식
        name_ = name;
        age_ = age;
    }
};

int main()
{
    User user1("Tom", 42)
}
#endif

// 활용 2.
//      연쇄 호출(체이닝)

class User{
private:
    std::string name;
    std::string address;
    std::String phone;

public:
// 1번
#if 0
    void SetName(const std::string& name) { name_ = name; }
    void SetAddress(const std::string& address) { address_ = address; }
    void SetPhone(const std::string& phone) { phone_ = phone; }
#endif

// 2번
#if 0
    User* SetName(const std::string& name)
    {
        name_ = name;
        return this;
    }
    User* SetAddress(const std::string& address)
    {
        address_ = address;
        return this;
    }
    User* SetPhone(const std::string& phone)
    {
        phone_ = phone;
        return this;
    }
#endif

// 3번
    User& SetName(const std::string& name)
    {
        name_ = name;
        return *this;
    }
    User& SetAddress(const std::string& address)
    {
        address_ = address;
        return *this;
    }
    User& SetPhone(const std::string& phone)
    {
        phone_ = phone;
        return *this;
    }

};

int main()
{
    User user;

    // 1번
    // user.SetName("Tom");
    // user.SetAddress("Seoul");
    // user.SetPhone("010-1234-1234");

    // 2번
    // user.SetName("Tom")->SetAddress("Seoul")->SetPhone("010-1234-1234");

    // 3번
    user.SetName("Tom").SetAddress("Seoul").SetPhone("010-1234-1234")
}
