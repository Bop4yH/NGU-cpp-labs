//
// Created by Александр on 09.12.2019.
//

#include "GrepFactory.h"
#include "../Workers/Grep.h"

Worker *GrepFactory::createWorker(const std::vector<std::string> &params){
    return new Grep(params);
}