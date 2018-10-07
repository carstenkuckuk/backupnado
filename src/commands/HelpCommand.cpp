// Project: backupnado
// File: commands/HelpCommand.cpp
//
// Performs the Help command for the backupnado command line tool

#include "HelpCommand.hpp"

// For version constands:
#include "../domain/version.hpp"
// For std::cout:
#include <iostream>

int HelpCommand() // 0=ok, other: failure
{
	std::cout
		<< pszBackupnadoBanner << std::endl
		<< std::endl
		<< "Usage:" << std::endl
		<< std::endl
		<< "backupnado help: Shows this help page" << std::endl
		<< std::endl
		<< "backupnado init <directory-to-be-backuped> <backuplocation>: Sets up configuration file and initializes the backup storage at the backup location" << std::endl
		;
	return 0;
}