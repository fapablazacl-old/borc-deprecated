
#include "ToolsetCpp.hpp"

#include "Compiler.hpp"
#include "Linker.hpp"

#include <cassert>
#include <algorithm>
#include <iostream>

#include <borc/FileTypeRegistry.hpp>
#include <borc/tasks/TaskNode.hpp>
#include <borc/tasks/Task.hpp>
#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>

#include "CompilerCpp.hpp"
#include "LinkerCpp.hpp"

namespace borc {
    ToolsetCpp::ToolsetCpp(FileTypeRegistry *registry) {
        m_c_sourceFile = registry->addFileType("C Source File", {".c"});
        m_c_headerFile = registry->addFileType("C Header File", {".h"});
        m_cpp_sourceFile = registry->addFileType("C++ Source File", {".cpp", ".cxx", ".cc", ".c++"});
        m_cpp_headerFile = registry->addFileType("C++ Header File", {".hpp", ".hxx", ".hh", ".h++"});

        m_compilers.emplace_back(new CompilerImpl(registry, "cl", {m_c_sourceFile, m_cpp_sourceFile}));
        m_linkers.emplace_back(new LinkerImpl("link"));
    }
    
    ToolsetCpp::~ToolsetCpp() {}

    std::vector<Compiler*> ToolsetCpp::getCompilers() const {
        std::vector<Compiler*> compilers;

        for (auto &compiler : m_compilers) {
            compilers.push_back(compiler.get());
        }

        return compilers;
    }
    
    std::vector<Linker*> ToolsetCpp::getLinkers() const {
        std::vector<Linker*> linkers;

        for (auto &linker: m_linkers) {
            linkers.push_back(linker.get());
        }

        return linkers;
    }

    std::unique_ptr<TaskNode> ToolsetCpp::createBuildTask(const Project *project)  {
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
