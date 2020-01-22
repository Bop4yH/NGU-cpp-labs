//
// Created by Александр on 09.12.2019.
//

#include "DumpFactory.h"
#include "../Workers/Dump.h"

Worker *DumpFactory::createWorker(const std::vector<std::string> &params){
    return new Dump(params);
}