

#include "Toolchain.hpp"

#include <cassert>

#include "Compiler.hpp"
#include "Linker.hpp"

#include <algorithm>

#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    Toolchain::Toolchain() {}
    
    Toolchain::~Toolchain() {}

    std::vector<Compiler*> Toolchain::getCompilers() const {
        std::vector<Compiler*> compilers;

        std::transform(m_compilers.begin(), m_compilers.end(), compilers.begin(), [](const auto &compiler) {
            return compiler.get();
        });

        return compilers;
    }
    
    std::vector<Linker*> Toolchain::getLinkers() const {
        std::vector<Linker*> linkers;
        
        std::transform(m_linkers.begin(), m_linkers.end(), linkers.begin(), [](const auto &linker) {
            return linker.get();
        });

        return linkers;
    }

    void Toolchain::setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project) {
        assert(hierarchy);
        assert(project);
        
    }
}
