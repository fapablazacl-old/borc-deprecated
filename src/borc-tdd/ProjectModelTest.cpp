
#include <catch.hpp>
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

TEST_CASE("Project class behaves correctly", "[borc::Project]") {
    borc::Project prj;
    const std::string projectName = "testProject";

    prj.setName(projectName);

    REQUIRE(prj.getName() == projectName);
}
