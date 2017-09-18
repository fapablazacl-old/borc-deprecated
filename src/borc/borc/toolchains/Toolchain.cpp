
#include "Toolchain.hpp"

#include "Compiler.hpp"
#include "Linker.hpp"

#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    Toolchain::Toolchain() {}
    
    Toolchain::~Toolchain() {}

    Compiler* Toolchain::getCompiler(const std::size_t index) {
        return m_compilers[index].get();
    }
    
    std::size_t Toolchain::getCompilerCount() const {
        return m_compilers.size();
    }

    Linker* Toolchain::getLinker(const std::size_t index) {
        return m_linkers[index].get();
    }

    std::size_t Toolchain::getLinkerCount() const {
        return m_linkers.size();
    }

    void Toolchain::setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project) {

    }
}
