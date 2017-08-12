
#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char **argv) {
    namespace po = boost::program_options;
    
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
        std::cout << "Initialized empty project structure on the folder current folder." << std::endl;
    }

    return 0;
}
