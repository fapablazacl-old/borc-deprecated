
#ifndef __borc_targettype_hpp__
#define __borc_targettype_hpp__

#include <string>

namespace borc {
    enum class TargetType {
        Program = 1,
        Library = 2
    };

    extern std::string to_string(const TargetType type);
}

#endif
