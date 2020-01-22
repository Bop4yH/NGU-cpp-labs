//
// Created by Александр on 09.12.2019.
//

#include "SortFactory.h"


#include "../Workers/Sort.h"

Worker *SortFactory::createWorker(const std::vector<std::string> &params){
    return new Sort(params);
}