#pragma once

#include <cstdio>
#include <string>
#include "Parser.h"
#include "Factory/IFactory.h"
class WorkFlow {
public:
    void launch(std::string path);
};