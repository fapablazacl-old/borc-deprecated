
#ifndef __borc_taskperformer_hpp__
#define __borc_taskperformer_hpp__

#include <vector>

namespace borc {
    class Task;
    class TaskPerformer {
    public:
        virtual ~TaskPerformer();

        virtual void perform(const std::vector<Task*> &tasks) = 0;
    };
}

#endif
