//
// Created by Александр on 07.12.2019.
//

#include "WriteFileFactory.h"
#include "../Workers/WriteFile.h"

Worker *WriteFileFactory::createWorker(const std::vector<std::string> &params){
    return new WriteFile(params);
}