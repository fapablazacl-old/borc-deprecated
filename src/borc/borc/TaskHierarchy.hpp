
#ifndef __borc_taskhierarchy_hpp__
#define __borc_taskhierarchy_hpp__

#include <memory>

namespace borc {
    class Task;

    /**
     * @brief The TaskHierarchy class provides task ownership and maintains a dependency chain between tasks.
     */
    class TaskHierarchy {
    public:
        virtual ~TaskHierarchy();

        virtual Task* addTask(std::unique_ptr<Task> task) = 0;

        virtual TaskHierarchy* setTaskDependency(const Task *task, const Task* dependency) = 0;
    };
}

#endif 
