#include "threadpool.h"

#include <thread>
#include <iostream>

#define THREADPOOL_DEFAULT_MODE MODE_FIXED
#define THREADPOOL_DEFAULT_TASKCNT 0
#define THREADPOOL_DEFAULT_TASKCNTTHRESHHOLD 1024

// 提交任务最多等待时间 单位 /s
#define SUBMIT_TASK_WAIT_TIME 1

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
Result ThreadPool::submitTask(std::shared_ptr<TaskBase> spTask)
{
    // 获取锁
    // lock_guard在构造时或者构造前（std::adopt_lock）就已经获取互斥锁，
    // 并且在作用域内保持获取锁的状态，直到作用域结束；
    // 而unique_lock在构造时或者构造后（std::defer_lock）获取锁，
    // 在作用域范围内可以手动获取锁和释放锁，作用域结束时如果已经获取锁则自动释放锁。
    // lock_guard锁的持有只能在lock_guard对象的作用域范围内，作用域范围之外锁被释放，
    // 而unique_lock对象支持移动操作，可以将unique_lock对象通过函数返回值返回，
    // 这样锁就转移到外部unique_lock对象中，延长锁的持有时间。
    std::unique_lock<std::mutex> lock(this->taskQueueMtx_);
    // 判断任务队列是否有位置 可能已经满了

    // while (taskQueue_.size() >= taskCntThreshhold_)
    // {
    //     // 释放锁 并等待
    //     notFull_.wait(lock);
    // }
    // notFull_.wait(lock, [&]() -> bool { return taskQueue_.size() < taskCntThreshhold_; });
    // 一秒之内 没有等到，提交任务失败
    if (!notFull_.wait_for(lock, std::chrono::seconds(SUBMIT_TASK_WAIT_TIME), [&]() -> bool
                           { return taskQueue_.size() < taskCntThreshhold_; }))
    {
        std::cerr << "task queue is full and submit failed, wait time is " << SUBMIT_TASK_WAIT_TIME << " s." << std::endl;
        return Result(spTask, false);
    }

    // 空余 放入 没有空余 等待一定时间 超时则任务提交失败 返回
    taskQueue_.emplace(spTask);
    taskCnt_++;

    // 成功放入 通知 任务队列非空
    notEmpty_.notify_all();

    return Result(spTask, true);
}

// 开启线程池
void ThreadPool::start(unsigned int size)
{
    setInitThreadSize(size);
    for (unsigned int i = 0; i < initThreadSize_; ++i)
    {
        // auto ptr = std::make_unique<ThreadWorker>();
        std::unique_ptr<ThreadWorker> ptr(new ThreadWorker(std::bind(&ThreadPool::threadHandler, this)));
        threads_.emplace_back(std::move(ptr));
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

// 每个线程的处理函数
void ThreadPool::threadHandler()
{
    // std::cout << "ThreadPool::threadHandler()" << std::endl;
    // std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;
    for (;;)
    {
        std::shared_ptr<TaskBase> task;
        {
            std::unique_lock<std::mutex> lock(this->taskQueueMtx_);
            // 线程死等就可以 不需要像 submit task 那样返回
            notEmpty_.wait(lock, [&]() -> bool
                           { return taskQueue_.size() > 0; });
            task = taskQueue_.front();
            taskQueue_.pop();
            taskCnt_--;
            if (taskQueue_.size() > 0)
            {
                // 通知其他线程来干活了！
                notEmpty_.notify_all();
            }
            notFull_.notify_all();
        }
        if (task != nullptr)
        {
            std::cout << "deal task tid = " << std::this_thread::get_id() << std::endl;
            task->exec();
        }
    }
}

// *************************
// ThreadWorker:: 方法实现
// *************************
ThreadWorker::ThreadWorker(threadHandler handler) : tHandler_(handler)
{
}

ThreadWorker::~ThreadWorker() {}

void ThreadWorker::start()
{
    // tHandler_();
    std::thread usrThread(tHandler_);
    usrThread.detach();
}

// *************************
// TaskBase:: 方法实现
// *************************

void TaskBase::exec()
{
    if (result_ != nullptr)
    {
        AnyData data = run();
        result_->set(data);
    }
}
