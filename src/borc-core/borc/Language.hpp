
#ifndef __borc_language_hpp__
#define __borc_language_hpp__

#include <vector>

namespace borc {

    class Toolset;
    class FileType;

    /**
     * @brief A language corresponding to a file type
     */
    class Language {
    public:
        virtual ~Language();

        /**
         * @brief Get a list of the supported toolset
         */
        virtual std::vector<Toolset*> getToolsets() = 0;

        virtual bool test(const std::string &fileName) const = 0;
    };
}

#endif 
