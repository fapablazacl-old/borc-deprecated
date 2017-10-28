
#include "LanguageCpp.hpp"

namespace borc {
    LanguageCpp::LanguageCpp() {}
    
    LanguageCpp::~LanguageCpp() {}

    std::string LanguageCpp::getName() const {
        return "cplusplus";
    }
    
    std::vector<Toolset*> LanguageCpp::getToolsets() {
        throw std::runtime_error("");
    }

    bool LanguageCpp::test(const std::string &fileName) const {
        throw std::runtime_error("");
    }
}
