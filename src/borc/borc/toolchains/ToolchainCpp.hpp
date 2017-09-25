
#ifndef __borc_toolchaincpp_hpp__
#define __borc_toolchaincpp_hpp__

#include "ToolchainImpl.hpp"

#include <cstddef>
#include <vector>
#include <memory>

namespace borc {
    class Target;
    class Source;

    struct FileType;
    class FileTypeRegistry;

    class ToolchainCpp : public ToolchainImpl {
    public:
        explicit ToolchainCpp(FileTypeRegistry *registry);

    private:
        const FileType *m_c_sourceFile = nullptr;
        const FileType *m_c_headerFile = nullptr;
        const FileType *m_cpp_sourceFile = nullptr;
        const FileType *m_cpp_headerFile = nullptr;
    };
}

#endif 
