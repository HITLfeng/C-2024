#include "common.h"
#include "socket_common.h"



Status ClientMain()
{
    int clientSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSockFd == -1)
    {
        error_info("create socket failed");
        return ERR_SOCKET_CLIENT;
    }
    struct sockaddr_in clientAddr;
    
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(9090);
    clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int clientBindRet = bind(clientSockFd, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
    if (clientBindRet == -1)
    {
        error_info("bind socket failed");
        return ERR_BIND_CLIENT;
    }

    struct sockaddr_in srvAddr;
    srvAddr.sin_family = AF_INET;
    srvAddr.sin_port = htons(8080);
    srvAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int connectRet = connect(clientSockFd, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
    if (connectRet == -1)
    {
        error_info("connect socket failed");
        return ERR_CONNECT_CLIENT;
    }

    while (true) {
        char buf[1024];
        printf("please input: ");
        gets(buf);
        if (strcmp(buf, "exit") == 0)
        {
            normal_info("exit normal.");
            break;
        }
        int sendRet = send(clientSockFd, buf, strlen(buf), 0);
        if (sendRet == -1)
        {
            error_info("send failed");
            break;
        }
        char recvBuf[1024];
        int recvRet = recv(clientSockFd, recvBuf, sizeof(recvBuf), 0);
        if (recvRet == -1)
        {
            error_info("recv failed");
            break;
        }
        printf("recv buf is: %s.\n", recvBuf);
        sleep(2);
    }
    return ERR_OK;
}