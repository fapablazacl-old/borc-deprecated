
#include "TaskNodeVisitorSerial.hpp"

#include "TaskNode.hpp"
#include "Task.hpp"

namespace borc {
    TaskNodeVisitorSerial::~TaskNodeVisitorSerial() {}

    void TaskNodeVisitorSerial::visit(std::unique_ptr<TaskNode> &root, std::function<void(Task*)> fn) {
        for (auto &childNode : root->childs) {
            this->visit(childNode, fn);
        }

        fn(root->task.get());
    }
}
