
#include "CompilerImpl.hpp"

#include <memory>

#include <borc/tasks/Task.hpp>
#include <borc/tasks/LogTask.hpp>
#include <borc/pom/Source.hpp>

#include <fmt/format.h>

namespace borc {
    CompilerImpl::CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types) {
        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
    }

    CompilerImpl::CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types, const std::string &path) {
        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
        m_path = path;
    }

    CompilerImpl::~CompilerImpl() {}

    bool CompilerImpl::isCompilable(const Source *source) const {
        FileType fileType = m_registry->getFileType(source);

        return m_supportedTypes.find(fileType) != m_supportedTypes.end();
    }

    std::string CompilerImpl::getToolName() const {
        return m_toolName;
    }

    std::string CompilerImpl::getPath() const {
        return m_path;
    }

    std::unique_ptr<Task> CompilerImpl::createTask(const Source *source) {
        const std::string cmd = fmt::format("{0}", source->getFilePath());

        return std::make_unique<LogTask>(cmd);
    }
}
