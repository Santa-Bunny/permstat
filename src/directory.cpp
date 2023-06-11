#include <boost/filesystem.hpp>

#include "directory.h"

// TODO: it is possible that boost::filesystem has a method of storing the directories and I am overthinking it


void Directory_tracker::save(std::string path) {
    
}

void Directory_tracker::scan(){
    int depth;
    int prev_depth = fs.depth();
    Node* node;
    Node* prev_node = &root;


    root.entry = fs.entry();
    fs.next();



    while(fs.good()){
        node = new Node();
        depth = fs.depth();

        node->entry = fs.entry();

        if (prev_depth == fs.depth()) { // Sibling in same dir
            prev_node->left = node;
            node->right = prev_node;
            node->parent = prev_node->parent;
        }
        else if (prev_depth + 1 == fs.depth()) { // child in new dir
            prev_node->child = node;
            node->parent = prev_node;
        }
        else if (prev_depth - 1 == fs.depth()) { // parent sibling
            prev_node->parent->left = node;
            node->right = prev_node->parent;
        }
        else {
            // TODO: figure out base case for popout of n directories
            throw std::runtime_error("ERROR: Jumped out of or into multiple directories");
            return;
        }
        

        prev_node = node;
        prev_depth = depth;
        fs.next();
    }
}