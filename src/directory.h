#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <boost/filesystem.hpp>
#include "scan.h"

#include <iterator>
#include <cstddef>

#define FAIL        -1
#define NEIGHBOR     0
#define PARENT       1
#define CHILD        2


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

    struct Iterator 
    {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t; // Not actually useful but required
        using value_type        = Node;
        using pointer           = Node*;
        using reference         = Node&;

        Iterator() : node(nullptr), good(0) {};
        Iterator(Node* n) : node(n), good(1) {};

        reference operator*() const { return *node; }
        pointer operator->() { return node; }

        // Prefix increment
        Iterator& operator++() { this->next(); return *this; } 
        Iterator& operator--() { this->prev(); return *this; } 

        // Postfix increment
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }

        friend bool operator== (const Iterator& a, const Iterator& b) { return a.node == b.node; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.node != b.node; };
        bool isgood(){ return good; }

        void next();
        void prev();

        int step_type() { return jump; }

    private:
        Node* node;
        bool good = 1;
        int jump = FAIL;
    };

    Iterator end(){ return Iterator(); }
    Iterator begin(){ return Iterator(&root); }


protected:
    Node root;
    Filesystm fs;
    uint longest_path;
    void write_reset(std::string& s, char c);

    void write_text(std::ostream os);
    void write_xml(std::ostream os);
    Node* level_jump(int diff, Node* base);
};





#endif // DIRECTORY_H