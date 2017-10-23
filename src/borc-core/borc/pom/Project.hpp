
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <string>
#include <vector>
#include <memory>

namespace borc {
    class Language;

    class TaskPerformer;
    class Target;

    /**
     * @brief A Project
     */
    class Project {
    public:
        explicit Project(const std::string name, const Language *language);

        virtual ~Project();

        virtual std::vector<Target*> getTargets() const;

        Target* addTarget();

        std::string getName() const;

        std::string getPath() const;

        /**
         * @brief Get the key of the programming language used
         */
        const Language* getLanguage() const;

        /**
         * @brief Set the root path of the project
         */
        void setPath(const std::string &path);

    private:
        const Language *m_language = nullptr;
        std::string m_name;
        std::string m_path;
        std::vector<std::unique_ptr<Target>> m_targets;
    };
}

#endif
