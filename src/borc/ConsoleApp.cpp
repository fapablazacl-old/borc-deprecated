
#include "ConsoleApp.hpp"

#include <borc/FileTypeRegistry.hpp>
#include <borc/TreeNode.hpp>
#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/TargetAction.hpp>
#include <borc/pom/Source.hpp>
#include <borc/pom/ProjectParserMock.hpp>
#include <borc/tasks/Task.hpp>
#include <borc/tasks/TaskNodeVisitor.hpp>
#include <borc/toolsets/ToolsetCpp.hpp>

namespace borc {
    class ConsoleAppImpl : public ConsoleApp {
    public:
        ConsoleAppImpl(const std::string &path) {
            m_path = path;
        }

        virtual std::vector<std::string> listTargets() override {
            std::vector<std::string> targets;

            auto project = this->parseProject();

            project->

            return targets;
        }
        
        virtual void build(const std::string &targetName) override {
            auto project = this->parseProject(); 
            auto taskTree = project->createTask(borc::TargetAction::Build);
            auto taskVisitor = borc::TaskNodeVisitor::create();
    
            taskVisitor->visit(taskTree.get(), [](borc::Task *task) {
                if (task) {
                    task->perform();
                }
            });
        }

    private:
        std::unique_ptr<borc::Project> parseProject() {
            auto registry = borc::FileTypeRegistry::create();
            auto toolset = borc::ToolsetCpp::create(registry.get());
    
            auto projectParser = borc::ProjectParserMock();
            auto project = projectParser.parse("nonexistingfile.any");
    
            auto targets = project->getTargets();
            for (borc::Target* target : targets) {
                target->setToolset(toolset.get());
            }
        }

    private:
        std::string m_path;
    };

    std::unique_ptr<ConsoleApp> ConsoleApp::create(const std::string &path) {
        return std::make_unique<ConsoleAppImpl>(path);
    }
}
