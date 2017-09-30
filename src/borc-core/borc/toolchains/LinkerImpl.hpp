
#ifndef __borc_linkerimpl_hpp__
#define __borc_linkerimpl_hpp__

#include "Linker.hpp"

#include <string>
#include <memory>

namespace borc {
    class Task;

    class Source;
    class Target;

    class LinkerImpl : public Linker {
    public:
        explicit LinkerImpl(const std::string &toolName);

        explicit LinkerImpl(const std::string &toolName, const std::string &path);

        virtual ~LinkerImpl();

        virtual bool isLinkable(const Target *target) const override;

        virtual std::string getToolName() const override;

        virtual std::string getPath() const override;
        
        virtual std::unique_ptr<Task> createTask(const Target *target) override;

    private:
        std::string m_toolName;
        std::string m_path;
    };
}

#endif 