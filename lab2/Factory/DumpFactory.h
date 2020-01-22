//
// Created by Александр on 09.12.2019.
//

#ifndef LAB2_DUMPFACTORY_H
#define LAB2_DUMPFACTORY_H


#include "IFactory.h"

class DumpFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params) ;
};




#endif //LAB2_DUMPFACTORY_H
