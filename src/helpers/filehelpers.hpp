// Project: backupnado
// File: helpers/filehelpers.hpp
//
// Little utility functions that deal with files: Read file contents into vector of string, write vector of strings
// to file etc.

#ifndef __BACKUPNADO_HELPERS_FILEHELPERS_HPP__
#define __BACKUPNADO_HELPERS_FILEHELPERS_HPP__

#include <string>
#include <vector>

bool ReadLinesFromFileIntoVectorOfString(std::string strFilename, std::vector<std::string> &refrgFileContents); // true = successful, false=error 

bool WriteVectorOfStringToFile(std::string strFilename, std::vector<std::string> rgFileContents);

#endif
