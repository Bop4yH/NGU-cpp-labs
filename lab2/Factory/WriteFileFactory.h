//
// Created by Александр on 07.12.2019.
//

#ifndef LAB2_WRITEFILEFACTORY_H
#define LAB2_WRITEFILEFACTORY_H


#include "IFactory.h"
#include "../Workers/WriteFile.h"
#include "../Workers/Worker.h"


class WriteFileFactory : public IFactory{
public:
    Worker * createWorker(const std::vector<std::string> &params);
};


#endif //LAB2_WRITEFILEFACTORY_H
