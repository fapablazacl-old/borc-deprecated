
#include "ToolchainImpl.hpp"

#include "Compiler.hpp"
#include "Linker.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

#include <borc/tasks/TaskHierarchy.hpp>
#include <borc/tasks/Task.hpp>

#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    ToolchainImpl::ToolchainImpl() {}
    
    ToolchainImpl::~ToolchainImpl() {}

    std::vector<Compiler*> ToolchainImpl::getCompilers() const {
        std::vector<Compiler*> compilers;

        std::transform(m_compilers.begin(), m_compilers.end(), compilers.begin(), [](const auto &compiler) {
            return compiler.get();
        });

        return compilers;
    }
    
    std::vector<Linker*> ToolchainImpl::getLinkers() const {
        std::vector<Linker*> linkers;
        
        std::transform(m_linkers.begin(), m_linkers.end(), linkers.begin(), [](const auto &linker) {
            return linker.get();
        });

        return linkers;
    }

    void ToolchainImpl::setupTaskHierarchy(TaskHierarchy *hierarchy, const Project *project) {
        assert(hierarchy);
        assert(project);

        auto targets = project->getTargets();

        auto linkers = this->getLinkers();
        auto compilers = this->getCompilers();

        for (Target *target : targets) {
            Linker *linker = nullptr;

            for (Linker *linker_ : linkers) {
                if (linker_->isLinkable(target)) {
                    linker = linker_;
                    break;
                }
            }

            if (!linker) {
                std::cout 
                    << "The target " << target->getName() 
                    << " could not be built. No supported toolchain found." << std::endl;

                continue;
            }

            auto sources = target->getSources();

            for (const Source *source : sources) {
                Compiler *compiler = nullptr;

                for (Compiler *compiler_ : compilers) {
                    if (compiler_->isCompilable(source)) {
                        compiler = compiler_;
                        break;
                    }
                }

                if (!compiler) {
                    std::cout 
                        << "The source " << source->getFileName()
                        << " could not be built. No supported compiler build tool found." << std::endl;

                    continue;
                }

                auto sourceBuildTask = compiler->createTask(source);

                // TODO: Add to the build hierarchy
                // TODO: Add to the current list of tasks for the build of the target
                // TODO: Create the dependency relation between the target task and the source tasks 
                // TODO: Create the task list to make the dependencies between sources
            }
        }
    }

    void ToolchainImpl::fillHierarchy(TaskHierarchy *hierarchy, Linker *linker, Target *target) {
        assert(hierarchy);
        assert(linker);
        assert(target);

    }

    void ToolchainImpl::fillHierarchy(TaskHierarchy *hierarchy, Compiler *compiler, Source *source) {
        assert(hierarchy);
        assert(compiler);
        assert(source);

        auto sourceBuildTask = compiler->createTask(source);

        hierarchy->addTask(std::move(sourceBuildTask));
    }
}
