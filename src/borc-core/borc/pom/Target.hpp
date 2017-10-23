
#ifndef __borc_target_hpp__
#define __borc_target_hpp__

#include <memory>
#include <vector>

namespace borc {
    class Source;
    class Project;

    enum class TargetType;

    class Target {
    public:
        virtual ~Target();

        /**
         * @brief
         */
        virtual Project* getProject() const = 0;

        /**
         * @brief
         */
        virtual Target* setName(const std::string &name) = 0;

        /**
         * @brief
         */
        virtual Target* setPath(const std::string &path) = 0;

        /**
         * @brief
         */
        virtual Target* setType(const TargetType type) = 0;

        /**
         * @brief
         */
        virtual std::string getName() const = 0;

        /**
         * @brief
         */
        virtual std::string getPath() const = 0;

        /**
         * @brief
         */
        virtual TargetType getType() const = 0;

        /**
         * @brief
         */
        virtual Target* addDependency(const Target *target) = 0;

        /**
         * @brief
         */
        virtual std::vector<const Target*> getDependencies() const = 0;

        /**
         * @brief
         */
        virtual Source* addSource(const std::string &filePath) = 0;

        /**
         * @brief
         */
        virtual Target* removeSource(const std::string &filePath) = 0;

        /**
         * @brief Scans the project path and all its subdirectories for source files, for this target
         */
        virtual std::vector<const Source*> getSources() const = 0;
    };
}

#endif
