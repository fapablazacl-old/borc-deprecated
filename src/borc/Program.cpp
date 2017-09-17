
#include <iostream>
#include <list>
#include <stdexcept>
#include <memory>

#include <borc/pom/Project.hpp>
#include <borc/pom/Target.hpp>
#include <borc/pom/Source.hpp>
#include <borc/pom/ProjectParserMock.hpp>

int main(int argc, char **argv) {
    auto projectParser = std::make_unique<borc::ProjectParserMock>();
    auto borcProject = projectParser->parse("nonexistingfile.any");

    return 0;
}
