
#ifndef __borc_projectparser_hpp__
#define __borc_projectparser_hpp__

#include <memory>
#include <string>

namespace borc {
    class Project;
    class ProjectParser {
    public:
        ~ProjectParser() {}

        std::unique_ptr<Project> parse(const std::string &file);
    };    
}

#endif 
