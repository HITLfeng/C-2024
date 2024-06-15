#include "threadpool.h"

#define THREADPOOL_DEFAULT_MODE MODE_FIXED
#define THREADPOOL_DEFAULT_INITTHREADSIZE 4
#define THREADPOOL_DEFAULT_TASKCNT 0
#define THREADPOOL_DEFAULT_TASKCNTTHRESHHOLD 1024

ThreadPool::ThreadPool() : poolMode_(THREADPOOL_DEFAULT_MODE),
                           initThreadSize(THREADPOOL_DEFAULT_INITTHREADSIZE),
                           taskCnt_(THREADPOOL_DEFAULT_TASKCNT),
                           taskCntThreshhold_(THREADPOOL_DEFAULT_TASKCNTTHRESHHOLD) {}
// ThreadPool::~ThreadPool();

// 设置线程池模式 固定|动态增长
// void ThreadPool::setMode(ThreadPoolMode poolMode);

// // 设置初始线程个数
// void ThreadPool::setInitThreadSize(unsigned int size);

// // 设置线程池任务队列阈值
// void ThreadPool::setTaskCntThreshold(unsigned int threshhold);

// // 线程池提交任务
// void ThreadPool::submitTask(std::shared_ptr<TaskBase> spTask);

// // 开启线程池
// void ThreadPool::start();