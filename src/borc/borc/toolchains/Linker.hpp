
#ifndef __borc_linker_hpp__
#define __borc_linker_hpp__

#include <string>
#include <memory>

namespace borc {
    class Task;

    class Source;
    class Target;

    class Linker {
    public:
        explicit Linker(const std::string &toolName);

        explicit Linker(const std::string &toolName, const std::string &path);

        virtual ~Linker();

        /**
         * @brief Return true the supplied target is linkable by this linker, and false otherwise.
         */
        bool isLinkable(const Target *target) const;

        /**
         * @brief Get the physical name of the command (example: "cl" for Visual C++).
         */
        std::string getToolName() const;

        /**
         * @brief Get the physical location, in disk, of the path of the compiler.
         */
        std::string getPath() const;
        
        /**
         * @brief Creates a task wich will link the specified target at a later stage.
         */
        std::unique_ptr<Task> createTask(const Target *target);

    private:
        std::string m_toolName;
        std::string m_path;
    };
}

#endif 
