//
// Created by Александр on 09.12.2019.
//

#ifndef LAB2_SORTFACTORY_H
#define LAB2_SORTFACTORY_H


#include "IFactory.h"

class SortFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params);
};



#endif //LAB2_SORTFACTORY_H
