
#include "CppProject.hpp"

#include <cassert>
#include <algorithm>

namespace borc {
    CppProject::CppProject(const std::string &name) 
        : Project(name) {}

    void CppProject::generateTasks(TaskPerformer *performer) const {
        assert(performer);
    }
}
