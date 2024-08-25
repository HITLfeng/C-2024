#include <unistd.h>
#include "common.h"
#include <stdlib.h>

// shmem
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>    /* For O_* constants */

#define UNIQUE_FALG "UNIQUE_FALG"

void TestPipe()
{
    // 0.read 1.write
    int pipefd[2];
    int ret = pipe(pipefd);
    if (ret == -1)
    {
        error_info("TestPipe pipe failed.");
        return;
    }

    pid_t proId = fork();
    if (proId < 0)
    {
        perror("fork failed");
    }
    else if (proId == 0)
    {
        // 新进程
        // read
        close(pipefd[0]);
        int sendCnt = 0;
        while (sendCnt < 100)
        {
            char msg[128] = {0};
            sprintf(msg, "hello thank you! + time: %d", sendCnt);
            write(pipefd[1], msg, 128);
            perror("current status");
            sendCnt++;
            sleep(2);
        }
    }
    else
    {
        close(pipefd[1]); // 关闭写，只读
        // 老进程流程
        // proId 新进程的ID
        char recv[128];
        int recvCnt = 0;
        while (read(pipefd[0], recv, 128) > 0 && recvCnt < 15)
        {
            normal_info("get msg from child process %d: %s", proId, recv);
            recvCnt++;
        }
        close(pipefd[0]);

        normal_info("parent exit");
        sleep(10);
    }
}

static void TestShmem1()
{
    // const char *name = "testshm1";
    // system("ipcs -a");
    // shm_open(name, O_CREAT | O_EXCL, 0644);
    // system("ipcs -a");
}

void TestShmem()
{
    // 1.创建共享内存
    // 2.映射共享内存
    // 3.使用共享内存
    // 4.删除共享内存

    // 1.创建共享内存
    int fd = shm_open(UNIQUE_FALG, O_CREAT | O_EXCL, 0644);
    if (fd == -1)
    {
        error_info("shm_open failed");
        return;
    }

    // 2.映射共享内存
    // 2.1 设置共享内存大小
    ftruncate(fd, 4096);
    // 2.2 映射共享内存
    void *addr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
    {
        error_info("mmap failed");
        return;
    }

    // 3.使用共享内存
    sprintf(addr, "hello world");
    printf("addr: %s\n", (char *)addr);

    // 4.删除共享内存
    shm_unlink(UNIQUE_FALG);
}

// void TestMessageQueue()
// {
//     // 1.创建消息队列
//     // 2.发送消息
//     // 3.接收消息
//     // 4.删除消息队列

//     // 1.创建消息队列
//     int mqid = msgget(1234, IPC_CREAT | 0666);
//     if (mqid == -1)
//     {
//         error_info("msgget failed");
//         return;
//     }

//     // 2.发送消息
//     char *msg = "hello world";
//     int ret = msgsnd(mqid, msg, strlen(msg), 0);
//     if (ret == -1)
//     {
//         error_info("msgsnd failed");
//         return;
//     }

//     // 3.接收消息
//     char buf[128] = {0};
//     ret = msgrcv(mqid, buf, 128, 0, 0);
//     if (ret == -1)
//     {
//         error_info("msgrcv failed");
//         return;
//     }
//     printf("get msg: %s\n", buf);

//     // 4.删除消息队列
//     msgctl(mqid, IPC_RMID, NULL);
// }
