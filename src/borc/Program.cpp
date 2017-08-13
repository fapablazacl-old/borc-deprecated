
#include <iostream>
#include <list>
#include <stdexcept>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

namespace fs = boost::filesystem;
namespace po = boost::program_options;

int setupProject(const fs::path &path);
int buildProject(const fs::path &path);

int borc_main(const po::variables_map &vm, const po::options_description &desc);

int main(int argc, char **argv) {

    try {
        auto desc = po::options_description("Allowed options");

        desc.add_options()
            ("init,i", "setup an initial project")
            ("build,b", "build the current project")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        return borc_main(vm, desc);

    } catch (const std::runtime_error &exp) {
        std::cout << "The following error occurred:" << std::endl;
        std::cout << exp.what() << std::endl;

        return 1;
    } catch (const std::exception &exp) {
        std::cout << "The following unexcepted error occurred:" << std::endl;
        std::cout << exp.what() << std::endl;

        return 2;
    } catch (...) {
        std::cout << "FATAL unknown error occurred." << std::endl;
        return 3;
    }
}

int borc_main(const po::variables_map &vm, const po::options_description &desc) {
    if (vm.count("init")) {
        fs::path current = fs::current_path();
        
        setupProject(current);
    } else if (vm.count("build")) {
        fs::path current = fs::current_path();
        buildProject(current / "borcfile.yaml");
    } else {
        std::cout << desc << std::endl;
    }

    return 0;
}

void checkEmpty(const fs::path &path) {
    const bool empty = true;

    if (!empty) {
        throw std::runtime_error("The folder '" + path.string() + "' isn't empty.");
    }
}

int setupProject(const fs::path &path) {
    checkEmpty(path);

    // by default, take the current folder name as the project name
    const std::string name = path.filename().string();

    // generate the project structure

    // generate the main YAML description file
    std::cout << "Initialized empty '" << name << "' project structure in '" << path.string() << "'" << std::endl;

    return 0;
}

void checkExistense(const fs::path &path) {
    if (!fs::exists(path)) {
        const std::string msg = 
            "The file '" + path.string() + "' wasn't found";

        throw std::runtime_error(msg);
    }
}

enum class TargetType {
    Program = 1, 
    Library = 2
};

std::string to_string(const TargetType type) {
    switch (type) {
        case TargetType::Program: return "TargetType::Program";
        case TargetType::Library: return "TargetType::Library";
    }
}

struct Target {
    std::string name;
    std::string path;
    std::list<std::string> deps;
    TargetType type;
};

struct Project {
    std::string name;
    std::list<Target> targets;
};

Target parseTarget(const YAML::Node &node) {
    Target target;

    // get name
    target.name = node["name"].as<std::string>();

    // get target relative directory
    if (node["path"]) {
        target.path = node["path"].as<std::string>();
    } else {
        target.path = target.name;
    }

    // get target dependencies 
    if (node["imports"]) {
        if (node["imports"].IsSequence()) {
            for (const YAML::Node &depNode : node["imports"]) {
                target.deps.push_back(depNode.as<std::string>());
            }
        } else {
            const auto dep = node["imports"].as<std::string>();
            target.deps.push_back(dep);
        }
    }

    return target;
}

Project parseProject(const YAML::Node &node) {
    Project project;

    project.name = node["name"].as<std::string>();

    return project;
}

int buildProject(const fs::path &path) {
    checkExistense(path);

    YAML::Node borcfile = YAML::LoadFile(path.string());

    if (!borcfile["project"]) {
        throw std::runtime_error("There isn't a 'project' section defined");
    }

    if (!borcfile["targets"] || borcfile["targets"].size() == 0) {
        throw std::runtime_error("There isn't a 'targets' section defined");
    }

    Project project = parseProject(borcfile["project"]);

    for (const YAML::Node targetNode : borcfile["targets"]) {
        Target target = parseTarget(targetNode);

        if (targetNode["library"]) {
            target.type = TargetType::Library;
        } else if (targetNode["program"]) {
            target.type = TargetType::Program;
        }

        project.targets.push_back(target);
    }
    
    return 0;
}
