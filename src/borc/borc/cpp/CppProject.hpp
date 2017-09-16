
#ifndef __borc_cppproject_hpp__
#define __borc_cppproject_hpp__

#include <borc/Project.hpp>

#include <memory>
#include <vector>

namespace borc {
    class CppProject : public Project {
    public:
        CppProject(const std::string &name);

        virtual void generateTasks(TaskPerformer *performer) const override;
    };
}

#endif
