
#include "CppTarget.hpp"

namespace borc {
    std::string to_string(const CppTargetType type) {
        switch (type) {
        case CppTargetType::Program: return "TargetType::Program";
        case CppTargetType::Library: return "TargetType::Library";
        default: return "TargetType::<Error>";
        }
    }

    CppTarget::CppTarget(CppProject *project) : m_project(project) {}

    CppTarget::CppTarget(CppProject *project, const std::string &name) : m_project(project) {
        this->setName(name);
    }

    CppTarget* CppTarget::setName(const std::string &name) {
        m_name = name;

        return this;
    }

    CppTarget* CppTarget::setPath(const std::string &path) {
        m_path = path;

        return this;
    }

    CppTarget* CppTarget::setType(const CppTargetType type) {
        m_type = type;

        return this;
    }
}
