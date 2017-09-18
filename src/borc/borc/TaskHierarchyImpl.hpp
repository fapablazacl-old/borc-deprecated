
#ifndef __borc_taskhierarchyimpl_hpp__
#define __borc_taskhierarchyimpl_hpp__

#include "TaskHierarchy.hpp"

#include <vector>
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

        virtual TaskHierarchyImpl* setTaskDependency(const Task *task, const Task* dependency) override;

    private:
        std::vector<std::unique_ptr<Task>> m_tasks;
        std::map<const Task*, std::vector<const Task*>> m_taskDependencies;
    };
}

#endif 
