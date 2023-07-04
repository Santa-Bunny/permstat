#include "../../src/directory.h"
#include "../../src/scan.h"

#include <iostream>


int main() {
    system("python3 ./../dirgen/dirmake.py");
    try {
        Directory_tracker fs("./../dirgen/root_node");

        std::cout << "scanning..." << std::endl;
        fs.scan();
        std::cout << "finished scan\nWriting..." << std::endl;
        fs.save_text("test_write.out");
        std::cout << "Task Complete!" << std::endl;
    }
    catch (std::exception e) {
        system("python3 ./../dirgen/dirclean.py");
        std::cerr << e.what();
        exit (1);
    }

    
    return 0;
}