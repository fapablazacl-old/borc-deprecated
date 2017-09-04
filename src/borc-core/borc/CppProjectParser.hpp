
#ifndef __borc_cppprojectparser_hpp__
#define __borc_cppprojectparser_hpp__

#include "ProjectParser.hpp"

namespace borc {
    /**
     * @brief C/C++ Project Parser
     */
    class CppProjectParser : public ProjectParser {
    public:
        virtual ~CppProjectParser();

        /**
         * @brief Parse a XML file and return a CppProject object.
         */
        virtual std::unique_ptr<Project> parse(const std::string &file) override;
    };
}

#endif
