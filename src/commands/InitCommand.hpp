// Project: backupnado
// File: commands/InitCommand.hpp
//
// Performs the Init command for the backupnado command line tool

#ifndef __BACKUPNADO_COMMANDS_INITCOMMAND_HPP__
#define __BACKUPNADO_COMMANDS_INITCOMMAND_HPP__

#include <string>

int InitCommand(std::string strNodeName, std::string strSourceDirectory, std::string strTargetDirectory); // 0=ok, other: failure

#endif

