
#ifndef __borc_serialtaskperformer_hpp__
#define __borc_serialtaskperformer_hpp__

#include "TaskPerformer.hpp"

namespace borc {
    class SerialTaskPerformer : public TaskPerformer {
    public:
        virtual ~SerialTaskPerformer();

        virtual void perform(const std::vector<Task*> &tasks) override;
    };
}

#endif
