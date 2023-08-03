#include "../../src/scan.h"
#include <iostream>


int main() {
    system("make -C ./../dirgen/");
    system("./../dirgen/dir m");
    try {
        Filesystm fs("./../dirgen/root_node");

        int depth = fs.depth();

        std::cout << "path                     perms          depth\n";

        while(fs.good()){
            std::cout << fs.path() << "      " << fs.perms() << "       " << fs.depth() << std::endl;
            fs.next();
        }
    }
    catch (std::exception e) {
        system("./../dirgen/dir c");
        std::cerr << e.what() << std::endl;
        exit (1);
    }
    system("./../dirgen/dir c");
    system("make -C ./../dirgen/ clean");
    return 0;
}