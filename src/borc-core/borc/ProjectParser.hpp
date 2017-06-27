
#ifndef __borc_projectparser_hpp__
#define __borc_projectparser_hpp__

#include <memory>
#include <string>

namespace borc {
    class Project;

    class ProjectParser {
    public:
        virtual ~ProjectParser();

        virtual std::unique_ptr<Project> parser(const std::string &file) = 0;
    };    
}

#endif 
