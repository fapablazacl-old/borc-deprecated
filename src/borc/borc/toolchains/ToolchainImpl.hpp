
#ifndef __borc_toolchainimpl_hpp__
#define __borc_toolchainimpl_hpp__

#include "Toolchain.hpp"

#include <cstddef>
#include <vector>
#include <memory>

namespace borc {

    class Target;
    class Source;

    class ToolchainImpl : public Toolchain {
    public:
        ToolchainImpl();

        virtual ~ToolchainImpl();

        virtual std::vector<Compiler*> getCompilers() const override;

        virtual std::vector<Linker*> getLinkers() const override;

        virtual void setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project) override;
        
    private:
        void fillHierarchy(TaskHierarchy *hierarchy, Linker *linker, Target *target);

        void fillHierarchy(TaskHierarchy *hierarchy, Compiler *compiler, Source *source);

    private:
        std::vector<std::unique_ptr<Compiler>> m_compilers;
        std::vector<std::unique_ptr<Linker>> m_linkers;
    };
}

#endif 
