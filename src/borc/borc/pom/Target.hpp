
#ifndef __borc_target_hpp__
#define __borc_target_hpp__

#include <memory>
#include <vector>

namespace borc {
    enum class TargetType {
        Program = 1,
        Library = 2
    };

    extern std::string to_string(const TargetType type);

    class Source;
    class Project;
    class Target {
    public:
        explicit Target(Project *project);

        explicit Target(Project *project, const std::string &name);

        Project* getProject() const {
            return m_project;
        }

        Target* setName(const std::string &name);

        Target* setPath(const std::string &path);

        Target* setType(const TargetType type);

        std::string getName() const {
            return m_name;
        }

        std::string getPath() const {
            return m_path;
        }

        TargetType getType() const {
            return m_type;
        }

        Target* addDependency(const Target *target);

        std::size_t getDependencyCount() const {
            return m_deps.size();
        }

        const Target* getDependency(const std::size_t index) const {
            return m_deps[index];
        }

        Source* addSource(const std::string &filePath);

        Target* removeSource(const std::string &filePath);

        std::size_t getSourceCount() const;

        const Source* getSource(const std::size_t index) const;
        
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
