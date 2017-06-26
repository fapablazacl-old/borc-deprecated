
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

namespace borc {

    class TaskPerformer;
    class Project {
    public:
        virtual ~Project();

        virtual void generateTasks(TaskPerformer *performer) const = 0;
    };
}

#endif
