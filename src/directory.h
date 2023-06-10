#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <boost/filesystem.hpp>



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

    protected:
    boost::filesystem::directory_entry entry;

};




class Directory_tracker {
    void save(std::string path);

private:
    Node root;
};





#endif // DIRECTORY_H