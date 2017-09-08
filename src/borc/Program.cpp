
#include <iostream>
#include <list>
#include <stdexcept>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "borc/Project.hpp"
#include "borc/ProjectParser.hpp"

namespace fs = boost::filesystem;
namespace po = boost::program_options;

void checkExistense(const fs::path &path);

int setupProject(const fs::path &path);

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
        fs::path borcfile = current / "borcfile.yaml";

        checkExistense(borcfile);

        auto parser = std::make_unique<borc::ProjectParser>();
        auto project = parser->parse(borcfile.string());

        std::cout << project->getName() << std::endl;

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
