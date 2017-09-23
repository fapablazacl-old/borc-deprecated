
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
        virtual ~Linker();

        /**
         * @brief Return true the supplied target is linkable by this linker, and false otherwise.
         */
        virtual bool isLinkable(const Target *target) const = 0;

        /**
         * @brief Get the physical name of the command (example: "cl" for Visual C++).
         */
        virtual std::string getToolName() const = 0;

        /**
         * @brief Get the physical location, in disk, of the path of the compiler.
         */
        virtual std::string getPath() const = 0;
        
        /**
         * @brief Creates a task wich will link the specified target at a later stage.
         */
        virtual std::unique_ptr<Task> createTask(const Target *target) = 0;
    };
}

#endif 
