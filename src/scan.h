#ifndef SCAN_H
#define SCAN_H

#include <boost/filesystem.hpp>
#include <string>


class Filesystm {
    public:
    Filesystm();

    Filesystm(std::string dir);

    void next();
    
    // Can be added to skip permission_denied error throws later on.
    // void next(bool throw_permission_denied_error);

    std::string path();

    int depth();

    boost::filesystem::perms perms();

    private:
    boost::filesystem::recursive_directory_iterator dir_it;
};



#endif // SCAN_H