#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include <algorithm>
#include <iostream>

enum class WorkerType {
    IN,
    OUT,
    INOUT
};

class Worker {
public:
    virtual ~Worker() = default;
    virtual WorkerType getType() = 0;
    virtual std::string execute(std::string &text)  = 0;
};


