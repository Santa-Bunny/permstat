#include <boost/filesystem.hpp>
#include <string>

#include "pexceptions.h"
#include "directory.h"

// TODO: it is possible that boost::filesystem has a method of storing the directories and I am overthinking it


void Directory_tracker::save_text(std::string path) {
    
}

void Directory_tracker::write_text(std::ostream os){
    Directory_tracker::Iterator it(&root);
    std::string whitspace(longest_path + 5, ' '); // adding 5 for permissions at the end
    std::string linespace(longest_path + 5, '-'); // lines every other to ease reading
    bool linetype = 0;
    
    whitspace.replace(whitspace.begin(), whitspace.begin() + 4, "path");
    whitspace.replace(whitspace.begin() + whitspace.length() - 6, whitspace.begin() + whitspace.length() - 1, "perms");
    os << whitspace << '\n' << linespace << std::endl; // label columns and insert break

    while(it.isgood()) {
        if (linetype){  // Whitepaces

        }
        else {          // Lines

        }

        ++it;
    }
}

void Directory_tracker::save_xml(std::string path) {
    
}

void Directory_tracker::write_xml(std::ostream os){

}



void Directory_tracker::scan(){
    int depth;
    int prev_depth = fs.depth();
    longest_path = fs.path().length();
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
        else if (prev_depth < fs.depth()) { // child in new dir
            prev_node = level_jump(fs.depth() - prev_depth, prev_node);
            prev_node->child = node;
            node->parent = prev_node;
        }
        else if (prev_depth > fs.depth()) { // parent sibling
            prev_node = level_jump(fs.depth() - prev_depth, prev_node);
            prev_node = node;
            node->right = prev_node;
        }
        else {
            throw permstat::dir_error("ERROR: Directory_tracker.Scan(). You aren't supposed to be here\nPlease submit a bug report");
            return;
        }
        
        if (fs.path().length() > longest_path) {
            longest_path = fs.path().length();
        }
        prev_node = node;
        prev_depth = depth;
        fs.next();
    }
}


Node* Directory_tracker::level_jump(int diff, Node* base){
    Node* node = base;
    for(int i = 0; i < diff; ++i){
        if (node == nullptr){
            throw permstat::dir_error("Error: level_jump: Depth out of range.");
        }
        if (diff < 0){
            node = node->parent;
        }
        else {
            node = node->child;
        }
    }
    return node;
}



void Directory_tracker::Iterator::next(){
    if (!good){
        throw permstat::dir_error("ERROR: Directory_tracker::iterator.next() use of bad iterator: nullptr");
    }

    if (node->child) {          // jump into this file
        node = node->child;
        jump = CHILD;
    }
    else if (node->left) {      // go to next file
        node = node->left;
        jump = NEIGHBOR;
    }
    else {                      // Go up to next parent file
        while (node->parent->left == nullptr){
            if (node == nullptr){
                good = 0;
                jump = FAIL;
                return;
            }
            else {
                node = node->parent;
                jump = PARENT;
            }
        }
        node = node->parent->left;
    }
}

void Directory_tracker::Iterator::prev(){// TODO: finish
    if (!good){
        throw permstat::dir_error("ERROR: Directory_tracker::iterator.prev() use of bad iterator: nullptr");
    }

    if (node->right == nullptr){            // up to parent
        if (node->right->parent == nullptr){
            good = 0;
            jump = FAIL;
            return;
        }
        node = node->parent;
    }
    else if (node->right->child == nullptr){ // right to next
        node = node->right;
        jump = NEIGHBOR;
    }
    else {                                  // down to child
        node = node->right;
        while (node->child != nullptr) {
            node = node->child;
            jump = CHILD;
        }
    }
}

// TODO: replace entire string with fill character
void write_reset(std::string& s, char c){
    s = std::string(s.length(), c);
}