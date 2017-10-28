
#include "ModuleTarget.hpp"
#include "ModuleTargetType.hpp"
#include "Project.hpp"
#include "Source.hpp"
#include "TargetAction.hpp"

#include <algorithm>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace borc {
    class ModuleTargetImpl : public ModuleTarget {
    public:
        explicit ModuleTargetImpl(Project *project) : m_project(project) {}

        virtual ~ModuleTargetImpl() {}

        virtual Project* getProject() const override {
            return m_project;
        }

        virtual ModuleTargetImpl* setName(const std::string &name) override {
            m_name = name;

            return this;
        }

        virtual std::string getName() const override {
            return m_name;
        }

        virtual std::unique_ptr<TaskNode> createTask(const TargetAction action) = 0;

        virtual std::vector<TargetAction> supportedActions() const override {
            return {TargetAction::Build};
        }

        virtual Language* getLanguage() const override {
            return m_language;
        }

        virtual ModuleTarget* setLanguage(Language *language) override {
            m_language = language;

            return this;
        }

        virtual ModuleTargetImpl* setPath(const std::string &path) override {
            // TODO: Make the borc::Target class aware of changes in the filesystem automatically
            namespace fs = boost::filesystem;

            fs::path fullpath = fs::path(m_project->getPath()) / fs::path(path);

            if (!fs::is_directory(fullpath)) {
                // TODO: Add target name and directory relative path
                throw std::runtime_error("The target directory isn't a directory");
            }

            m_path = path;
            m_sources.clear();

            for (auto &entry : boost::make_iterator_range(fs::recursive_directory_iterator(fullpath), {})) {
                fs::path sourcePath = entry.path();

                if (fs::is_directory(sourcePath)) {
                    continue;
                }

                m_sources.emplace_back(new Source(sourcePath.string(), this));
            }

            return this;
        }

        virtual ModuleTargetImpl* setType(const ModuleTargetType type) override {
            m_type = type;

            return this;
        }

        virtual ModuleTargetType getType() const override {
            return m_type;
        }

        virtual ModuleTargetImpl* addDependency(const Target *target) override {
            m_deps.push_back(target);

            return this;
        }

        virtual Source* addSource(const std::string &filePath) override {
            // TODO: Check previous existence 
            auto source = new Source(filePath, this);

            m_sources.emplace_back(source);

            return source;
        }
    
        virtual ModuleTargetImpl* removeSource(const std::string &filePath) override {
            return this;
        }

        virtual std::vector<const Target*> getDependencies() const override {
            return m_deps;
        }

        virtual std::vector<const Source*> getSources() const override {
            std::vector<const Source*> sources;
        
            for (auto &source : m_sources) {
                sources.push_back(source.get());
            }

            return sources;
        }

    private:
        Project *m_project;
        std::string m_name;
        Language *m_language;
        ModuleTargetType m_type;
        std::string m_path;
        std::vector<const Target*> m_deps;
        std::vector<std::unique_ptr<const Source>> m_sources;
    };

    std::unique_ptr<ModuleTarget> ModuleTarget::create(Project *project) {
        return std::make_unique<ModuleTargetImpl>(project);
    }
}
