// Project: backupnado
// File: helpers/stringhelpers.cpp
//
// Little utility functions that deal with strings and vectors of strings

#include "stringhelpers.hpp"


std::string ConfigFileContentsFindFirstEntryByNameWithDefaultValue(
	const std::vector<std::string> &refrgLines,
	std::string strName,
	std::string strDefaultValue)
{
	return strDefaultValue;
}

std::string AllowOnlyAToZ0To9(std::string strArg) // Removes all characters except for 'A' to 'Z' and '0' to '9'
{
	std::string strResult;
	size_t nSize = strArg.size();
	for (size_t i = 0; i < nSize; i++)
	{
		char ch = strArg[i];
		if (
			( ('A' <= ch) && (ch <= 'Z') ) ||
			( ('a' <= ch) && (ch <= 'z') ) ||
			( ('0' <= ch) && (ch <= '9') )
			)
		{
			strResult.push_back(ch);
		}
	}
	return strResult;
}
