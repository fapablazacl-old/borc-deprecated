
#include <iostream>
#include <list>
#include <stdexcept>
#include <memory>

#include <borc/FileTypeRegistryImpl.hpp>

#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>
#include <borc/pom/ProjectParserMock.hpp>

#include <borc/toolchains/ToolchainCpp.hpp>

#include <borc/tasks/Task.hpp>
#include <borc/tasks/TaskNode.hpp>
#include <borc/tasks/TaskNodeVisitorSerial.hpp>

int main(int argc, char **argv) {
    auto registry = std::make_unique<borc::FileTypeRegistryImpl>();
    auto toolchain = std::make_unique<borc::ToolchainCpp>(registry.get());

    auto projectParser = std::make_unique<borc::ProjectParserMock>();
    auto project = projectParser->parse("nonexistingfile.any");
    auto taskTree = toolchain->createBuildTask(project.get());
    auto taskVisitor = std::make_unique<borc::TaskNodeVisitorSerial>();

    taskVisitor->visit(taskTree, [](borc::Task *task) {
        if (task) {
            task->perform();
        }
    });

    return 0;
}
