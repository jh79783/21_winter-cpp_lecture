// #include <thread>   // C++11
#include <pthread.h>    // 기존에 사용
#include <unistd.h>

#include <iostream>
using namespace std;

void *foo(void *foo)
{
    for (int i = 0; i < 10000000; ++i)
    {
        usleep(20000);
        cout << "foo" << endl;
    }

    return nullptr;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, nullptr, &foo, nullptr);
    for (int i = 0; i < 10000000; ++i)
    {
        usleep(100000);
        cout << i << endl;
    }
}

// g++ 18_thread.cpp -lpthread
