
#ifndef __borc_toolchainimpl_hpp__
#define __borc_toolchainimpl_hpp__

#include "Toolchain.hpp"

#include <cstddef>
#include <vector>
#include <memory>

namespace borc {

    class Target;
    class Source;

    class FileTypeRegistry;

    class ToolchainImpl : public Toolchain {
    public:
        explicit ToolchainImpl(const FileTypeRegistry *registry);

        virtual ~ToolchainImpl();

        virtual std::vector<Compiler*> getCompilers() const override;

        virtual std::vector<Linker*> getLinkers() const override;

        virtual std::unique_ptr<TaskNode> createBuildTask(const Project *project) override;
        
    private:
        std::vector<std::unique_ptr<Compiler>> m_compilers;
        std::vector<std::unique_ptr<Linker>> m_linkers;
    };
}

#endif 
