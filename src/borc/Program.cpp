
#include <iostream>
#include <stdexcept>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;
namespace po = boost::program_options;

int setupProject(const fs::path &path);

int main(int argc, char **argv) {
    auto desc = po::options_description("Allowed options");

    desc.add_options()
        ("help", "show this message")
        ("init,i", "setup an initial project")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;

        return 0;
    }

    if (vm.count("init")) {
        fs::path current = fs::current_path();
        
        return setupProject(current);
    }

    std::cout << desc << std::endl;

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
    /*
        project 
          borcfile
          src
    */

    // generate the main YAML description file
    /*
        project: borc
        library: borc-core
        program: borc
        program: borc-tdd
    */
    std::cout << "Initialized empty '" << name << "' project structure in '" << path.string() << "'" << std::endl;

    return 0;
}
