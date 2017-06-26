
#include "SerialTaskPerformer.hpp"
#include "Task.hpp"

namespace borc {
    SerialTaskPerformer::~SerialTaskPerformer() {}

    void SerialTaskPerformer::perform(const std::vector<Task*> &tasks) {
        for (Task *task : tasks) {
            task->perform();
        }
    }
}
