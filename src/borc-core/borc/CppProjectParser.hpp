
#ifndef __borc_cppprojectparser_hpp__
#define __borc_cppprojectparser_hpp__

#include "ProjectParser.hpp"

namespace borc {
    class CppProjectParser : public ProjectParser {
    public:
        virtual ~CppProjectParser();

        virtual std::unique_ptr<Project> parser(const std::string &file) = 0;
    };
}

#endif
