# backupnado
Backup tool for Windows and Linux based on libgit2

##Purpose
Backupnado is a configurable backup program that can backup folders from your computer to a remote location. For storage
it will use a git repository as a backend. Several computers can backup into one git repository. Internally, git de-duplicates
files which means that storage is only needed for the parts that change. File metadata like timestamps or access rights are
not preserved, so this tool should only be used in a private context where security is dealt with by means of physical access.
My personal use case is, that I use several computers, some Windows, some Linux machines, and they mainly contain the same
or similar files, and I want to be able to backup them on a NAS but not duplicate files too much. 

##Usage
TBD

##Configuration
TBD

##Development
This program is developed in C++. Right now, it's my toy hobby project, and I'm trying to get a version 1 done which
is able to backup files in the background and allows me to restore them at a later point. It will be a pure command
line tool so that I can focus on getting the bare configuration and the backend right. Next will be improved configuration
options, and then the GUI will be a focus. After that, I'll work on timestamp meta data. 

## Compiling on Linux
Install your favourite Linux distribution (I use Ubuntu). Install the usual developer tools, especially a C++ compiler.
Install CMake (sudo apt-get install cmake). Install libgit2 (sudo apt-get install libgit2-dev).

In order to compile backupnado, switch to the repository's root directory, and start ./linuxbuild.bash. This has CMake 
create a Makefile, then compiles everything, and then creates a DEB package from it.

## Compiling on Windows
TDB

