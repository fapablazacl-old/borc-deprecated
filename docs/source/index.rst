BORC
====

Introduction
------------

BORC pretends to accelerate the development of C/C++ applications offering some features not found in other build systems out there.


Planned Features
----------------

* Declarative, high-level orchestration description files.
* Gives modularization of C/C++ projects via metadata in the description files.
* Work with more than one compiler simultaneosly (ideal for cross-compiling).
* Generates project stubs to start to work quickly.
* C++ library interface, for integration with other tools (mainly IDEs).
* Built-In support for git-based packages/repositories.
* Integration with other build systems.
* One build directory, automatic management for configurations, compilers, architectures, etc


Descriptable Entities
---------------------

* Software Artifacts (components, redistributables, manuals, etc), 
* Toolchains for not previously supported programming languages/technologies, frameworks, etc.
* File Types
* Actions
* Templates for various software artifacts.


Command Line Tool Flow 1: Generating an empty project
-----------------------------------------------------

Example::

    $ cd /path/to/project/root
    $ borc --init helloworld --version-control git
    Initializing empty project skeleton named into 'helloworld'
    $ cd helloworld
    $ borc --add 
    