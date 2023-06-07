#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <boost/filesystem.hpp>




class dirfile {

    std::string filename() { return path.filename().string(); }
    
    boost::filesystem::perms perms() { return permissions; };

private:
    boost::filesystem::path path;
    boost::filesystem::perms permissions;
};

class Directory_tracker {




private:
    
};





#endif // DIRECTORY_H