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


Scenario 1: Multimedia engine project (XE)
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
