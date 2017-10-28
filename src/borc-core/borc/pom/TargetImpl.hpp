
#ifndef __borc_targetimpl_hpp__
#define __borc_targetimpl_hpp__

#include <memory>
#include <vector>

#include "Target.hpp"

namespace borc {
    class Source;
    class Project;

    enum class TargetType;

    class TargetImpl : public Target {
    public:
        explicit TargetImpl(Project *project);

        explicit TargetImpl(Project *project, const std::string &name);

        virtual ~TargetImpl() {}

        virtual Project* getProject() const override {
            return m_project;
        }

        virtual TargetImpl* setName(const std::string &name) override;

        virtual TargetImpl* setPath(const std::string &path) override;

        virtual TargetImpl* setType(const TargetType type) override;

        virtual std::string getName() const override {
            return m_name;
        }

        virtual std::string getPath() const override {
            return m_path;
        }

        virtual TargetType getType() const override {
            return m_type;
        }

        virtual TargetImpl* addDependency(const Target *target) override;

        virtual std::vector<const Target*> getDependencies() const override;

        virtual Source* addSource(const std::string &filePath) override;

        virtual TargetImpl* removeSource(const std::string &filePath) override;

        virtual std::vector<const Source*> getSources() const override;

    private:
        Project *m_project;
        TargetType m_type;
        std::string m_name;
        std::string m_path;
        std::vector<const Target*> m_deps;
        std::vector<std::unique_ptr<const Source>> m_sources;
    };
}

#endif
