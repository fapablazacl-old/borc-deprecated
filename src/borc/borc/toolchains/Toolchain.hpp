
#ifndef __borc_toolchain_hpp__
#define __borc_toolchain_hpp__

#include <cstddef>

#include <vector>
#include <memory>

namespace borc {
    class Project;
    class Compiler;
    class Linker;
    class Task;

    struct TaskNode;
    
    class Toolchain {
    public:
        virtual ~Toolchain();

        virtual std::vector<Compiler*> getCompilers() const = 0;

        virtual std::vector<Linker*> getLinkers() const = 0;

        /**
         * @brief Create the build task hierarchy needed to build the specified project
         */
        virtual std::unique_ptr<TaskNode> createBuildTask(const Project *project) = 0;
    };
}

#endif
