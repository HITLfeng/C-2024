#include "common.h"
#include "socket_common.h"

// 处理函数1：calc
void *HandleCalc(void *arg)
{
    // TODO: 处理请求
    // TODO: 释放资源
    normal_info("calc thread %lu support your calc.\n", pthread_self());
    int clientFd = *(int *)arg;
    char buf[1024] = {0};
    uint32_t recvCnt = 0;
    while (true)
    {
        int ret = recv(clientFd, buf, sizeof(buf), 0);
        if (ret == -1)
        {
            error_info("recv failed.");
            break;
        }
        else if (ret == 0)
        {
            error_info("client close.");
            break;
        }
        else
        {
            recvCnt++;
            normal_info("recv buf is: %s.\n", buf);
            char *retBuf = (char *)malloc(1024);
            sprintf(retBuf, "buf: %u.", recvCnt);
            send(clientFd, retBuf, strlen(retBuf), 0);
            memset(buf, 0x00, 1024);
            free(retBuf);
        }
    }
    return NULL;
}

Status MainWorker()
{
    int srvListenFd = -1;
    srvListenFd = socket(AF_INET, SOCK_STREAM, 0);
    if (srvListenFd == -1)
    {
        error_info("create socket failed");
        return ERR_SOCKET;
    }
    struct sockaddr_in srvAddr;
    srvAddr.sin_family = AF_INET;
    // srvAddr.sin_port = htons(8080);
    srvAddr.sin_port = htons(8080);
    srvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int bindRet = bind(srvListenFd, (struct sockaddr *)&srvAddr, sizeof(srvAddr));
    if (bindRet == -1)
    {
        error_info("bind socket failed");
        return ERR_BIND;
    }

    int listenRet = listen(srvListenFd, 128);
    if (listenRet == -1)
    {
        error_info("listen socket failed");
        return ERR_LISTEN;
    }

    // TODO: accept 循环accept 等待客户端请求 然后创建线程去处理请求
    uint8_t isEnd = 0;
    while (!isEnd)
    {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientFd = accept(srvListenFd, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientFd == -1)
        {
            error_info("accept socket failed");
            return ERR_ACCEPT;
        }
        printf("client ip: %s, port: %d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        // TODO: 创建线程处理请求
        // TODO: 释放资源
        pthread_t handleThreadId;
        pthread_create(&handleThreadId, NULL, HandleCalc, (void *)&clientFd);
        pthread_detach(handleThreadId);
        sleep(3);
    }
    return ERR_OK;
}

int main()
{
    Status ret = MainWorker();
    if (ret != ERR_OK)
    {
        error_info("main worker failed.");
    }
    return 0;
}