
# setup borc-core
include_directories("../borc-core/")

# setup boost
set (Boost_USE_STATIC_LIBS OFF)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)

add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_PROGRAM_OPTIONS_DYN_LINK)

set (target "borc-core")
set (sources )

set (sources_borc
    "borc/Version.hpp"
    "borc/Version.cpp"
	"borc/Language.hpp"
	"borc/Language.cpp"
	"borc/FileType.hpp"
    "borc/FileType.cpp"
	"borc/FileTypeRegistry.hpp"
    "borc/FileTypeRegistry.cpp"
	"borc/TreeNode.hpp"
    "borc/TreeNode.cpp"
)

set (sources_borc_tasks
    "borc/tasks/Task.hpp"
    "borc/tasks/Task.cpp"
	"borc/tasks/TaskNodeVisitor.hpp"
    "borc/tasks/TaskNodeVisitor.cpp"
	"borc/tasks/TaskNodeVisitorSerial.hpp"
    "borc/tasks/TaskNodeVisitorSerial.cpp"
    "borc/tasks/LogTask.hpp"
    "borc/tasks/LogTask.cpp"
    "borc/tasks/CommandTask.hpp"
    "borc/tasks/CommandTask.cpp"
)

set (sources_borc_pom
	"borc/pom/TargetAction.hpp"
    "borc/pom/TargetAction.cpp"
	"borc/pom/Target.hpp"
    "borc/pom/Target.cpp"

	"borc/pom/ModuleTarget.hpp"
    "borc/pom/ModuleTarget.cpp"
	"borc/pom/ModuleTargetType.hpp"
    "borc/pom/ModuleTargetType.cpp"

    "borc/pom/Project.hpp"
    "borc/pom/Project.cpp"
    "borc/pom/Source.hpp"
    "borc/pom/Source.cpp"
    "borc/pom/ProjectParser.hpp"
    "borc/pom/ProjectParser.cpp"
    "borc/pom/ProjectParserMock.hpp"
    "borc/pom/ProjectParserMock.cpp"
)

set (sources_borc_toolset
    "borc/toolsets/Compiler.hpp"
    "borc/toolsets/Compiler.cpp"
	"borc/toolsets/CompilerCpp.hpp"
    "borc/toolsets/CompilerCpp.cpp"
    "borc/toolsets/Linker.hpp"
    "borc/toolsets/Linker.cpp"
	"borc/toolsets/LinkerCpp.hpp"
    "borc/toolsets/LinkerCpp.cpp"
    "borc/toolsets/Toolset.hpp"
    "borc/toolsets/Toolset.cpp"
	"borc/toolsets/ToolsetCpp.hpp"
    "borc/toolsets/ToolsetCpp.cpp"
)

set (sources_borc_cpp
    
)

find_package(Boost 1.45.0 REQUIRED COMPONENTS
    program_options
    filesystem
)

include_directories(${Boost_INCLUDE_DIRS})

source_group("\\"                   FILES ${sources})
source_group("\\borc"               FILES ${sources_borc})
source_group("\\borc\\tasks"        FILES ${sources_borc_tasks})
source_group("\\borc\\pom"          FILES ${sources_borc_pom})
source_group("\\borc\\cpp"          FILES ${sources_borc_cpp})
source_group("\\borc\\toolsets"   FILES ${sources_borc_toolset})

add_library (${target} 
	${sources}
    ${sources_borc}
    ${sources_borc_tasks}
	${sources_borc_pom}
    ${sources_borc_cpp}
    ${sources_borc_toolset}
)

target_link_libraries (
    ${target} 
    ${Boost_LIBRARIES} 
    #yaml-cpp
    fmt
)

install(TARGETS ${target} DESTINATION "bin")
