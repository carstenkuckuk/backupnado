// Project: backupnado
// File: helpers/stringhelpers.hpp
//
// Little utility functions that deal with strings and vectors of strings

#ifndef __BACKUPNADO_HELPERS_STRINGHELPERS_HPP__
#define __BACKUPNADO_HELPERS_STRINGHELPERS_HPP__

#include <string>
#include <vector>



std::string ConfigFileContentsFindFirstEntryByNameWithDefaultValue(
	const std::vector<std::string> &refrgLines, 
	std::string strName, 
	std::string strDefaultValue);

#endif
