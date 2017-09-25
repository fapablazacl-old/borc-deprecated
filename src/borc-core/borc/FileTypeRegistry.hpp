
#ifndef __borc_filetyperegistry_hpp__
#define __borc_filetyperegistry_hpp__

#include <string>
#include <vector>

namespace borc {
    class Source;
    struct FileType;

    /**
     * @brief A registry for identification and registering for file types
     *
     * This registry class serves as a local database for known file types, and it's used for 
     * know how to react during certain compilation operations.
     */
    class FileTypeRegistry {
    public:
        virtual ~FileTypeRegistry();

        virtual const FileType* getFileType(const Source *source) const = 0;

        virtual const FileType* addFileType(const std::string &name, const std::vector<std::string> &extensions) = 0;

        virtual void removeFileType(const FileType *type) = 0;
    };
}

#endif
