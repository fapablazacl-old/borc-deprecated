
#include "Compiler.hpp"

#include <borc/tasks/Task.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    Compiler::Compiler(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types) {
        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
    }

    Compiler::Compiler(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types, const std::string &path) {
        m_registry = registry;
        m_toolName = toolName;
        m_supportedTypes = types;
        m_path = path;
    }

    Compiler::~Compiler() {}

    bool Compiler::isCompilable(const Source *source) const {
        FileType fileType = m_registry->getFileType(source);

        return m_supportedTypes.find(fileType) != m_supportedTypes.end();
    }

    std::string Compiler::getToolName() const {
        return m_toolName;
    }

    std::string Compiler::getPath() const {
        return m_path;
    }

    std::unique_ptr<Task> Compiler::createTask(const Source *source) {
        // TODO: Add implementation
        return std::unique_ptr<Task>();
    }
}
