
#ifndef __borc_compiler_hpp__
#define __borc_compiler_hpp__

#include <string>
#include <set>
#include <memory>

#include <borc/FileTypeRegistry.hpp>

namespace borc {

    class Task;
    class Source;
    class FileTypeRegistry;

    class Compiler {
    public:
        explicit Compiler(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types);

        explicit Compiler(const FileTypeRegistry *registry, const std::string &toolName, const std::set<FileType> &types, const std::string &path);

        virtual ~Compiler();

        /**
         * @brief Return true the supplied source is compilable by this compiler, and false otherwise.
         */
        bool isCompilable(const Source *source) const;

        /**
         * @brief Get the physical name of the command (example: "cl" for Visual C++).
         */
        std::string getToolName() const;

        /**
         * @brief Get the physical location, in disk, of the path of the compiler.
         */
        std::string getPath() const;
        
        /**
         * @brief Creates a task wich will build the specified source file at a later stage.
         */
        std::unique_ptr<Task> createTask(const Source *source);

    private:
        std::string m_toolName;
        std::string m_path;
        const FileTypeRegistry *m_registry;

        std::set<FileType> m_supportedTypes;
    };
}

#endif 
