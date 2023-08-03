#include <stdexcept>
#include <string>

namespace permstat{
    class dir_error : public std::runtime_error {
    public:
        dir_error(char const* msg) throw()
            : std::runtime_error(msg) {}   
    };

}