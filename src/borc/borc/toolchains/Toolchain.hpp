
#ifndef __borc_toolchain_hpp__
#define __borc_toolchain_hpp__

#include <cstddef>

namespace borc {
    class Compiler;
    class Linker;

    class Toolchain {
    public:
        virtual ~Toolchain();

        virtual std::size_t getCompilerCount() const = 0;
        
        virtual const Compiler* getCompiler(const std::size_t index) const = 0;
    };
}

#endif 
