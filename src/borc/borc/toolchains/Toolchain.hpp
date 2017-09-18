
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
        Toolchain();

        virtual ~Toolchain();

        virtual std::vector<Compiler*> getCompilers() const;

        virtual std::vector<Linker*> getLinkers() const;

        virtual void setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project);
        
    private:
        std::vector<std::unique_ptr<Compiler>> m_compilers;
        std::vector<std::unique_ptr<Linker>> m_linkers;
    };
}

#endif 
