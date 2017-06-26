
#ifndef __borc_cppproject_hpp__
#define __borc_cppproject_hpp__

#include "Project.hpp"

#include <memory>
#include <vector>

namespace borc {

    struct Target {
        std::string name;
        std::string outName;

        std::vector<std::string> files;
    };

    class CppProject : public Project {
    public:
        virtual void generateTasks(TaskPerformer *performer) const override;

    public:
        virtual ~CppProject();

        std::size_t getTargetCount() const;

        Target* getTarget(const std::size_t index);

        const Target* getTarget(const std::size_t index) const;

        void addTarget(std::unique_ptr<Target> target);

        std::unique_ptr<Target> removeTarget(Target *target);

    private:
        std::vector<std::unique_ptr<Target>> m_targets;
    };
}

#endif
