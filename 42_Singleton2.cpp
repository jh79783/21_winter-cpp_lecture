// 힙에 생성하는 싱글톤
#include <iostream>
#include <mutex>
using namespace std;

class AutoLock
{
    std::mutex& mLock;
public:
    inline AutoLock(std::mutex& m)
    : mLock(m) { mLock.lock(); }

    ineline ~AutoLock() { mLock.unlock(); }
};

class Cursor
{
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    Cursor& operator=(const Cursor&) = delete;

    static Cursor* sInstance;
    static std::mutex sLock;    // 스레드 공유를 해결하기 위한 방법
public:
    // 코드의 문제점: 임계영역 안에서 예외가 발생하면 unlock이 호출되지 않는다. -> 데드락의 위험성이 있다.
    // => 예외 안전하게 사용하기 위해서, RAII를 이용한다.
    //  RAII(Resource Acquision is Initialize)
    //  - 생성자 소멸자를 이용해 자원을 관리하는 것

    // C++11/14 에서 보장받을 수 있다.
    static Cursor& GetInstance()    
    {
        static Cursor* instance = new Cursor;
        return *instance;
    }

#if 0
    static Cursor& GetInstance()    
    {
        // AutoLock al(sLock);
        std::lock_guard<std::mutex> al(sLock);  // 이미 있는 라이브러리 사용하여 데드락을 방지할 수 있다.
        if (sInstance == nullptr)
            sInstance = new Cursor; 
        return *sInstance;
    }
#endif


    #if 0
    static Cursor& GetInstance()    // 전역이다 : 모든 스레드에서 공유된다
    {
        sLock.lock();
        if (sInstance == nullptr)
            sInstance = new Cursor; //-> 예외 발생하면 데드락 발생!!!
        sLock.unlock();
        return *sInstance;
    }
    #endif
};

// 정적 멤버 변수는 반드시 외부 선언되어야 한다.! (꼭 기억하기)
Cursor* Cursor::sInstance = nullptr;
std::mutex Cursor::sLock;

int main()
{
    // Cursor c; // error!
    // Cursor* p = new Cursor; // error!

    Cursor& c1 = Cursor::GetInstance();
    Cursor& c2 = Cursor::GetInstance();     

    cout << &c1 << endl;
    cout << &c2 << endl;

}

