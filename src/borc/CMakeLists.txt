
# setup borc-core
include_directories("../borc-core/")

set (target "borc")
set (sources 
	"Main.cpp"
	"ConsoleApp.hpp"
	"ConsoleApp.cpp"
)

source_group("\\" FILES ${sources})

add_executable (${target} ${sources})

target_link_libraries (
    ${target} 
    borc-core
    yaml-cpp
    fmt
)

install(TARGETS ${target} DESTINATION "bin")
