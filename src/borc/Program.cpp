
#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char **argv) {
    namespace po = boost::program_options;
    
    auto desc = po::options_description("Allowed options");

    desc.add_options()
        ("help", "")
        ("compression", po::value<int>(), "set compression level")
    ;

    return 0;
}
