
#ifndef __borc_cppproject_hpp__
#define __borc_cppproject_hpp__

#include "Project.hpp"

#include <memory>
#include <vector>

namespace borc {
    class CppTarget;
    class CppProject : public Project {
    public:
        virtual void generateTasks(TaskPerformer *performer) const override;

    public:
        explicit CppProject(const std::string name);

        virtual ~CppProject();

        std::size_t getTargetCount() const;

        CppTarget* getTarget(const std::size_t index);

        const CppTarget* getTarget(const std::size_t index) const;

        CppTarget* addTarget();

        std::string getName() const {
            return m_name;
        }

    private:
        std::string m_name;
        std::vector<std::unique_ptr<CppTarget>> m_targets;
    };
}

#endif
