
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <string>

namespace borc {

    class TaskPerformer;
    class Project {
    public:
        virtual ~Project();

        virtual std::string getName() const = 0;

        virtual void generateTasks(TaskPerformer *performer) const = 0;
    };
}

#endif
