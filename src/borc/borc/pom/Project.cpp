
#include "Project.hpp"
#include "Target.hpp"
#include "Source.hpp"

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

    std::string Project::getName() const {
        return m_name;
    }

    std::string Project::getPath() const {
        return m_path;
    }

    void Project::setPath(const std::string &path) {
        m_path = path;
    }
}
