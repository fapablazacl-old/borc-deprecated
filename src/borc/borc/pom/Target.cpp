
#include "Target.hpp"

namespace borc {
    std::string to_string(const TargetType type) {
        switch (type) {
        case TargetType::Program: return "TargetType::Program";
        case TargetType::Library: return "TargetType::Library";
        default: return "TargetType::<Error>";
        }
    }

    Target::Target(Project *project) : m_project(project) {}

    Target::Target(Project *project, const std::string &name) : m_project(project) {
        this->setName(name);
    }

    Target* Target::setName(const std::string &name) {
        m_name = name;

        return this;
    }

    Target* Target::setPath(const std::string &path) {
        m_path = path;

        return this;
    }

    Target* Target::setType(const TargetType type) {
        m_type = type;

        return this;
    }

    Target* Target::addDependency(const Target *target) {
        m_deps.push_back(target);

        return this;
    }
}
