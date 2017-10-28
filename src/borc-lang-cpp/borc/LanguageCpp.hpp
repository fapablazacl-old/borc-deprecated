
#ifndef __borc_languagecpp_hpp__
#define __borc_languagecpp_hpp__

#include <borc/Language.hpp>

namespace borc {
    /**
     * @brief Adds support for the C++ language
     */
    class LanguageCpp : public Language {
    public:
        LanguageCpp();

        virtual ~LanguageCpp();

        virtual std::string getName() const override;
        
        virtual std::vector<Toolset*> getToolsets() override;

        virtual bool test(const std::string &fileName) const override;

    private:
        std::string m_name;
    };
}

#endif
