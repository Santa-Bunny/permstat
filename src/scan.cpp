#include "scan.h"
#include <boost/filesystem.hpp>

/// @brief Creates a filesystem iterator at the programs path
Filesystm::Filesystm(){
    dir_it = boost::filesystem::recursive_directory_iterator(".");
}

/// @brief Creates a filesystm iterator at a specific path
/// @param dir the path of the directory to iterate over
Filesystm::Filesystm(std::string dir) {
    dir_it = boost::filesystem::recursive_directory_iterator(dir);
}

/// @brief advances filesystem iterator
void Filesystm::next(){
        ++dir_it;
}

/// @brief gets the path file/dir of the iterators position.
/// @return String of file or directory path
std::string Filesystm::path(){
    return dir_it->path().string();
}

/// @brief gets depth of search in directory path
/// @return int of depth
int Filesystm::depth(){
        return dir_it.depth();
}

/// @brief Checks to see wether the filesystem iterator is at the end
/// @return 0 when iterator finishes. 1 when iterator is still traversing
int Filesystm::good(){
    return dir_it != end(dir_it);
}

/// @brief gets permissions as a Enum type
/// @return Enum.perms with values of permissions
boost::filesystem::perms Filesystm::perms(){
    return dir_it->status().permissions();
}