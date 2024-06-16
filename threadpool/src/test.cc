#include "threadpool.h"
#include <chrono>
#include <thread>
#include "task.h"

#define CLT_THREAD_CNT 4



int main()
{
    ThreadPool threadPool;
    threadPool.setMode(MODE_FIXED);
    threadPool.start();
    while (true) {
        std::shared_ptr<TaskBase> spTask(new TaskBuyHuawei());
        threadPool.submitTask(spTask);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::this_thread::sleep_for(std::chrono::seconds(100));

    return 0;
}