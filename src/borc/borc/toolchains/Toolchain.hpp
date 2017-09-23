
#ifndef __borc_toolchain_hpp__
#define __borc_toolchain_hpp__

#include <cstddef>

#include <vector>
#include <memory>

namespace borc {
    class Project;
    class TaskHierarchy;
    class Compiler;
    class Linker;
    class Task;
    
    class Toolchain {
    public:
        virtual ~Toolchain();

        virtual std::vector<Compiler*> getCompilers() const = 0;

        virtual std::vector<Linker*> getLinkers() const = 0;

        virtual void setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project) = 0;
    };
}

#endif
