
set (target "borc-core")

set (sources 
    "borc/Task.hpp"
    "borc/Task.cpp"
    "borc/CommandTask.hpp"
    "borc/CommandTask.cpp"
    "borc/TaskPerformer.hpp"
    "borc/TaskPerformer.cpp"
    "borc/SerialTaskPerformer.hpp"
    "borc/SerialTaskPerformer.cpp"
    "borc/Project.hpp"
    "borc/Project.cpp"
)

add_library(${target} ${sources})
