
#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char **argv) {
    namespace po = boost::program_options;
    
    auto desc = po::options_description("Allowed options");

    desc.add_options()
        ("help", "")
        ("generate,g", po::value<int>(), "generate skeleton project")
        ("build,b", po::value<int>(), "build project")
        ("configure,c", po::value<int>(), "configure project")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    if (vm.count("compression")) {
        std::cout << "Level compression " << vm["compression"].as<int>() << std::endl;
    } else {
        std::cout << "There is no compression level" << std::endl;
    }

    return 0;
}
