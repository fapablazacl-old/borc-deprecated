
#ifndef __borc_filetyperegistryimpl_hpp__
#define __borc_filetyperegistryimpl_hpp__

#include "FileTypeRegistry.hpp"

#include <string>
#include <memory>
#include <vector>

namespace borc {
    class Source;
    class FileType;

    /**
     * @brief A registry for identification and registering for file types
     */
    class FileTypeRegistryImpl : public FileTypeRegistry {
    public:
        FileTypeRegistryImpl();

        virtual ~FileTypeRegistryImpl();

        virtual const FileType* getFileType(const Source *source) const override;

        virtual const FileType* addFileType(const std::string &name, const std::vector<std::string> &extensions) override;

        virtual void removeFileType(const FileType *type) override;

    private:
        std::vector<std::unique_ptr<FileType>> m_fileTypes;
    };
}

#endif
