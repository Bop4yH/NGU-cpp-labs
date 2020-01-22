//
// Created by Александр on 09.12.2019.
//

#include "ReplaceFactory.h"

#include "../Workers/Replace.h"

Worker *ReplaceFactory::createWorker(const std::vector<std::string> &params){
    return new Replace(params);
}