// Project: backupnado
// File: helpers/oshelpers.cpp
//
// Little utility functions that deal with operating-specific issues

#include "oshelpers.hpp"

#include <Windows.h>

std::string OsGetComputerName()
{
	char buf[500] = { 0 };
	DWORD nLen = 499;

	BOOL bRes = GetComputerNameA(buf, &nLen);

	std::string strRes = buf;
	return strRes;
}
