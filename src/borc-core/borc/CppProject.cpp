
#include "CppProject.hpp"
#include "CppTarget.hpp"

#include <cassert>
#include <algorithm>

namespace borc {
    void CppProject::generateTasks(TaskPerformer *performer) const {
        assert(performer);
    }

    CppProject::CppProject(const std::string name) : m_name(name) {}

    CppProject::~CppProject() {}

    std::size_t CppProject::getTargetCount() const {
        return m_targets.size();
    }

    CppTarget* CppProject::getTarget(const std::size_t index) {
        return m_targets[index].get();
    }

    const CppTarget* CppProject::getTarget(const std::size_t index) const {
        return m_targets[index].get();
    }

    CppTarget* CppProject::addTarget() {
        auto target = new CppTarget(this);

        m_targets.emplace_back(target);

        return target;
    }
}
