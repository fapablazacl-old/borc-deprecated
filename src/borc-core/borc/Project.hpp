
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <string>
#include <vector>
#include <memory>

namespace borc {
    class TaskPerformer;
    class Target;
    class Project {
    public:
        explicit Project(const std::string name);

        virtual ~Project();

        virtual void generateTasks(TaskPerformer *performer) const = 0;

        std::size_t getTargetCount() const;

        Target* getTarget(const std::size_t index);

        const Target* getTarget(const std::size_t index) const;

        Target* addTarget();

        std::string getName() const {
            return m_name;
        }

    private:
        std::string m_name;
        std::vector<std::unique_ptr<Target>> m_targets;
    };
}

#endif
