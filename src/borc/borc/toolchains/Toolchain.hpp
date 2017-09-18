
#ifndef __borc_toolchain_hpp__
#define __borc_toolchain_hpp__

#include <cstddef>

namespace borc {
    class Compiler;
    class Linker;

    class Toolchain {
    public:
        std::size_t getCompilerCount() const;
        const Compiler* getCompiler(const std::size_t index) const;
    };
}

#endif 
