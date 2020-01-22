#include <iostream>

#include "Workflow.h"

int main(int arg, char **argv) {
    WorkFlow workFlow;

    try {
        workFlow.launch("in.txt");
    }
    catch (std::string &ex) {
        std::cout << ex << endl;
    }

    return 0;
}