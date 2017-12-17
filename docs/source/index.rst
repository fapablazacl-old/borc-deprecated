BORC
====

Introduction
------------

BORC pretends to accelerate the development of C/C++ applications offering some features not found in other build systems out there.


Planned Features
----------------

* Declarative, cross-platform, high-level orchestration description files.
* Work with more than one compiler simultaneosly (ideal for cross-compiling).
* Generates project stubs to start to work quickly.
* C++ library interface, for integration with other tools (mainly IDEs).
* Built-In support for git-based packages/repositories.
* Integration with other build systems.


C++ Planned Features
--------------------

* One build directory, automatic management for configurations, compilers, architectures, etc
* Gives modularization of C/C++ projects via metadata in the description files.


Descriptable Entities
---------------------

* Software Artifacts (components, redistributables, manuals, etc), 
* Toolchains for not previously supported programming languages/technologies, frameworks, etc.
* File Types
* Actions
* Templates for various software artifacts.


BORC Definitions
-------------------------

A Project:
* Has a collection of Targets

A Target:
* Is a Software Artifact
* Is based on a Target Archetype.
* Is defined by a collection of Files
* Supports a certain set of Actions

A Target Archetype:
* Is a Software Artifact Definition, used to "derive" concrete targets.
* Has a set of predefined Actions
* References a set of predefined Toolchains Kinds

A Toolchain:
* Is a collection of Compilers and Linkers.
* They are used to Build a target.

A Action:
* Is an operation applied to a Target, that can use a given Toolchain or another entity.
* That operation needs:
  * A subset of the Files contained on a Target (¿Why a subset?)
  * A Toolchain in order to process those Files 
* That operation also can have Arguments.


BORC Command Line Utility
-------------------------

The BORC Command Line Utility is the main interface for "regular" users (developers using it for managing their build system needs).
This utility must be used in order to:

* Setup an initial development project.
* Configure it with several toolchains for different purposes and/or aspects.
* Update a project, giving more capabilities, purposes, or aspects during build-time.
* Perform the building of all the targets for a fiven development project.


Scenario 1: A simple console application, that outputs 'HelloWorld from Sample Project!'
----------------------------------------------------------------------------------------

$ borc 
  Not a valid BORC directory (no file main.borc)

$ borc --working-directory sample-project/
  You are on the SampleProject project, version v1.0.0.

  Available Targets:
    SampleProject (cplusplus/executable)
    Actions:
      build, install, clean, purge, run
    
    Compatible Toolchains:
      cplusplus (system clang-5.1.2)
      asm toolchain (N/A)
    
$ cd sample-project
$ borc 
  (same output as before)

$ borc --target SampleProject --action build
  Building target SampleProject (Debug, x64),  ...
  Done.

$ borc --target SampleProject --action run
  HelloWorld from Sample Project!

Notes:
  * Actions may have dependencies between them ('run' depends on 'build')


Scenario 2: Multimedia engine project (XE)
-----------------------------------------------------------------------------
Let's suppose we have this C++ based project. It's a multimedia engine, used to make games in 3D, with bindings to Python and the Web and has the following structure:

Folder structure::
  xe/
    src/
      xe-core/
        xe/ ...
        xe-core.borc
      xe-gfx-gl3/
        xe/ ...
        xe-gfx-gl3.borc
      xe-gfx-es2/
        xe/ ...
        xe-gfx-es2.borc
      xe-sfx-al/
        xe/ ...
        xe-sfx-al.borc
      xe-python/
        xe/
        xe-python.borc
      xe-js/
        xe/
        xe-js.borc
    main.borc

Because we need to interact with another languages and systems, we require:
  * A C++ toolchain (arch: host)
  * A C++ toolchain (arch: WebAssembly, required for the Web port, optional)
  * A Python toolchain (arch: host, required for python bindings, optional)
  * A Android SDK and NDK (arch: host, target arch: ARM/x86, required for android bindings, optional).

As we can see, there is plenty of choices and configuration combinations.

In order to configure this project, let's run the following command::
  $ cd /path/to/project/xe
  $ borc configure

  Configuring project 'xe' ...
  Scanning targets, dependencies and requirements ...
  Cloning Git repositories ...

  
  Using default toolchains
    [C++] Emscripten Compiler, version 4.2.0, targeting WebAssembly, with static runtime library.
    [C++] GCC Compiler, version 7.1.0, targeting x64, with shared runtime library
    [Python] 
  
We need to compiler 
    .borc/
      {compiler}/
        {configuration}/
          {projectName}/
            bin/
              MyProject[.exe]
            obj/
              MyProject.cpp.obj
 