set GIT2_ROOT="c:\program files\libgit2"
set GIT2_INCLUDEDIR="c:\program files\libgit2\include"
set GIT2_LIBRARYDIR="c:\program files\libgit2\lib"

set GIT2_LIBRARIES="c:\program files\libgit2\lib"
set GIT2_INCLUDE_DIR="c:\program files\libgit2\include"

set GIT2_LIBRARY="c:\program files\libgit2\lib"
set GIT2_INCLUDEPATH="c:\program files\libgit2\include"

mkdir xxx
cd xxx
cmake -G "Visual Studio 10 Win64" ..
REM cmake -G "Visual Studio 11 Win64" ..
cmake --build . --config Release
cpack -G NSIS64
cd ..

