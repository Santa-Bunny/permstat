#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

#define ipsum   "./data.txt"
#define root_folder     "./root_node"


void help();
void dirmake();
void dirclean();
void makefile(std::ifstream &datafile, const std::string &path, int lines_to_read);


int main(int argc, char** argv) {
    if (argc == 1 || argc > 2) {
        help(argv);
    }

    

    if (argv[1][0] == 'm'){
        dirmake();
    }
    else {
        dirclean();
    }
    exit(0);
}


void help(char** argv) {
    std::cout << "call with " << argv[0] << "<m|c>\n" 
        << "m: make the directory\n" 
        << "c: clean up and delete directory" << std::endl;
}


void dirmake() {
    std::ifstream datafile;
    datafile.open(ipsum, std::ios::in);
    if (!datafile.is_open()) {
        std::cerr << "ERROR: dirmake: Cannot open datafile" << std::endl;
        exit(1);
    }


    // Parent Directories
    boost::filesystem::directory_entry("./root_node");
    boost::filesystem::directory_entry("./root_node/dir1");
    boost::filesystem::directory_entry("./root_node/dir2");
    boost::filesystem::directory_entry("./root_node/dir3");
    boost::filesystem::directory_entry("./root_node/dir4");

    // Child directories
    boost::filesystem::directory_entry("./root_node/dir1/dir1dir1");
    boost::filesystem::directory_entry("./root_node/dir1/dir1dir2");
    boost::filesystem::directory_entry("./root_node/dir3/dir3dir1");
    boost::filesystem::directory_entry("./root_node/dir3/dir3dir1/dir3dir1dir1");
    boost::filesystem::directory_entry("./root_node/dir3/dir3dir2");

    // files
    makefile(datafile, "./root_node/file1.txt", 2);
    makefile(datafile, "./root_node/dir1/dir1file1.txt", 1);
    makefile(datafile, "./root_node/dir1/dir1file2.txt", 2);
    makefile(datafile, "./root_node/dir1/dir1file3.txt", 1);
    makefile(datafile, "./root_node/dir1/dir1dir2/file1.txt", 1);
    makefile(datafile, "./root_node/dir1/dir1dir2/file2.txt", 4);
    makefile(datafile, "./root_node/dir2/dir2file1.txt", 2);
    makefile(datafile, "./root_node/dir3/dir3file1.txt", 3);
    makefile(datafile, "./root_node/dir3/dir3dir1/file1.txt", 4);
    makefile(datafile, "./root_node/dir3/dir3dir1/file2.txt", 1);
    makefile(datafile, "./root_node/dir3/dir3dir1/dir3dir1dir1/file1.txt", 4);

}

void dirclean() {
    boost::filesystem::remove_all(root_folder);
}

void makefile(std::ifstream &datafile, const std::string &path, int lines_to_read) {
    std::ofstream ofile;
    std::string temp;
    ofile.open(path);
    if (!ofile.is_open()) {
        std::cerr << "ERROR: makefile: cannot make file: " << path << std::endl;
        exit(1);
    }
    
    for(int i = 0; i < lines_to_read; ++i) {
        std::getline(datafile, temp);
        ofile << temp << '\n';
    }
    ofile.close();
}