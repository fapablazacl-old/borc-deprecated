
#ifndef __borc_target_hpp__
#define __borc_target_hpp__

#include <memory>
#include <vector>

namespace borc {
    class Project;
    struct TaskNode;

    enum class TargetType;
    enum class TargetAction;

    /**
     * @brief A build target. Can be a documentation target, module target, etc
     */
    class Target {
    public:
        virtual ~Target();

        /**
         * @brief Get the parent project
         */
        virtual Project* getProject() const = 0;

        /**
         * @brief Set the current target name. 
         * 
         * This name must be unique among the other targets of the project.
         */
        virtual Target* setName(const std::string &name) = 0;

        /**
         * @brief Get the current target name.
         */
        virtual std::string getName() const = 0;

        /**
         * @brief Create a task hierarchy to perform the specified action on this target
         *
         * The concrete actions will depend on:
         *  - The Type of Target 
         *  - The needed Toolsets 
         */
        virtual std::unique_ptr<TaskNode> createTask(const TargetAction action) = 0;

        /**
         * @brief Gets an array of the actions supported by this target
         */
        virtual std::vector<TargetAction> supportedActions() const = 0;
    };
}

#endif
