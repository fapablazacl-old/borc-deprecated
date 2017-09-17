
#include "FileTypeRegistry.hpp"

#include <cassert>
#include <borc/pom/Source.hpp>

namespace borc {
    FileTypeRegistry::FileTypeRegistry() {
        m_fileTypes.push_back({FileType::C, {".c", ".h"}});
        m_fileTypes.push_back({FileType::Cplusplus, {".cc", ".hh", ".cpp", ".hpp", ".cxx", ".hxx", "c++", "h++"}});
    }

    FileType FileTypeRegistry::getFileType(const Source *source) const {
        assert(source);

        const std::string ext = source->getExtension();

        for (const auto &pair : m_fileTypes) {
            const FileType fileType = pair.first;
            const auto &extensions = pair.second;

            if (extensions.find(ext) != extensions.end()) {
                return fileType;
            }
        }

        return FileType::Unknown;
    }
}
