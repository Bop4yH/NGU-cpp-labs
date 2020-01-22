//
// Created by Александр on 05.12.2019.
//

#ifndef LAB2_WRITEFILE_H
#define LAB2_WRITEFILE_H


#include "Worker.h"
class WriteFile : public Worker {
private:
    std::string outputFile;
public:
    WriteFile(const std::vector<std::string> &params) ;
    WorkerType getType() override;
    std::string execute(std::string &text) override;
};

#endif //LAB2_WRITEFILE_H
