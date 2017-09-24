
#include "CompilerImpl.hpp"

#include <cassert>
#include <memory>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include <borc/tasks/Task.hpp>
#include <borc/tasks/LogTask.hpp>
#include <borc/pom/Source.hpp>

#include <fmt/format.h>

namespace borc {
    CompilerImpl::CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types) {
        assert(registry);

        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
    }

    CompilerImpl::CompilerImpl(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types, const std::string &path) {
        assert(registry);

        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
        m_path = path;
    }

    CompilerImpl::~CompilerImpl() {}

    bool CompilerImpl::isCompilable(const Source *source) const {
        assert(source);

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
        assert(source);

        namespace fs = boost::filesystem;

        const std::string commandTemplate = "{0} {1} /O0 /c /o {2}";

        const fs::path sourceFile = source->getFilePath();
        const fs::path targetFile = fs::path(source->getFilePath()).parent_path() / fs::path(source->getFileTitle() + ".obj");

        const std::string cmd = fmt::format(commandTemplate, m_toolName, sourceFile.string(), targetFile.string());

        return std::make_unique<LogTask>(cmd);
    }
}
