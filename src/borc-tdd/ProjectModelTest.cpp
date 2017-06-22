
#include <UnitTest++/UnitTest++.h>

#include <string>

namespace borc {
    class Project {
    public:
        std::string getName() const {
            return m_name;
        }

        void setName(const std::string &name) {
            m_name = name;
        }

    private:
        std::string m_name;
    };
}

SUITE(ProjectModelTest)
{
    TEST(Project) {
        borc::Project prj;

        const std::string projectName = "testProject";

        prj.setName(projectName);

        CHECK_EQUAL(prj.getName(), projectName);
    }
}
