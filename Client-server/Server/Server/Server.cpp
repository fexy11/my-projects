// Server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>

#pragma warning(disable: 4996)
SOCKET Connections[100];
int count = 0;

void ClientHandler(int index)
{
    char msg[128];
    while (true)
    {
        recv(Connections[index], msg, sizeof(msg), NULL);
        for (int i = 0; i < count; i++)
        {
            if (i == index) continue;
            send(Connections[i], msg, sizeof(msg), NULL);
        }
    }
}

int main(int args, char* argv[])
{
    WSADATA wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET slisten = socket(AF_INET, SOCK_STREAM, NULL);
    bind(slisten, (SOCKADDR*)&addr, sizeof(addr));
    listen(slisten, SOMAXCONN);

    for (int i = 0; i < 100; i++)
    {
        SOCKET newConnection;
        newConnection = accept(slisten, (SOCKADDR*)&addr, &sizeofaddr);
        
        if (newConnection == 0)
        {
            std::cout << "Error #2\n";
        }
        else
        {
            std::cout << "Client Connection!\n";
            char msg[128] = "Hello!";
            send(newConnection, msg, sizeof(msg), NULL);
            Connections[count] = newConnection;
            count++;
            CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
        }
    }
    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
