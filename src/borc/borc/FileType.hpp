
#ifndef __borc_filetype_hpp__
#define __borc_filetype_hpp__

#include <string>
#include <set>
#include <vector>
#include <tuple>

namespace borc {
    /**
     * A specific file type
     */
    enum class FileType {
        Unknown,
        C,
        Cplusplus, 
    };
}

#endif
