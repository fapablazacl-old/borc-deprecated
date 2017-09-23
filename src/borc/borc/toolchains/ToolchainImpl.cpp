
#include "ToolchainImpl.hpp"

#include "Compiler.hpp"
#include "Linker.hpp"

#include "CompilerImpl.hpp"
#include "LinkerImpl.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

#include <borc/FileTypeRegistry.hpp>
#include <borc/tasks/TaskNode.hpp>
#include <borc/tasks/Task.hpp>
#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>

namespace borc {
    ToolchainImpl::ToolchainImpl(const FileTypeRegistry *registry) {
        m_compilers.emplace_back(new CompilerImpl(registry, "g++", {borc::FileType::Cplusplus}));
        m_linkers.emplace_back(new LinkerImpl("ld"));
    }
    
    ToolchainImpl::~ToolchainImpl() {}

    std::vector<Compiler*> ToolchainImpl::getCompilers() const {
        std::vector<Compiler*> compilers;

        for (auto &compiler : m_compilers) {
            compilers.push_back(compiler.get());
        }

        return compilers;
    }
    
    std::vector<Linker*> ToolchainImpl::getLinkers() const {
        std::vector<Linker*> linkers;

        for (auto &linker: m_linkers) {
            linkers.push_back(linker.get());
        }

        return linkers;
    }

    std::unique_ptr<TaskNode> ToolchainImpl::createBuildTask(const Project *project)  {
        assert(project);

        auto projectTaskNode = std::make_unique<TaskNode>();

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
                continue;
            }

            auto targetTaskNode = std::make_unique<TaskNode>();
            auto targetTask = linker->createTask(target);

            targetTaskNode->task = std::move(targetTask);

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
                    continue;
                }

                auto sourceTaskNode = std::make_unique<TaskNode>();
                auto sourceTask = compiler->createTask(source);

                sourceTaskNode->task = std::move(sourceTask);

                targetTaskNode->childs.push_back(std::move(sourceTaskNode));
            }

            projectTaskNode->childs.push_back(std::move(targetTaskNode));
        }

        return projectTaskNode;
    }
}
