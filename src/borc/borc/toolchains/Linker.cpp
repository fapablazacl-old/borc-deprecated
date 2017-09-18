
#include "Linker.hpp"

#include <borc/pom/Target.hpp>
#include <borc/tasks/Task.hpp>

namespace borc {
    Linker::Linker(const std::string &toolName) {
        m_toolName = toolName;
    }

    Linker::Linker(const std::string &toolName, const std::string &path) {
        m_toolName = toolName;
        m_path = path;
    }

    Linker::~Linker() {}

    bool Linker::isLinkable(const Target *target) const {
        return target->getSources().size() > 0;
    }

    std::string Linker::getToolName() const {
        return m_toolName;
    }

    std::string Linker::getPath() const {
        return m_path;
    }

    std::unique_ptr<Task> Linker::createTask(const Target *target) {
        // TODO: Add implementation
        return std::unique_ptr<Task>();
    }
}
