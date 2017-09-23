
#include "LinkerImpl.hpp"

#include <borc/pom/Target.hpp>
#include <borc/tasks/LogTask.hpp>
#include <borc/tasks/Task.hpp>

namespace borc {
    LinkerImpl::LinkerImpl(const std::string &toolName) {
        m_toolName = toolName;
    }

    LinkerImpl::LinkerImpl(const std::string &toolName, const std::string &path) {
        m_toolName = toolName;
        m_path = path;
    }

    LinkerImpl::~LinkerImpl() {}

    bool LinkerImpl::isLinkable(const Target *target) const {
        return target->getSources().size() > 0;
    }

    std::string LinkerImpl::getToolName() const {
        return m_toolName;
    }

    std::string LinkerImpl::getPath() const {
        return m_path;
    }

    std::unique_ptr<Task> LinkerImpl::createTask(const Target *target) {
        return std::make_unique<LogTask>(target->getName());
    }
}
