#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>

// 线程池模式
// class enum ThreadPoolMode
enum ThreadPoolMode
{
    MODE_FIXED,
    MODE_CACHED,
};

// 任务基类
class TaskBase
{
public:
    virtual void run() = 0;
};

// 线程类型
class ThreadWorker
{
public:
private:
};
// 线程池
class ThreadPool
{
public:
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool& operator=(const ThreadPool &) = delete;

public:
    ThreadPool();
    ~ThreadPool();

    // 设置线程池模式 固定|动态增长
    void setMode(ThreadPoolMode poolMode);
    
    // 设置初始线程个数
    void setInitThreadSize(unsigned int size);

    // 设置线程池任务队列阈值
    void setTaskCntThreshold(unsigned int threshhold);

    // 线程池提交任务
    void submitTask(std::shared_ptr<TaskBase> spTask);

    // 开启线程池
    void start();

private:
    ThreadPoolMode poolMode_;
    std::vector<ThreadWorker *> threads_; // 线程列表
    unsigned int initThreadSize;          // 初始线程个数
    // 用户创建 引用计数+1 放入服务端队列 引用计数+1 防止服务端处理任务时task已经被析构
    std::queue<std::shared_ptr<TaskBase>> taskQueue_; // 任务队列
    std::atomic_uint taskCnt_;                        // 任务数量
    unsigned int taskCntThreshhold_;                  // 任务队列数量上限
    std::mutex taskQueueMtx_;                         // 互斥操作task queue

    std::condition_variable notFull_;  // 表示任务队列不满
    std::condition_variable notEmpty_; // 表示任务队列不空
};