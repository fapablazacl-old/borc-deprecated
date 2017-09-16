
#include "Project.hpp"
#include "Target.hpp"

namespace borc {
    Project::Project(const std::string name) : m_name(name) {}

    Project::~Project() {}

    std::size_t Project::getTargetCount() const {
        return m_targets.size();
    }

    Target* Project::getTarget(const std::size_t index) {
        return m_targets[index].get();
    }

    const Target* Project::getTarget(const std::size_t index) const {
        return m_targets[index].get();
    }

    Target* Project::addTarget() {
        auto target = new Target(this);

        m_targets.emplace_back(target);

        return target;
    }
}
