//
// Created by Александр on 09.12.2019.
//

#include "ReadFileFactory.h"

#include "../Workers/ReadFile.h"

Worker *ReadFileFactory::createWorker(const std::vector<std::string> &params){
    return new ReadFile(params);
}