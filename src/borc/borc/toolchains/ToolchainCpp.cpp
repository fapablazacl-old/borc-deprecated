
#include "ToolchainCpp.hpp"

#include "CompilerImpl.hpp"
#include "LinkerImpl.hpp"

namespace borc {
    ToolchainCpp::ToolchainCpp(FileTypeRegistry *registry) : ToolchainImpl(registry) {
        m_c_sourceFile = registry->addFileType("C Source File", {".c"});
        m_c_headerFile = registry->addFileType("C Header File", {".h"});
        m_cpp_sourceFile = registry->addFileType("C++ Source File", {".cpp", ".cxx", ".cc", ".c++"});
        m_cpp_headerFile = registry->addFileType("C++ Header File", {".hpp", ".hxx", ".hh", ".h++"});

        m_compilers.emplace_back(new CompilerImpl(registry, "cl", {m_c_sourceFile, m_cpp_sourceFile}));
        m_linkers.emplace_back(new LinkerImpl("link"));
    }
}
