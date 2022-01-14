#include <iostream>
#include <string.h>
using namespace std;

// Facade   네트워크의 상위개념: 네트워크를 몰라서 사용할 수있도록 프레임워크를 제공해준다.

// 1. google.com
// => IP주소로 변환한다.
// 2. IP주소를 통해, 컴퓨터를 찾고, 그 안에 약속된 프로세스를 찾는다.
//    컴퓨터의 주소: IP
//    프로세스의 주소: PORT

// 3. HTTP(Hyper Text Transfer Protocol)
//  - GET 명령을 날리면, HTML / Javascript / CSS를 전송해준다.

// 4. 리눅스에서 네트워크를 통해 데이터를 전송받기 위해서는 "소켓 프로그래밍"을 이용한다.

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h> //sockaddr_in
#include <arpa/inet.h>
#include <unistd.h>

class Address
{
    sockaddr_in addr;
public:
    Address(const char* ip, short port)
    {
        memset(&addr, 0, sizeof addr);
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);
    }

    const sockaddr* GetRawAddress() const
    {
        return reinterpret_cast<const sockaddr*>(&addr);
    }
};


class Socket
{
    int csock;
public:
    Socket(int type)    { csock = socket(PF_INET, type, 0); }

    ~Socket() { close(csock); }

    void Connect(const Address& addr)
    {
        int ret = connect(csock, addr.GetRawAddress(), sizeof(sockaddr_in));
    }

    int Write(const char* data, int len)
    {
        return write(csock, data, len);
    }

    int Read(char* data, int len)
    {
        return read(csock, data, len);
    }
};

// Facade Pattern
// : 프로그램을 하는데 필요한 클래스와 절차를 단순화 시켜주는 상위 개념의 클래스를 제공하자.
// 3.
class HTMLDownloader
{
    Socket sock;
    Address addr;

public:
    HTMLDownloader(const char* ip)
    : sock(SOCK_STREAM)
    , addr(ip, 80)
    {}

    void Start()
    {
        sock.Connect(addr);
        char str[] = "GET\n";
        sock.Write(str, strlen(str));

        char buf[128];
        int len;
        while ((len = sock.Read(buf, sizeof buf)) > 0)
            write(1, buf, len);
    }
};

int main()
{
    HTMLDownloader downloader("142.250.207.46");
    downloader.Start();
}

#if 0
int main()
{
    // 1. Socket
    int csock = socket(PF_INET, SOCK_STREAM, 0);
    // Socket sock(SOCK_STREAM);

    // 2. 주소 지정
    // => IP / PORT
    struct sockaddr_in addr = {0,};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80); // 빅엔디안으로 지정해야한다.
    addr.sin_addr.s_addr = inet_addr("142.250.207.46");
    // Address addr("142.250.207.46", 80); // : 자동으로 위에꺼가 다 처리가 된다. 불필요한 하부개념을 감출 수 있다.

    // 3. connect
    int ret = connect(csock, (struct sockaddr*)&addr, sizeof addr);
    if (ret == -1)
    {
        perror("connect()\n");
        return -1;
    }
    // sock.Connect(addr);

    char str[] = "GET\n";
    // 4. GET 명령을 서버에 전송한다.
    write(csock, str, strlen(str));

    // 5. read를 통해서 서버로부터 전송된 데이터를 화면에 출력한다.
    char buf[128];
    int len;
    while ((len = read(csock, buf, sizeof buf)) > 0) 
    {
        // printf("%s", buf);
        write(1, buf, len);
    }

    // 6. 연결을 종료한다.
    close(csock);
}
#endif

// 2.
#if 0
int main()
{
    Socket sock(SOCK_STREAM);
    Address addr("142.250.207.46", 80);
    
    sock.Connect(addr);

    char str[] = "GET\n";
    sock.Write(str, strlen(str));

    char buf[128];
    int len;
    while ((len = sock.Read(buf, sizeof buf)) > 0)
        // printf("%s", buf);
        write(1, buf, len);
}
#endif