#pragma once

#include "threadpool.h"

class TaskBuyHuawei : public TaskBase
{
public:
    AnyData run();
};

class Monitor : public TaskBase
{
public:
    AnyData run();
};
