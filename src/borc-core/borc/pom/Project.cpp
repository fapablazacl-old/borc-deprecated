
#include "Project.hpp"

#include "TargetAction.hpp"
#include "ModuleTarget.hpp"
#include "Source.hpp"

#include <borc/tasks/TaskNode.hpp>

#include <stdexcept>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace borc {
    class ProjectImpl : public Project {
    public:
        explicit ProjectImpl(const std::string name, const std::string &path) {
            this->setName(name)->setPath(path);
        }
    
        virtual ~ProjectImpl() {}
    
        virtual std::vector<Target*> getTargets() const override {
            std::vector<Target*> targets;
            
            for (auto &target : m_targets) {
                targets.push_back(target.get());
            }
    
            return targets;
        }
    
        virtual Target* addTarget(std::unique_ptr<Target> targetPtr) override {
            assert(targetPtr->getProject() == this);

            auto target = targetPtr.release();

            m_targets.emplace_back(target);

            return target;
        }
    
        virtual std::string getName() const override {
            return m_name;
        }
    
        virtual Project* setName(const std::string &name) override {
            // TODO: Add validation
            m_name = name;

            return this;
        }

        virtual std::string getPath() const override {
            return m_path;
        }
    
        virtual Project* setPath(const std::string &path) override {
            // TODO: Add validation
            m_path = path;

            return this;
        }

        virtual Project* setup() override {
            if (!fs::is_directory(m_path)) {
                throw std::runtime_error("The current project path doesn't exist");
            }
            
            if (!fs::create_directory(this->getBuildPath())) {
                throw std::runtime_error("Couldn't create the .borc internal directory.");
            }

            return this;
        }

        virtual std::unique_ptr<TaskNode> createTask(const TargetAction action) override {
            if (action == TargetAction::Build) {
                return this->createBuildTask();
            } else {
                throw std::runtime_error("Unsupported Action");
            }
        }

        virtual std::string getBuildPath() const override {
            return (fs::path(m_path) / ".borc").string();
        }

    private:
        std::unique_ptr<TaskNode> createBuildTask()  {
            // TODO: Take into account dependency management
            auto taskNode = std::make_unique<TaskNode>();

            for (auto &target : m_targets) {
                auto targetTaskNode = target->createTask(TargetAction::Build);

                // TODO: Enhance the style of the TaskNode class
                taskNode->childs.push_back(std::move(targetTaskNode));
            }

            return taskNode;
        }

    private:
        std::string m_name;
        std::string m_path;
        std::vector<std::unique_ptr<Target>> m_targets;
    };

    std::unique_ptr<Project> Project::create(const std::string &name, const std::string &path) {
        return std::make_unique<ProjectImpl>(name, path);
    }
}
