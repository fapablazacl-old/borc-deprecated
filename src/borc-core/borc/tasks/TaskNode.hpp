
#ifndef __borc_tasknode_hpp__
#define __borc_tasknode_hpp__

#include "Task.hpp"

#include <memory>
#include <vector>

namespace borc {
    /**
     * @brief A single task dependency hierarchy node
     */    
    class TaskNode {
    public:
        ~TaskNode();

    public:
        std::unique_ptr<Task> task;

        std::vector<std::unique_ptr<TaskNode>> childs;
    };
}

#endif
