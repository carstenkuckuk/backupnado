mkdir xxx
cd xxx
cmake -G "Visual Studio 11 Win64" ..
cmake --build .
cpack -G NSIS64

