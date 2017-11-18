
#include "ProjectParserYaml.hpp"

#include <borc/Version.hpp>
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

#include "ModuleTarget.hpp"
#include "ModuleTargetType.hpp"
#include "Project.hpp"

namespace fs = boost::filesystem;

namespace borc {

    class ProjectParserYamlImpl : public ProjectParserYaml {
    public:
        virtual ~ProjectParserYamlImpl() {}

        virtual std::unique_ptr<Project> parse(const std::string &file) override {
            fs::path path(file);

            YAML::Node borcfile = YAML::LoadFile(path.string());

            if (!borcfile["project"]) {
                throw std::runtime_error("There isn't a 'project' section defined");
            }
            
            auto projectNode = borcfile["project"];
            auto project = this->parseProject(projectNode);
            for (const YAML::Node targetNode : borcfile["target"]) {
                this->parseTarget(project.get(), targetNode);
            }

            return project;
        }

    private:
        std::unique_ptr<Project> parseProject(const YAML::Node &node) {
            auto name = node["name"].as<std::string>();
            auto project = Project::create(name);

            // auto version = node["version"].as<std::string>();
            // project->setVersion(Version::parse(version));

            return project;
        }

        Target* parseTarget(Project *project, const YAML::Node &node) {
            auto name = node["name"].as<std::string>();
            auto type = node["type"].as<std::string>();
            auto path = node["path"].as<std::string>();

            if (type == "library" || type == "program") {
                // module target!
                auto target = project->createTarget<ModuleTarget>();

                target->setName(name);
                target->setPath(path);
                
                if (type == "library") {
                    target->setType(ModuleTargetType::Library);
                } else if (type == "program") {
                    target->setType(ModuleTargetType::Program);
                }

                return target;
            } else {
                throw std::runtime_error("Unsupported target type");
            }
        }
    };

    std::unique_ptr<ProjectParserYaml> ProjectParserYaml::create() {
        return std::make_unique<ProjectParserYamlImpl>();
    }
}
