#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <boost/filesystem.hpp>
#include "scan.h"



class Node {
public:

    std::string filename() { return entry.path().filename().string(); }
    
    boost::filesystem::perms perms() { return entry.status().permissions(); };

    bool isfile(){ return !boost::filesystem::is_directory(entry.status()); }

    // Node operations

    /// @brief Builds an empty node
    Node() : parent(nullptr), child(nullptr), left(nullptr), right(nullptr) {}

    /// @brief builds a node connected to a parent node
    /// @param parent the parent node of the Node
    Node(Node* parent) : parent(parent), child(nullptr), left(nullptr), right(nullptr) {}

    ~Node() {}

    Node* parent;
    Node* child;
    Node* left;
    Node* right;
    boost::filesystem::directory_entry entry;
    
};




class Directory_tracker {
    Directory_tracker() : fs(Filesystm(".")) {}
    Directory_tracker(std::string directory_to_scan) : fs(Filesystm(directory_to_scan)) {}
    ~Directory_tracker(){};

    void save_text(std::string path);
    void save_xml(std::string path);
    void scan();

    Node* end(){ return nullptr; }
    Node* begin(){ return &root; }


private:
    Node root;
    Filesystm fs;

    void write_text(std::ostream os);
    void write_xml(std::ostream os);
    Node* level_jump(int diff, Node* base);



public:
    class iterator {
        iterator() : node(nullptr), good(0) {};
        iterator(Node* n) : node(n), good(1) {};
        void next();
        void prev();

        Node* operator*();
        bool isgood(){ return good; }

    private:
        Node* node;
        bool good = 1;
    };
};





#endif // DIRECTORY_H