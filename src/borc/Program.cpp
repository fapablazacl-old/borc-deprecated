
#include <iostream>
#include <list>
#include <stdexcept>
#include <memory>

#include <borc/FileTypeRegistry.hpp>
#include <borc/TreeNode.hpp>
#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/TargetAction.hpp>
#include <borc/pom/Source.hpp>
#include <borc/pom/ProjectParserMock.hpp>
#include <borc/tasks/Task.hpp>
#include <borc/tasks/TaskNodeVisitorSerial.hpp>
#include <borc/toolsets/ToolsetCpp.hpp>

int main(int argc, char **argv) {
    auto registry = borc::FileTypeRegistry::create();
    auto toolchain = borc::ToolsetCpp::create(registry.get());

    auto projectParser = std::make_unique<borc::ProjectParserMock>();
    auto project = projectParser->parse("nonexistingfile.any");
    auto taskTree = project->createTask(borc::TargetAction::Build);
    auto taskVisitor = std::make_unique<borc::TaskNodeVisitorSerial>();

    taskVisitor->visit(taskTree.get(), [](borc::Task *task) {
        if (task) {
            task->perform();
        }
    });

    return 0;
}
