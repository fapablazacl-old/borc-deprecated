
#include "LinkerCpp.hpp"

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include <borc/pom/Source.hpp>
#include <borc/pom/Target.hpp>
#include <borc/tasks/LogTask.hpp>
#include <borc/tasks/Task.hpp>

#include <fmt/format.h>

namespace borc {
    LinkerCpp::LinkerCpp(const std::string &toolName) {
        m_toolName = toolName;
    }

    LinkerCpp::LinkerCpp(const std::string &toolName, const std::string &path) {
        m_toolName = toolName;
        m_path = path;
    }

    LinkerCpp::~LinkerCpp() {}

    bool LinkerCpp::isLinkable(const Target *target) const {
        return target->getSources().size() > 0;
    }

    std::string LinkerCpp::getToolName() const {
        return m_toolName;
    }

    std::string LinkerCpp::getPath() const {
        return m_path;
    }

    std::unique_ptr<Task> LinkerCpp::createTask(const Target *target) {
        assert(target);

        namespace fs = boost::filesystem;

        const std::string commandTemplate = "{0} {1}";
        const std::string targetName = target->getName();
        const std::string cmd = fmt::format(commandTemplate, m_toolName, targetName);

        return std::make_unique<LogTask>(cmd);
    }
}
