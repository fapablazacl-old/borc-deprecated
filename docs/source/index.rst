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


Command Line Tool Flow 1: Generating a simple, default C++ console executable
-----------------------------------------------------------------------------

Example::

    $ borc --init --name MyProject --template cpp/console-app

The command generates the following folder structure::

    MyProject/
        .borc/
        src/
    
Command Line Tool Flow 2: Generating an empty project
-----------------------------------------------------

Example::

    $ cd /path/to/project/root
    $ borc --init helloworld
    Initialized empty 'helloworld' project
    $ cd helloworld
    $ borc --name helloworld --language cplusplus --add component 
    Added component helloworld
