//
// Created by Александр on 09.12.2019.
//

#ifndef LAB2_REPLACEFACTORY_H
#define LAB2_REPLACEFACTORY_H


#include "IFactory.h"

class ReplaceFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params);
};


#endif //LAB2_REPLACEFACTORY_H
