#include "task.h"
#include <iostream>
#include <thread>
#include <random>

int intRandomGen(int l, int r)
{
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(l, r);
    return distr(eng);
}

// class TaskBuyHuawei
// public:
void TaskBuyHuawei::run()
{
    std::cout << "买手机 买遥遥领先还是买iphone ? " << std::endl;
    std::cout << "线程" << std::this_thread::get_id() << "选择是：" << std::endl;
    if (intRandomGen(1, 10) < 9)
    {
        std::cout << "买iphone" << std::endl;
    }
    else
    {
        std::cout << "买遥遥领先" << std::endl;
    }
}