
#ifndef __borc_target_hpp__
#define __borc_target_hpp__

#include "Project.hpp"

#include <memory>
#include <list>

namespace borc {
    enum class TargetType {
        Program = 1,
        Library = 2
    };

    extern std::string to_string(const TargetType type);

    class Project;
    class Target {
    public:
        explicit Target(Project *project);

        explicit Target(Project *project, const std::string &name);

        Project* getProject() const {
            return m_project;
        }

        Target* setName(const std::string &name);

        Target* setPath(const std::string &path);

        Target* setType(const TargetType type);

        std::string getName() const {
            return m_name;
        }

        std::string getPath() const {
            return m_path;
        }

        TargetType getType() const {
            return m_type;
        }

    private:
        Project *m_project;
        TargetType m_type;
        std::string m_name;
        std::string m_path;
        std::list<std::string> m_deps;
    };
}

#endif
