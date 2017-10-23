
#include "TargetImpl.hpp"

#include "Project.hpp"
#include "Source.hpp"

#include <algorithm>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace borc {
    TargetImpl::TargetImpl(Project *project) : m_project(project) {}

    TargetImpl::TargetImpl(Project *project, const std::string &name) : m_project(project) {
        this->setName(name);
    }

    TargetImpl* TargetImpl::setName(const std::string &name) {
        m_name = name;

        return this;
    }

    TargetImpl* TargetImpl::setPath(const std::string &path) {
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

    TargetImpl* TargetImpl::setType(const TargetType type) {
        m_type = type;

        return this;
    }

    TargetImpl* TargetImpl::addDependency(const Target *target) {
        m_deps.push_back(target);

        return this;
    }

    Source* TargetImpl::addSource(const std::string &filePath) {
        // TODO: Check previous existence 
        auto source = new Source(filePath, this);

        m_sources.emplace_back(source);

        return source;
    }
    
    TargetImpl* TargetImpl::removeSource(const std::string &filePath) {
        return this;
    }

    std::vector<const Target*> TargetImpl::getDependencies() const {
        return m_deps;
    }

    std::vector<const Source*> TargetImpl::getSources() const {
        std::vector<const Source*> sources;
        
        for (auto &source : m_sources) {
            sources.push_back(source.get());
        }

        return sources;
    }
}
