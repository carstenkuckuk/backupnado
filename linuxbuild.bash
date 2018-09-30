mkdir xxx
cd xxx
cmake -G "Unix Makefiles" ..
make

sudo make PACKAGE
sudo cpack -G DEB

