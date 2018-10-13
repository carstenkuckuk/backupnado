// Project: backupnado
// File: backupnado.cpp
//
// Entry point for the backupnado command line tool

#include "commands/HelpCommand.hpp"
#include "commands/InitCommand.hpp"
#include "helpers/oshelpers.hpp"

#include <git2.h>
#include <git2/common.h>

#include <iostream>
#include <vector>
#include <string>

int backupnado(std::vector<std::string> rgArgs);

int main(int argc, char**argv)
{
	std::vector<std::string> rgArgs;

	for (size_t i = 0; i < argc; i++)
	{
		std::string strArg = argv[i];
		rgArgs.push_back(strArg);
	}
	
	int nReturncode = backupnado(rgArgs);
	
	return nReturncode;
}

int backupnado(std::vector<std::string> rgArgs)
{
	int nReturncode = 0;
	git_libgit2_init();

	std::string strCommand = "help";
	if (rgArgs.size() > 1)
	{
		strCommand = rgArgs[1];
	}

	if (strCommand == "help")
	{
		nReturncode = HelpCommand();
	}
	else
	if(strCommand == "init")
	{
		if (rgArgs.size() == 4)
		{
			std::string strComputername = OsGetComputerName();
			std::string strUserName = OsGetUserName();
			std::string strUserEMail = OsGetUserEMail();
			nReturncode = InitCommand(strComputername, rgArgs[2], rgArgs[3], strUserName, strUserEMail);
		}
		else
		{
			std::cout << "error: init command needs two parameters!";
			nReturncode = 1;
		}
	}
	else
	{
		std::cout << "Unknown command '" << strCommand << "'" << std::endl;
		nReturncode = HelpCommand();
	}

	git_libgit2_shutdown();

	return nReturncode;
}

