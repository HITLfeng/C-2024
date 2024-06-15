#include "threadpool.h"

#define THREADPOOL_DEFAULT_MODE MODE_FIXED
#define THREADPOOL_DEFAULT_TASKCNT 0
#define THREADPOOL_DEFAULT_TASKCNTTHRESHHOLD 1024

// *************************
// ThreadPool:: 方法实现
// *************************
// public
ThreadPool::ThreadPool() : poolMode_(THREADPOOL_DEFAULT_MODE),
                           taskCnt_(THREADPOOL_DEFAULT_TASKCNT),
                           taskCntThreshhold_(THREADPOOL_DEFAULT_TASKCNTTHRESHHOLD) {}

ThreadPool::~ThreadPool()
{
}

// 设置线程池模式 固定|动态增长
void ThreadPool::setMode(ThreadPoolMode poolMode)
{
    poolMode_ = poolMode;
}

// 设置线程池任务队列阈值
void ThreadPool::setTaskCntThreshold(unsigned int threshhold)
{
    taskCntThreshhold_ = threshhold;
}

// 线程池提交任务
void ThreadPool::submitTask(std::shared_ptr<TaskBase> spTask) {}

// 开启线程池
void ThreadPool::start(unsigned int size)
{
    setInitThreadSize(size);
    for (unsigned int i = 0; i < initThreadSize_; ++i)
    {
        threads_.emplace_back(new ThreadWorker());
    }
    for (unsigned int i = 0; i < initThreadSize_; ++i)
    {
        threads_[i]->start();
    }
}

// private
// 设置初始线程个数
void ThreadPool::setInitThreadSize(unsigned int size)
{
    initThreadSize_ = size;
}

// *************************
// ThreadWorker:: 方法实现
// *************************