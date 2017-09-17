
# setup borc-core
include_directories("../borc-core/")

# setup boost
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)

set (target "borc")
set (sources 
    "Program.cpp"
)

set (sources_borc
    "borc/Task.hpp"
    "borc/Task.cpp"
    "borc/CommandTask.hpp"
    "borc/CommandTask.cpp"
    "borc/TaskPerformer.hpp"
    "borc/TaskPerformer.cpp"
    "borc/SerialTaskPerformer.hpp"
    "borc/SerialTaskPerformer.cpp"

	"borc/FileTypeRegistry.hpp"
	"borc/FileTypeRegistry.cpp"
)

set (sources_borc_pom
	"borc/pom/Target.hpp"
    "borc/pom/Target.cpp"
    "borc/pom/Project.hpp"
    "borc/pom/Project.cpp"
    "borc/pom/Source.hpp"
    "borc/pom/Source.cpp"
    #"borc/pom/ProjectParser.hpp"
    #"borc/pom/ProjectParser.cpp"
)

set (sources_borc_cpp
    # C++ language support
    "borc/cpp/CppProject.hpp"
    "borc/cpp/CppProject.cpp"
)

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
    filesystem
)

include_directories(${Boost_INCLUDE_DIRS})

source_group("\\" FILES ${sources})
source_group("\\borc" FILES ${sources_borc})
source_group("\\borc\\pom" FILES ${sources_borc_pom})
source_group("\\borc\\cpp" FILES ${sources_borc_cpp})

add_executable (${target} 
	${sources}
	${sources_borc}
	${sources_borc_pom}
	${sources_borc_cpp}
)

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    #borc-core
    #yaml-cpp
)

install(TARGETS ${target} DESTINATION "bin")
