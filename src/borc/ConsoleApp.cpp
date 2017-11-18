
#include "ConsoleApp.hpp"

#include <iostream>
#include <borc/FileTypeRegistry.hpp>
#include <borc/TreeNode.hpp>
#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/TargetAction.hpp>
#include <borc/pom/Source.hpp>
#include <borc/pom/ProjectParserYaml.hpp>
#include <borc/tasks/Task.hpp>
#include <borc/tasks/TaskNodeVisitor.hpp>
#include <borc/toolsets/ToolsetCpp.hpp>

namespace borc {
    class ConsoleAppImpl : public ConsoleApp {
    public:
        explicit ConsoleAppImpl(const std::string &path) {
            m_path = path;
        }

        virtual void list() override {
            auto project = this->parseProject();
            auto targets = project->getTargets();

            std::cout << "Available targets:" << std::endl;

            for (Target *target : targets) {
                std::cout << "  - " << target->getName() << std::endl;
            }
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

        virtual void init() override {
            // generate the main YAML description file
            throw std::runtime_error("Not implemented yet!");
        }

    private:
        std::unique_ptr<borc::Project> parseProject() {
            auto registry = borc::FileTypeRegistry::create();
            auto toolset = borc::ToolsetCpp::create(registry.get());
    
            auto parser = borc::ProjectParserYaml::create();
            auto project = parser->parse(m_path);
    
            auto targets = project->getTargets();
            for (borc::Target* target : targets) {
                target->setToolset(toolset.get());
            }

            return project;
        }

    private:
        std::string m_path;
    };

    std::unique_ptr<ConsoleApp> ConsoleApp::create(const std::string &path) {
        return std::make_unique<ConsoleAppImpl>(path);
    }
}
