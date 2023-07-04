#include "../../src/scan.h"
#include <iostream>


int main() {
    system("python3 ./../dirgen/dirmake.py");
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
        system("python3 ./../dirgen/dirclean.py");
        std::cerr << e.what();
        exit (1);
    }

    return 0;
}