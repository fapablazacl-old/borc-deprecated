
#ifndef __borc_tasknodevisitor_hpp__
#define __borc_tasknodevisitor_hpp__

#include <functional>
#include <memory>

namespace borc {
    class Task;
    class TaskNode;

    /**
     * @brief A task node visitor that performs the specified complete hierarchy.
     */    
    class TaskNodeVisitor {
    public:
        virtual ~TaskNodeVisitor();

        virtual void visit(std::unique_ptr<TaskNode> &root, std::function<void(Task*)> fn) = 0;
    };
}

#endif
