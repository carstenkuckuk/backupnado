# backupnado
Backup tool for Windows and Linux based on libgit2

## Purpose
Backupnado is a configurable backup program that can backup folders from your computer to a remote location. For storage
it will use a git repository as a backend. Several computers can backup into one git repository. Internally, git de-duplicates
files which means that storage is only needed for the parts that change. File metadata like timestamps or access rights are
not preserved, so this tool should only be used in a private context where security is dealt with by means of physical access.
My personal use case is, that I use several computers, some Windows, some Linux machines, and they mainly contain the same
or similar files, and I want to be able to backup them on a NAS but not duplicate files too much. 

## Usage
TBD

## Configuration
TBD

## Development
This program is developed in C++. Right now, it's my toy hobby project, and I'm trying to get a version 1 done which
is able to backup files in the background and allows me to restore them at a later point. It will be a pure command
line tool so that I can focus on getting the bare configuration and the backend right. Next will be improved configuration
options, and then the GUI will be a focus. After that, I'll work on timestamp meta data. 

## Compiling on Linux
Install your favourite Linux distribution (I use Ubuntu). Install the usual developer tools, especially a C++ compiler and CMake. (sudo apt-get install git cmake build-essential libssl-dev).

Clone and compile libgit2 as follows:
```
git clone https://github.com/libgit2/libgit2.git
cd libgit2
mkdir xxx
cd xxx
cmake -G "Unix Makefiles" ..
cmake --build .
sudo cmake --build . --target install
```
In order to compile backupnado, switch to the repository's root directory, and start ./linuxbuild.bash. This has CMake 
create a Makefile, then compiles everything, and then creates a DEB package from it.

## Compiling on Windows
Install Visual Studio (I'm working with VS 2010). Install CMake. Install NSIS. Install Git. Install Python 3.7.0
(libgit2 needs it for building tests.) Clone and compile libgit2 as follows:
```
git clone https://github.com/libgit2/libgit2.git
cd libgit2
mkdir xxx
cd xxx
cmake -G "Visual Studio 15 2017 Win64" ..
cmake --build . --config Release
cmake --build . --target install (executed in an admin shell)
```
This copies the header files, the git.lib and the git.dll files to c:\program files\libgit2\...  folders. As I could not figure out
how to find these files using the proper CMake means, I have set these paths directly in my own CMakeLists.txt for Windows. 

Then cd into this project's root directory and execute winbuild.cmd. Before you do this, check that the cmake -G call in winbuild.cmd
uses the same Visual Studio version and bitness as the -G option you used for building libgit2

