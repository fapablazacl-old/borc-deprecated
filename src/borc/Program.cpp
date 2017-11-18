
#include <iostream>
#include <list>
#include <stdexcept>
#include <memory>

#include "ConsoleApp.hpp"

int main(int argc, char **argv) {
    try {
        auto consoleApp = borc::ConsoleApp::create("");
        auto targetNames = consoleApp->listTargets();

        std::cout << "Available targets:" << std::endl;

        for (const std::string &name : targetNames) {
            std::cout << "    * " << name << std::endl;
        }

        /*
        auto taskTree = project->createTask(borc::TargetAction::Build);
        auto taskVisitor = borc::TaskNodeVisitor::create();

        taskVisitor->visit(taskTree.get(), [](borc::Task *task) {
            if (task) {
                task->perform();
            }
        });
        */
    } catch (const std::exception &exp) {
        std::cout << exp.what() << std::endl;
    }

    return 0;
}
