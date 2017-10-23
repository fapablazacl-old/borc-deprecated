
#include "TargetType.hpp"

namespace borc {
    std::string to_string(const TargetType type) {
        switch (type) {
        case TargetType::Program: return "TargetType::Program";
        case TargetType::Library: return "TargetType::Library";
        default: throw std::invalid_argument("Unknown target type");
        }
    }
}
