#include <iostream>
#pragma comment(lib, "ws2_32")
#include <WinSock2.h>
#include <stdio.h>
using namespace std;
int main(int argc, char* grgv[])
{
    WSADATA wsa;
    int result = WSAStartup(MAKEWORD(2, 2), &wsa); //윈속 라이브러리 초기화

    if (result != 0)
    {
        cout << "윈속 초기화 실패" << endl;
        return 1;
    }

    cout << "윈속 초기화 성공" << endl;

    int dataSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (dataSocket == INVALID_SOCKET)
    {
        cout << "소켓 생성 실패" << endl;
        WSACleanup();
        return 1;
    }
    cout << "소켓 생성 성공" << endl;
    cout << "소켓을 닫습니다" << endl;

    closesocket(dataSocket);

    cout << "윈속을 종료합니다" << endl;

    WSACleanup();
    return 0;
}
