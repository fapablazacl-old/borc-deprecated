
#include "FileTypeRegistryImpl.hpp"

#include <cassert>
#include <algorithm>
#include <borc/FileType.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    FileTypeRegistryImpl::FileTypeRegistryImpl() {}

    FileTypeRegistryImpl::~FileTypeRegistryImpl() {}

    const FileType* FileTypeRegistryImpl::getFileType(const Source *source) const {
        assert(source);

        const FileType* resultType = nullptr;

        const std::string ext = source->getExtension();

        for (const auto &fileType : m_fileTypes) {
            if (fileType->check(ext)) {
                resultType = fileType.get();
                break;
            }
        }

        return resultType;
    }

    const FileType* FileTypeRegistryImpl::addFileType(const std::string &name, const std::vector<std::string> &extensions) {
        auto fileType = new FileType{name, extensions};

        m_fileTypes.emplace_back(fileType);

        return fileType;
    }

    void FileTypeRegistryImpl::removeFileType(const FileType *type) {
        assert(type);

        auto it = 
            std::find_if( m_fileTypes.begin(), m_fileTypes.end(), [type](auto &fileType) {
                return fileType.get() == type;
            });

        if (it != m_fileTypes.end()) {
            m_fileTypes.erase(it);
        }
    }
}
