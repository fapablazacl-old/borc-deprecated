
set (target "borc-core")

set (sources 
    "borc/Task.hpp"
    "borc/Task.cpp"
    "borc/TaskPerformer.hpp"
    "borc/TaskPerformer.cpp"
    "borc/SerialTaskPerformer.hpp"
    "borc/SerialTaskPerformer.cpp"
)

add_library(${target} ${sources})
