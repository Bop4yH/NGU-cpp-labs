//
// Created by Александр on 07.12.2019.
//

#ifndef LAB2_IFACTORY_H
#define LAB2_IFACTORY_H


#include "../Workers/Worker.h"

class IFactory {
public:
    virtual Worker * createWorker() = 0;
    virtual ~IFactory() = default;
};


#endif //LAB2_IFACTORY_H
