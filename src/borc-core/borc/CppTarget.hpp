
#ifndef __borc_cpptarget_hpp__
#define __borc_cpptarget_hpp__

#include "Project.hpp"

#include <memory>
#include <list>

namespace borc {
    enum class CppTargetType {
        Program = 1,
        Library = 2
    };

    extern std::string to_string(const CppTargetType type);

    class CppProject;
    class CppTarget {
    public:
        explicit CppTarget(CppProject *project);

        explicit CppTarget(CppProject *project, const std::string &name);

        CppProject* getProject() const {
            return m_project;
        }

        CppTarget* setName(const std::string &name);

        CppTarget* setPath(const std::string &path);

        CppTarget* setType(const CppTargetType type);

        std::string getName() const {
            return m_name;
        }

        std::string getPath() const {
            return m_path;
        }

        CppTargetType getType() const {
            return m_type;
        }

    private:
        CppProject *m_project;
        CppTargetType m_type;
        std::string m_name;
        std::string m_path;
        std::list<std::string> m_deps;
    };
}

#endif