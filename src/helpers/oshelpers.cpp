// Project: backupnado
// File: helpers/oshelpers.cpp
//
// Little utility functions that deal with operating-specific issues

#include "oshelpers.hpp"
#include "stringhelpers.hpp"

#ifdef __linux__
#include <unistd.h>
std::string OsGetComputerName()
{
	char buf[500] = { 0 };
	int nLen = 499;

	int nRes = gethostname(buf, nLen);

	std::string strRes = buf;
	return strRes;
}

std::string OsGetUserName()
{
	std::string strUserName = getenv("USERNAME");
	return strUserName;
}

std::string OsGetUserEMail()
{
	std::string strUserEMail = AllowOnlyAToZ0To9(OsGetUserName()) + "@" + OsGetComputerName() + ".local";
	return strUserEMail;
}


#else
#include <Windows.h>

std::string OsGetComputerName()
{
	char buf[500] = { 0 };
	DWORD nLen = 499;

	BOOL bRes = GetComputerNameA(buf, &nLen);

	std::string strRes = buf;
	return strRes;
}

std::string OsGetUserName()
{
	std::string strUserName = getenv("USERNAME");
	return strUserName;
}

std::string OsGetUserEMail()
{
	std::string strUserEMail = AllowOnlyAToZ0To9(OsGetUserName()) + "@" + OsGetComputerName() + ".local";
	return strUserEMail;
}

#endif

