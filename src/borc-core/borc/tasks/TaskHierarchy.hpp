
#ifndef __borc_taskhierarchy_hpp__
#define __borc_taskhierarchy_hpp__

#include <memory>
#include <vector>

namespace borc {
    class Task;

    /**
     * @brief The TaskHierarchy class provides task ownership and maintains a dependency chain between tasks.
     */
    class TaskHierarchy {
    public:
        virtual ~TaskHierarchy();

        virtual Task* addTask(std::unique_ptr<Task> task) = 0;

        virtual TaskHierarchy* setTaskDependency(Task *task, Task* dependency) = 0;

        virtual std::vector<Task*> getTaskDependencies(Task *task) const = 0;
    };
}

#endif 
