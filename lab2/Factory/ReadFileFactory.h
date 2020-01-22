//
// Created by Александр on 09.12.2019.
//

#ifndef LAB2_READFILEFACTORY_H
#define LAB2_READFILEFACTORY_H


#include "IFactory.h"

class ReadFileFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params) ;
};


#endif //LAB2_READFILEFACTORY_H
