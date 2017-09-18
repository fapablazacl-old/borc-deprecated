
#include "TaskHierarchyImpl.hpp"
#include "Task.hpp"

namespace borc {
    TaskHierarchyImpl::TaskHierarchyImpl() {}

    TaskHierarchyImpl::~TaskHierarchyImpl() {}

    Task* TaskHierarchyImpl::addTask(std::unique_ptr<Task> task) {
        Task *taskPtr = task.get();

        m_tasks.push_back(std::move(task));

        return taskPtr;
    }

    TaskHierarchyImpl* TaskHierarchyImpl::setTaskDependency(const Task *task, const Task* dependency) {
        m_taskDependencies[task].push_back(dependency);
        return this;
    }
}
