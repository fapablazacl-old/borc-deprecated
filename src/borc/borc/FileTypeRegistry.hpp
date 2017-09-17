
#ifndef __borc_filetyperegistry_hpp__
#define __borc_filetyperegistry_hpp__

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
