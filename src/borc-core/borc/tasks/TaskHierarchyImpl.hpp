
#ifndef __borc_taskhierarchyimpl_hpp__
#define __borc_taskhierarchyimpl_hpp__

#include "TaskHierarchy.hpp"

#include <map>

namespace borc {
    class Task;

    /**
     * @brief The TaskHierarchyImpl class provides a default implementation for TaskHierarchy
     */
    class TaskHierarchyImpl : public TaskHierarchy {
    public:
        TaskHierarchyImpl();

        virtual ~TaskHierarchyImpl();

        virtual Task* addTask(std::unique_ptr<Task> task) override;

        virtual TaskHierarchyImpl* setTaskDependency(Task *task, Task* dependency) override;

        virtual std::vector<Task*> getTaskDependencies(Task *task) const override;

    private:
        std::vector<std::unique_ptr<Task>> m_tasks;
        std::map<Task*, std::vector<Task*>> m_taskDependencies;
    };
}

#endif 
