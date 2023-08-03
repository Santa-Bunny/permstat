#include "../../src/directory.h"
#include "../../src/scan.h"

#include <iostream>


int main() {
    system("make -C ./../dirgen/");
    system("./../dirgen/dir m");
    try {
        Directory_tracker fs("./../dirgen/root_node");

        std::cout << "scanning..." << std::endl;
        fs.scan();
        std::cout << "finished scan\nWriting..." << std::endl;
        fs.save_text("test_write.out");
        std::cout << "Task Complete!" << std::endl;
    }
    catch (std::exception e) {
        system("./../dirgen/dir c");
        std::cerr << e.what();
        exit (1);
    }

    system("./../dirgen/dir c");
    system("make -C ./../dirgen/ clean");
    return 0;
}