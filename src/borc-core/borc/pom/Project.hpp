
#ifndef __borc_project_hpp__
#define __borc_project_hpp__

#include <string>
#include <vector>
#include <memory>

namespace borc {
    class TaskPerformer;
    class Target;
    class Version;

    /**
     * @brief Project representation
     */
    class Project {
    public:
        virtual ~Project() {}

        /**
         * @brief Get a vector of the supported Targets for the project 
         */
        virtual std::vector<Target*> getTargets() const = 0;

        /**
         * @brief Add a new target, linked to this project
         */
        virtual Target* addTarget() = 0;

        /**
         * @brief Get the name of the project
         */
        virtual std::string getName() const = 0;

        /**
         * @brief Set the name of the project
         */
        virtual Project* setName(const std::string &name) = 0;

        /**
         * @brief Get the root path
         */
        virtual std::string getPath() const = 0;

        /**
         * @brief Get the build path for the project
         */
        virtual std::string getBuildPath() const = 0;

        /**
         * @brief Set the root path of the project
         */
        virtual Project* setPath(const std::string &path) = 0;

        /**
         * @brief Prepare internal directory hierarchy for build project files
         */
        virtual Project* setup() = 0;

    public:
        /**
         * @brief Create a new instance 
         */
        static std::unique_ptr<Project> create(const std::string &name, const std::string &path="");
    };
}

#endif
