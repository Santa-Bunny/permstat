#include "../../src/directory.h"
#include "../../src/scan.h"

#include <iostream>


int main() {
    Directory_tracker fs("./../../../.");

    std::cout << "scanning..." << std::endl;
    fs.scan();
    std::cout << "finished scan\nWriting..." << std::endl;
    fs.save_text("test_write.out");
    std::cout << "Task Complete!" << std::endl;

    return 0;
}