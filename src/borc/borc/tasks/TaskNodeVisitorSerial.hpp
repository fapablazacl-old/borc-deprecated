
#ifndef __borc_tasknodevisitorserial_hpp__
#define __borc_tasknodevisitorserial_hpp__

#include "TaskNodeVisitor.hpp"

namespace borc {
    /**
     * @brief A task node visitor that performs the specified complete hierarchy.
     */    
    class TaskNodeVisitorSerial : public TaskNodeVisitor {
    public:
        virtual ~TaskNodeVisitorSerial();

        virtual void visit(std::unique_ptr<TaskNode> &root, std::function<void(Task*)> fn) override;
    };
}

#endif
