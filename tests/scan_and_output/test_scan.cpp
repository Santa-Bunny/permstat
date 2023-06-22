#include "../../src/scan.h"
#include <iostream>


int main() {
    Filesystm fs("./../../../.");

    int depth = fs.depth();

    std::cout << "path                     perms          depth\n";

    while(fs.good()){
        std::cout << fs.path() << "      " << fs.perms() << "       " << fs.depth() << std::endl;
        fs.next();
    }

    return 0;
}