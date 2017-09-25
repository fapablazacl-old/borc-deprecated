
#ifndef __borc_projectparseryaml_hpp__
#define __borc_projectparseryaml_hpp__

#include "ProjectParser.hpp"

namespace borc {
    class Project;
    class ProjectParserYaml : public ProjectParser {
    public:
        ~ProjectParserYaml() {}

        virtual std::unique_ptr<Project> parse(const std::string &file) override;
    };    
}

#endif 
