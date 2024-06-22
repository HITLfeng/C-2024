#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <functional>

// 接受任意类型数据
class AnyData
{
public:
    AnyData() = default;
    ~AnyData() = default;
    AnyData(const AnyData &) = delete;
    AnyData &operator=(const AnyData &) = delete;
    AnyData(AnyData &&) = default;

    template <typename T>
    // AnyData(T data) : ptr_(new Derive<T>(data))
    AnyData(T data) : ptr_(std::make_unique<Derive<T>>(data))
    {
    }

    template <typename T>
    T CastToOriginData()
    {
        Derive<T> *pDerive = dynamic_cast<Derive<T>>(ptr_.get());
        if (pDerive == nullptr)
        {
            // std::cerr << "转换失败 可能是基类指针转换为非法的派生类！" << std::endl;
            throw "CastToOriginData failed!"
        }
        return pDerive->data_;
    }

private:
    // 基类
    class Base
    {
    public:
        virtual ~Base() = default;
    };

    // 派生类
    template <typename T>
    class Derive : public Base
    {
    public:
        Derive(T data) : data_(data) {}

    private:
        T data_;
    };

private:
    std::unique_ptr<Base> ptr_;
};

// 信号量
class Sem
{
public:
    Sem(int cnt = 1) : resCnt_(cnt) {}
    ~Sem() = default;

    // 资源 -1
    void wait()
    {
        std::unique_lock<std::mutex> lock(mtx_);
        // if (resCnt_ < 1) {
        //     cond_.wait(lock);
        // }
        cond_.wait(lock, [&]() -> bool
                   { return resCnt_ > 0; });
        resCnt_--;
    }
    // 资源 +1
    void post()
    {
        std::unique_lock<std::mutex> lock(mtx_);
        resCnt_++;
        cond_.notify_all();
    }

private:
    int resCnt_; // 资源数
    std::mutex mtx_;
    std::condition_variable cond_;
};

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
    TaskBase() : result_(nullptr) {}
    ~TaskBase() = default;
    void exec(); // 封装run 实现更多功能 比如设置返回值
    virtual AnyData run() = 0;

private:
    Result *result_;
};

// 接受到提交线程池task返回值的Result
class Result
{
public:
    Result(std::shared_ptr<TaskBase> ptrTask, bool isSubmit = true)
        : ptrTask_(ptrTask), isSubmitSucc_(isSubmit) {}
    ~Result() = default;

    // 存 返回值
    // 调用时机，服务端处理任务结束
    void set(AnyData data)
    {
        this->any_ = std::move(data);

        // 可以get 获取了！
        sem_.post();
    }

    // 获取返回值
    // 调用时机，客户端调用接口阻塞等待返回值
    AnyData get()
    {
        if (!isSubmitSucc_)
        {
            // TODO
            return "";
        }
        sem_.wait();
        return std::move(any_);
    }

private:
    AnyData any_;
    Sem sem_;
    std::shared_ptr<TaskBase> ptrTask_;
    std::atomic_bool isSubmitSucc_; // 是否提交成功 提交失败调用get方法不需要阻塞
};

// 线程类型
class ThreadWorker
{
public:
    using threadHandler = std::function<void()>;

    ThreadWorker(threadHandler handler);
    ~ThreadWorker();

    void start();

private:
    threadHandler tHandler_;
};
// 线程池
class ThreadPool
{
public:
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;

public:
    ThreadPool();
    ~ThreadPool();

    // 设置线程池模式 固定|动态增长
    void setMode(ThreadPoolMode poolMode);

    // 设置线程池任务队列阈值
    void setTaskCntThreshold(unsigned int threshhold);

    // 线程池提交任务
    Result submitTask(std::shared_ptr<TaskBase> spTask);

    // 开启线程池
    void start(unsigned int size = 4);

private:
    // 内部调用接口
    // 设置初始线程个数
    void setInitThreadSize(unsigned int size);

    // 每个线程的处理函数
    void threadHandler();

private:
    ThreadPoolMode poolMode_;
    std::vector<std::unique_ptr<ThreadWorker>> threads_; // 线程列表
    unsigned int initThreadSize_;                        // 初始线程个数
    // 用户创建 引用计数+1 放入服务端队列 引用计数+1 防止服务端处理任务时task已经被析构
    std::queue<std::shared_ptr<TaskBase>> taskQueue_; // 任务队列
    std::atomic_uint taskCnt_;                        // 任务数量
    unsigned int taskCntThreshhold_;                  // 任务队列数量上限
    std::mutex taskQueueMtx_;                         // 互斥操作task queue

    std::condition_variable notFull_;  // 表示任务队列不满
    std::condition_variable notEmpty_; // 表示任务队列不空
};
