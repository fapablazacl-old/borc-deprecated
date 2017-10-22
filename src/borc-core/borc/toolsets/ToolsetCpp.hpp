
#ifndef __borc_toolchainimpl_hpp__
#define __borc_toolchainimpl_hpp__

#include "Toolset.hpp"

#include <cstddef>
#include <vector>
#include <memory>

namespace borc {
    class Target;
    class Source;
    class FileTypeRegistry;

    class FileType;

    class ToolsetCpp : public Toolset {
    public:
        explicit ToolsetCpp(FileTypeRegistry *registry);

        virtual ~ToolsetCpp();

        virtual std::vector<Compiler*> getCompilers() const override;

        virtual std::vector<Linker*> getLinkers() const override;

        virtual std::unique_ptr<TaskNode> createBuildTask(const Project *project) override;
        
    protected:
        std::vector<std::unique_ptr<Compiler>> m_compilers;
        std::vector<std::unique_ptr<Linker>> m_linkers;

        const FileType *m_c_sourceFile = nullptr;
        const FileType *m_c_headerFile = nullptr;
        const FileType *m_cpp_sourceFile = nullptr;
        const FileType *m_cpp_headerFile = nullptr;
    };
}

#endif 
