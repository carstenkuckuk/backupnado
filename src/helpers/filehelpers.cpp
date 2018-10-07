// Project: backupnado
// File: helpers/filehelpers.cpp
//
// Little utility functions that deal with files: Read file contents into vector of string, write vector of strings
// to file etc.

#include "filehelpers.hpp"

#include <iostream>
#include <fstream>

bool ReadLinesFromFileIntoVectorOfString(std::string strFilename, std::vector<std::string> &refrgFileContents) // true = successful, false=error 
{
	return false;
}

bool WriteVectorOfStringToFile(std::string strFilename, std::vector<std::string> rgFileContents)
{
	std::ofstream of;
	of.open(strFilename);
	size_t nLines = rgFileContents.size();
	for (size_t i = 0; i < nLines; i++)
	{
		std::string strLine = rgFileContents[i];
		of << strLine << std::endl;
	}
	of.close();
	return true;
}