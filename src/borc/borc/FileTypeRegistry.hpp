
#ifndef __borc_filetyperegistry_hpp__
#define __borc_filetyperegistry_hpp__

#include <string>
#include <set>
#include <vector>
#include <tuple>

#include "FileType.hpp"

namespace borc {
    /**
     * @brief The registry for known file types
     */
    class Source;
    class FileTypeRegistry {
    public:
        FileTypeRegistry();

        FileType getFileType(const Source *source) const;

    private:
        std::vector<std::pair<FileType, std::set<std::string>>> m_fileTypes;
    };
}

#endif
