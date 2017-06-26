
#include "CppProject.hpp"

#include <cassert>

namespace borc {
    void CppProject::generateTasks(TaskPerformer *performer) const {
        assert(performer);
    }

    CppProject::~CppProject() {}

    std::size_t CppProject::getTargetCount() const {
        return m_targets.size();
    }

    Target* CppProject::getTarget(const std::size_t index) {
        return m_targets[index].get();
    }

    const Target* CppProject::getTarget(const std::size_t index) const {
        return m_targets[index].get();
    }

    void CppProject::addTarget(std::unique_ptr<Target> target) {
        m_targets.push_back(std::move(target));
    }

    std::unique_ptr<Target> CppProject::removeTarget(Target *target) {
        return std::unique_ptr<Target>();
    }
}
