
#include "Project.hpp"

#include <algorithm>

#include "Target.hpp"
#include "Source.hpp"

namespace borc {
    Project::Project(const std::string name) : m_name(name) {}

    Project::~Project() {}

    std::vector<Target*> Project::getTargets() const {
        std::vector<Target*> targets;
        
        std::transform(m_targets.begin(), m_targets.end(), targets.begin(), [](const auto &target) {
            return target.get();
        });

        return targets;
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
