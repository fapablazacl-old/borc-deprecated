
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <string>
#include <vector>
#include <memory>

namespace borc {
    class TaskPerformer;
    class Target;
    class Project {
    public:
        explicit Project(const std::string name);

        virtual ~Project();

        std::size_t getTargetCount() const;

        Target* getTarget(const std::size_t index);

        const Target* getTarget(const std::size_t index) const;

        Target* addTarget();

        std::string getName() const;

        std::string getPath() const;

        void setPath(const std::string &path);

    private:
        std::string m_name;
        std::string m_path;
        std::vector<std::unique_ptr<Target>> m_targets;
    };
}

#endif
