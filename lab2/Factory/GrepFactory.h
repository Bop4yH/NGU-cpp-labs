//
// Created by Александр on 09.12.2019.
//

#ifndef LAB2_GREPFACTORY_H
#define LAB2_GREPFACTORY_H


#include "IFactory.h"

class GrepFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params) ;
};


#endif //LAB2_GREPFACTORY_H
