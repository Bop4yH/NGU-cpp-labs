//
// Created by Александр on 05.12.2019.
//

#ifndef LAB2_DUMP_H
#define LAB2_DUMP_H


#include "Worker.h"
class Dump : public Worker {
private:
    std::string outputFile;
public:
    Dump(const std::vector<std::string> &params);
    WorkerType getType() override;
    std::string execute(std::string &text) override;
};


#endif //LAB2_DUMP_H
